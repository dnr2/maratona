//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4202
//#tag DP dynamic programming 
//#tag PD programacao dinamica
//#sol notice that you should put the areas with least probability in the last zones. So use a DP 
// where the states are: ni = number of areas left, and wi = number of zones that you still have to
// create. for each state test if you can put i areas in the wi zone.

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
#include <cassert>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(ll (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF ((1LL)<<50)
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 110;

ll dp[maxn][maxn];
ll pi[maxn];
ll in[maxn];
ll n, w;

ll rec( ll ni, ll wi ){	
	if( wi == 1 && ni >= 1 ){
		return n * pi[ni];
	}
	if( ni == 0) return INF;
	if( dp[ni][wi] != -1) return dp[ni][wi];
	ll ret = INF;
	REP(i,1,ni+1){
		ll nval = ( (i + (n-ni) ) * (pi[ni] - pi[ni-i]) ) + rec( ni - i , wi - 1);
		ret= min( ret, nval);
	}
	return dp[ni][wi] = ret;
}


int main(){	
	int T; cin >> T;	
	while( T--){
		scanf("%lld%lld", &n, &w);		
		ll sum = 0;
		REP(i,0,n){			
			scanf("%lld", in+i);
			sum += in[i];
		}
		sort( in, in+n);
		FILL( dp,-1 );
		pi[0] = 0;
		REP(i,1,n+1){	
			pi[i] = pi[i-1] + in[i-1];
		}
		ll ret = rec( n, w );
		double resp = ((double) ret ) / ( (double) sum );
		printf("%.4lf\n", resp);
	}	
	return 0;
}