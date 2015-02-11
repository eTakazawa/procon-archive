#include <bits/stdc++.h>
#define INF INT_MAX / 2
#define MOD 1000000007

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int>> PIPII;
typedef long long ll;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first1 ,
  BidirectionalIterator last1 ,
  BidirectionalIterator first2 ,
  BidirectionalIterator last2 )
{
  if (( first1 == last1 ) || ( first2 == last2 )) {
    return false ;
  }
  BidirectionalIterator m1 = last1 ;
  BidirectionalIterator m2 = last2 ; --m2;
  while (--m1 != first1 && !(* m1 < *m2 )){
  }
  bool result = (m1 == first1 ) && !(* first1 < *m2 );
  if (! result ) {
    // ①
    while ( first2 != m2 && !(* m1 < * first2 )) {
      ++ first2 ;
    }
    first1 = m1;
    std :: iter_swap (first1 , first2 );
    ++ first1 ;
    ++ first2 ;
  }
  if (( first1 != last1 ) && ( first2 != last2 )) {
    // ②
    m1 = last1 ; m2 = first2 ;
    while (( m1 != first1 ) && (m2 != last2 )) {
      std :: iter_swap (--m1 , m2 );
      ++ m2;
    }
    // ③
    std :: reverse (first1 , m1 );
    std :: reverse (first1 , last1 );
    std :: reverse (m2 , last2 );
    std :: reverse (first2 , last2 );
  }
  return ! result ;
}
 
template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first ,
  BidirectionalIterator middle ,
  BidirectionalIterator last )
{
  return next_combination (first , middle , middle , last );
}


int main(void){
	int n,m;
	cin >> n >> m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<vector<int>> I(m);
	vector<int> b(m);
	vector<int> c(m);
	for(int i=0;i<m;i++){
		cin >> b[i] >> c[i];
		for(int j=0;j<c[i];j++){
			int t;cin >> t;
			t--;
			I[i].push_back(t);
		}
	}

	vector<int> v(n);
	int ret = 0;
	for(int i=0;i<n;i++)v[i] = i;
	do{
		int used[16] = {0};
		int p = 0;
		for(int i=0;i<16;i++)used[i] = 0;

		for(int i=0;i<9;i++){
			used[v[i]] = 1;
			p += a[v[i]];
		}
		for(int i=0;i<m;i++){
			int cnt = 0;
			for(int j=0;j<c[i];j++){
				if( used[ I[i][j] ] == 1)cnt++;
			}
			if(cnt >= 3){
				p += b[i];
			}
		}
		ret = max(ret,p);
	}while(next_combination(v.begin(),v.begin()+9,v.end()));

	cout << ret << endl;
	return 0;
}