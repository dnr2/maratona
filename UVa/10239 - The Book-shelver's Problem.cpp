//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1180
//#tag DP dynamic programming

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
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map
using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 1100;

ll dp[maxn];
ll sum[maxn];
ll mh[maxn][maxn];
ll in[maxn][2];
ll n, w;

ll rec( ll pos ){
	if( pos == n+1 ){
		return 0;
	}
	ll & ret = dp[pos];
	if( ret != -1 ) return ret;
	ret = 1e15;	
	REP(i,pos,n+1){
		if( sum[i] - sum[pos-1] > w ) break;
		ret = min( ret , mh[pos][i] + rec(i+1) );
	}	
	return ret;
}

int main(){
	
	while( cin >> n){
		ll a, b;
		scanf("%lld.%lld",&a,&b );
		w = a * 10000 + b;
		// DB( n _ w );
		if( n== 0 && w == 0) break;
		REP(i,0,n){
			REP(kk,0,2){
				ll a, b;
				scanf("%lld.%lld",&a,&b );
				in[i+1][kk] = a * 10000 + b;				
			}
		}
		FILL(sum,0);
		REP(i,1,n+1){
			sum[i] = sum[i-1] + in[i][1];
		}
		REP(i,1,n+1){
			ll m = in[i][0];
			mh[i][i] = m;
			REP(j,i+1,n+1){
				m = max(m, in[j][0]);
				mh[i][j] = m;
			}
		}
		FILL(dp,-1);
		ll ret = rec( 1 );			
		printf("%lld.%04lld\n", ret/10000, ret % 10000);
	}
	return 0;
}