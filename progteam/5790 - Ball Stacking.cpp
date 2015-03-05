//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3801
//#tag
//#sol

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

const int MAXN = 2000;

ll in[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll n; 

ll go(ll y, ll x){
	if( y >= n ) return 0;	
	if( dp[y][x] >= 0 ) return dp[y][x];	
	return dp[y][x] = max( max( in[y][x], 0LL) , in[y][x] + go( y+1, x) + go(y+1,x+1) - go(y+2,x+1) );	
}

int main(){
	IOFAST();
	while( cin >> n ){
		if( n == 0) break;
		REP(i,0,n) {
			REP(j,0,i+1){
				cin >> in[i][j] ;				
			}
		}
		FILL(dp,-1LL);
		cout << go( 0, 0 ) << endl;		
	}
	return 0;
}