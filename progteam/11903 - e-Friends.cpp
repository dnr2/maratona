
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3054 
//#tag DP dynamic programming / PD programacao dinamica
//#tag bitmask 
//#sol To count every permutation is too expensive, instead we can create a DP where you create a bitmask telling who
//is in the queue so far, the last guy in the queue and the total sum of dissatisfaction. Notice that the maximum 
//dissatisfaction can be at most K * N, or actually N (considering that each dissatisfaction has a fixed cost). So
//you can divide each query by K to know how many friends were unsatisfied (don't divide by K when K is 0);


#pragma comment(linker, "/STACK:16777216")

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

const int MAXN = 3000;

ll dp[1<<13][13][13];
ll adj[15][15];
ll resp[15];
int N, maxval;

ll go(int mask, int prev, int val ){
	int pos = 0, aux = mask;
	while(aux > 0) pos += aux & 1, aux >>= 1;
	if( dp[mask][prev][val] != -1) return dp[mask][prev][val];
	
	if( pos == N ){	return val == maxval; }
	ll ret = 0;
	REP(i,0,N){		
		if( mask & (1<<i) || (val == maxval && adj[i][prev] ) ) continue;		
		ret += go( mask | (1 << i) , i , val + adj[i][prev] );		
	}
	return dp[mask][prev][val] = ret;
}

int main(){
	
	int T,K,Q; cin >> T;
	REP(cn,1,T+1){		
		cin >> N >> K >> Q;
		printf("Case %d:\n", cn);
		FILL(adj,0);
		REP(i,0,N){
			int cont = 0; scanf("%d", &cont);
			REP(j,0,cont){
				int a; scanf("%d", &a ); a--;
				adj[i][a] = 1;	
			}
		}		
		REP(i,0,N){
			FILL(dp,-1);
			maxval = i;
			resp[i] = go( 0, 14, 0);
			if( i > 0 ) resp[i] += resp[i-1];
		}
		REP(i,0,Q){
			int q; scanf("%d", &q);
			if( K > 0 )q /= K;
			else q = INF;
			q = min( N-1, q );
			printf("%lld\n", resp[q]);
		}
	}
	return 0;
}