//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3059
//#tag DP / dynamic programming / PD
//#sol sort the ads by its ending point, now for each ad you can either not use it, or add it and use the solution
//found so far for the ads with end position less than its begin point.


#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <sstream>
#include <climits>
#include <set>
// #include <unordered_map>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) if(0) cerr << #x << " = " << x << endl;
#define _ << ", " <<
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map
using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream 
os(""); os<<a;return os.str(); }

const int MAXN = 40000, MAXM = 300000;

struct st{
	int b, e, c;
	st( int b =0, int e= 0, int c = 0 ) : b(b), e(e) , c(c) {}
	const bool operator < ( const st & in ) const {
		if( e == in.e ) return b > in.b;
		return e < in.e;
	}
};

st vec[MAXN];

int dp[MAXN];

int main(){
	int K; cin >> K; int cn = 1;
	while( K--){
		cout << "Case " << (cn++) << ": ";
		int n; cin >> n;
		REP(i,0,n){
			int a,b,c;
			scanf("%d%d%d", &a , &b, &c);
			vec[i] = st( a , a + b - 1, c );
		}
		sort( vec, vec+ n);
	
		REP(i,0,n){			
			int lo = -1, hi = i, mid;
			while(lo + 1 < hi){
				mid = (lo+hi)/2;
				if( vec[mid].e < vec[i].b){
					lo = mid;
				} else {
					hi = mid;
				}
			}
			if( i > 0) dp[i] = max( dp[i-1] , vec[i].c + dp[lo] );
			else dp[i] = vec[i].c;
		}
		cout << dp[n-1] << endl;
	}
	return 0;
}