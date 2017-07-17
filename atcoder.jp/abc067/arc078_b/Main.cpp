#include <bits/stdc++.h>
using namespace std;

vector<int> getPath(vector<vector<int>>& es){
  int n = es.size();
  int s = 0,t = n-1;
  
  queue<int> que;
  vector<int> prev(n,-1);
  prev[s] = 1;
  que.push(s);
  while(!que.empty()){
    int now = que.front();que.pop();
    for(int i=0;i<es[now].size();i++){
      int nxt = es[now][i];
      if(prev[nxt] != -1)continue;
      prev[nxt] = now;
      que.push(nxt);
    }
  }
  vector<int> path;
  path.push_back(t);
  int now = t;
  while(now != s) {
    now = prev[now];
    path.push_back(now);
  }
  reverse(path.begin(),path.end());
  return path;
}

int main(void) {
  int N;
  cin >> N;
  vector<vector<int>> es(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin >> a >> b;
    a--;b--;
    es[a].push_back(b);
    es[b].push_back(a);
  }

  // 相手の方に近づく方向に塗るだけ
  vector<int> color(N);
  color[0] = 1;
  color[N-1] = -1;

  vector<int> path = getPath(es);
  for(int t=0;t<path.size();t++){
    if(t%2==0)
      color[path[t/2]] = 1;
    else
      color[path[path.size()-1-t/2]] = -1;
  }

  int cc = 0;
  if(path.size() % 2 == 0) cc = 1;
  else cc = -1;

  vector<int> cnt(2);
  for(int c=-1;c<=1;c+=2){
    queue<int> que;
    vector<int> used(N);
    int s;
    if(c==-1) s = N-1;
    else s = 0;
    
    used[s] = 1;
    que.push(s);
    while(!que.empty()){
      int now = que.front();que.pop();
      if(color[now] )
      for(int i=0;i<es[now].size();i++){
        int nxt = es[now][i];
        if(used[nxt] != 0)continue;
        if(color[nxt] == 0) {
          color[nxt] = c;
          
          if(c==-1) cnt[1]++;
          else cnt[0]++;
          que.push(nxt);
        }else if(color[nxt] == c){
          used[nxt] = 1;
          que.push(nxt);
        }
      }
    }
  }
  cerr << cc << endl;
  cerr << cnt[0] << endl;
  cerr << cnt[1] << endl;

  if(cc == 1){
    if(cnt[0] > cnt[1])cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
  } else {
    if(cnt[1] > cnt[0])cout << "Snuke" << endl;
    else cout << "Fennec" << endl;
  }

  // cerr << 'a';
  // for(int i=0;i<path.size();i++){
  //   cerr << color[path[i]] << endl;
  // }

  return 0;
}