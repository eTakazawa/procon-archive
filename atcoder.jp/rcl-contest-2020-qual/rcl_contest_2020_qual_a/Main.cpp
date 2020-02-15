#include <bits/stdc++.h>
using namespace std;

// 1000, 8, 6, 8
int N, W, K, V;
const int MAX_H = 250;

void putMono(int w, int c, int v, vector<vector<int>>& colors, vector<vector<int>>& values, vector<int>& heights) {
  int h = heights[w];
  heights[w]++;
  colors[h][w] = c;
  values[h][w] = v;
}

int getscore(const vector<vector<int>>& colors, const vector<vector<int>>& values) {
  int score = 0;
  for (int h = 0; h < MAX_H; h++) {
    vector<int> color_hist(K);
    vector<int> value_hist(K);
    bool ok = true;
    for (int w = 0; w < W; w++) {
      if (colors[h][w] == -1) {
        ok = false;
        break;
      }
      color_hist[colors[h][w]]++;
      value_hist[colors[h][w]] += values[h][w];
    }
    if (ok) {
      int max_color_id = max_element(color_hist.begin(), color_hist.end()) - color_hist.begin();
      // cerr << h + 1 << " : "<< max_color_id << " " << value_hist[max_color_id] << endl;
      score += *max_element(value_hist.begin(), value_hist.end());
    }
  }
  return score;
}

int solve(vector<int>& c, vector<int>& v, vector<int>& ret, const vector<int>& color_trans) {
  vector<int> heights(W); // 1000 / 8 = 125
  vector<vector<int>> colors(MAX_H, vector<int>(W, -1));
  vector<vector<int>> values(MAX_H, vector<int>(W));
  ret.resize(N);

  // 出来るだけ下から(mod K)段目に同じ色が来るように置く
  for (int i = 0; i < N; i++) {
    int color = c[i];
    int value = v[i];

    bool isput = false;
    vector<pair<int,int>> oks;
    for (int w = 0; w < W; w++) {
      if (!isput && heights[w] % K == color_trans[color]) { // (color + offset) % Kを色変換にすれば良さそう
        oks.emplace_back(heights[w], w);
        isput = true;
      }
    }
    auto it_min = min_element(heights.begin(), heights.end());
    auto it_max = max_element(heights.begin(), heights.end());
    // cerr << *it_min << " " << *it_max << endl;
    int min_height = *it_min;
    int min_height_col = it_min - heights.begin();
    int max_height = *it_max;
    int max_height_col = it_max - heights.begin();

    // おけるときは一番低いところに置く
    if (isput) {
      // 差が大きすぎる場合　かつ valueが小さければ埋める
      if (abs(max_height - min_height) > 28 && value < 3) {
        putMono(min_height_col, color, value, colors, values, heights);
        ret[i] = min_height_col;
      }
      else {
        int h, min_col;
        tie(h, min_col) = *min_element(oks.begin(), oks.end());

        // 高さ制限
        if (h >= 124) {
          putMono(min_height_col, color, value, colors, values, heights);
          ret[i] = min_height_col;
        }
        else {
          putMono(min_col, color, value, colors, values, heights);
          ret[i] = min_col;
        }
      }
    }
    else {
      // 差がおおきすぎるときはなくなるように
      if (abs(max_height - min_height) > 28) {
        putMono(min_height_col, color, value, colors, values, heights);
        ret[i] = min_height_col;
      }
      // まだ置けていないとき，一番高いところの隣に置く
      else {
        int col = (max_height_col + 1) % W;
        if (max_height_col == W - 1) col = W - 2;

        // int selected = rand() % W;
        // while (heights[selected] == max_height) {
        //   selected = rand() % W;
        // }
        // col = selected;

        // 高さ制限
        if (heights[col] >= 124) {
          putMono(min_height_col, color, value, colors, values, heights);
          ret[i] = min_height_col;
        }
        else {
          putMono(col, color, value, colors, values, heights);
          ret[i] = col;
        }
      }
    }
  }

  // for (int i = 0; i < N; i++) {
  //   cout << ret[i] << endl;
  // }

  return getscore(colors, values);
}

int main(void) {
  cin >> N >> W >> K >> V;
  vector<int> c(N), v(N);
  for (int i = 0; i < N; i++) {
    cin >> c[i] >> v[i];
  }
  
  vector<int> max_ret, ret;
  int max_score = -1;
  vector<int> color_trans(K);
  for (int i = 0; i < K; i++) color_trans[i] = i;

  do {
    int score = solve(c, v, ret, color_trans);
    if (max_score < score) {
      max_score = score;
      max_ret = ret;
    }
  } while(next_permutation(color_trans.begin(), color_trans.end()));

  for (int i = 0; i < N; i++) {
    cout << max_ret[i] << endl;
  }

  return 0;
}