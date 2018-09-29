#include <bits/stdc++.h>
using namespace std;
#if 0
#define LOG_OP(a, b, c, d, e) (cerr << a << " " << b << " " << c << " " << d << " " << e << endl)
#define LOG(a) (cerr << a << endl)
#else
#define LOG_OP(a, b, c, d, e) (cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << " " << e << endl)
#define LOG(a)
#endif

struct segtree_min {
    int N;
    vector<int> dat, sum;
    segtree_min(int n) {
        N = 1;
        while(N < n) N <<= 1;
        dat.assign(2*N-1,0);
        sum.assign(2*N-1,0);
    }
    void add(int a, int b, int x) { add(a,b,x,0,0,N); }
    int add(int a, int b, int x, int k, int l, int r) {
        if(b <= l or r <= a) return dat[k];
        if(a <= l and r <= b) {
            sum[k] += x;
            return dat[k] += x;
        }
        int m = (l+r)/2;
        return dat[k] = min(add(a,b,x,2*k+1,l,m),add(a,b,x,2*k+2,m,r))+sum[k];
    }
    int minimum(int a, int b) { return minimum(a,b,0,0,N); }
    int minimum(int a, int b, int k, int l, int r) {
        if(b <= l or r <= a) return 2e9;
        if(a <= l and r <= b) return dat[k];
        int m = (l+r)/2;
        return min(minimum(a,b,2*k+1,l,m),minimum(a,b,2*k+2,m,r))+sum[k];
    }
};
struct segtree_max {
    int N;
    vector<int> dat, sum;
    segtree_max(int n) {
        N = 1;
        while(N < n) N <<= 1;
        dat.assign(2*N-1,0);
        sum.assign(2*N-1,0);
    }
    void add(int a, int b, int x) { add(a,b,x,0,0,N); }
    int add(int a, int b, int x, int k, int l, int r) {
        if(b <= l or r <= a) return dat[k];
        if(a <= l and r <= b) {
            sum[k] += x;
            return dat[k] += x;
        }
        int m = (l+r)/2;
        return dat[k] = max(add(a,b,x,2*k+1,l,m),add(a,b,x,2*k+2,m,r))+sum[k];
    }
    int maximum(int a, int b) { return maximum(a,b,0,0,N); }
    int maximum(int a, int b, int k, int l, int r) {
        if(b <= l or r <= a) return -2e9;
        if(a <= l and r <= b) return dat[k];
        int m = (l+r)/2;
        return max(maximum(a,b,2*k+1,l,m),maximum(a,b,2*k+2,m,r))+sum[k];
    }
};
/*struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
 
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
 
    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};*/

template<class T> class bit {
public:
    vector<T> dat;
    int N;
    bit(){}
    bit(int N) : N(N) { dat.assign(N,0); }
    // sum [0,i)
    T sum(int i){
        int ret = 0;
        for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
        return ret;
    }
    // sum [i,j)
    T sum(int i, int j) { return sum(j) - sum(i); }
    // add x to i
    void add(int i, T x) { for(; i < N; i|=i+1) dat[i] += x; }
};

class Segtrees {
public:
  bit<int> seg_sum;
  segtree_max seg_max;
  segtree_min seg_min;
  Segtrees(int n): seg_sum(n), seg_max(n), seg_min(n) {}
  void add(int l, int r, int a) {
    for (int i = l; i <= r; i++) seg_sum.add(i, a);
    seg_max.add(l, r + 1, a);
    seg_min.add(l, r + 1, a);
  }
  int getmax(int l, int r) {
    return seg_max.maximum(l, r + 1);
  }
  int getmin(int l, int r) {
    return seg_min.minimum(l, r + 1);
  }
  int getsum(int l, int r) {
    return seg_sum.sum(l, r + 1);
  }
  int sum_arange(int l, int r) {
    return (l + r + 2) * (r - l + 1) / 2;
  }
};

int N, K;
void op(int i, int j, int k, int l, int v, Segtrees& A) {
  LOG_OP(i, j, k, l, v);
  assert(i <= j && k <= l);
  assert(0 <= v && v <= N - 1);
  assert(j < k || l < i);
  assert(j - i == l - k);
  A.add(i, j, -v);
  A.add(k, l, v);
}
void proc1(int& maxdiff1, int& maxid1, Segtrees& A, int width, int start = 0) {
  for (int i = start; i < N - width; i+=5) {
    int diff = A.getsum(i, i + width) - A.sum_arange(i, i + width);
    int mn = A.getmin(i, i + width);
    if (diff <= 0 || mn <= 1) continue;
    diff = min(diff / (width + 1), mn - 1); 
    if (maxdiff1 < diff) {
      maxdiff1 = diff;
      maxid1 = i;
    }
  }
}

void proc2(int& maxdiff2, int& maxid2, Segtrees& A, int width, int start) {
  for (int i = start; i < N - width; i+=5) {
    int diff = A.getsum(i, i + width) - A.sum_arange(i, i + width);
    int mx = A.getmax(i, i + width);
    if (diff >= 0 || mx >= N) continue;
    diff = min(abs(diff) / (width + 1), N - mx);
    if (maxdiff2 < diff) {
      maxdiff2 = diff;
      maxid2 = i;
    }
  }
}

int main(void) {
  cin >> N >> K;
  Segtrees A(N);
  for (int i = 0; i < N; i++) {
    int tmp;cin >> tmp;
    A.add(i, i, tmp);
  }

  int width = 30 - 1;
  int samelimit = 33;
  int prevt = -1, samecount = 0;
  for (int t = 0; t < K; t++) {
    int maxdiff1 = 0, maxid1 = -1;
    int maxdiff2 = 0, maxid2 = -1;
    if (t == prevt) {
      samecount++;
      if (samecount > samelimit) {
        width--;
        samecount = 0;
      }
    }
    if (width == 0) {
      for (; t < K; t++) {
        LOG_OP(1, 2, 3, 4, 0);
      }
      break;
    }
    prevt = t;
    if (rand() % 2 == 0) {
      proc1(maxdiff1, maxid1, A, width, 0);
      if (!(maxid1 != -1)) {t--; continue;}
      proc2(maxdiff2, maxid2, A, width, maxid1 + width + 1);
      if (!(maxid2 != -1)) {t--; continue;}
    } else {
      proc2(maxdiff2, maxid2, A, width, 0);
      if (!(maxid2 != -1)) {t--; continue;}
      proc1(maxdiff1, maxid1, A, width, maxid2 + width + 1);
      if (!(maxid1 != -1)) {t--; continue;}
    }

    assert(maxdiff1 > 0 && maxdiff2 > 0);
    int v = min(maxdiff1, maxdiff2);
    op(maxid1, maxid1+width, maxid2, maxid2+width, v, A);
  }


  return 0;
}
