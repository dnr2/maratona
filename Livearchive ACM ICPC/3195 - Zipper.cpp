//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1196
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

const int maxn = 300;

int dp[maxn][maxn];
string x,y,z;

int can( int a, int b ){
	if( a + b == (int) z.size()) return 1;
	if( dp[a][b] != -1 ) return dp[a][b];	
	int ret = 0;
	if( a < (int)x.size() && x[a] == z[a+b] && can( a + 1, b )) ret = 1;
	if( b < (int)y.size() && y[b] == z[a+b] && can( a , b + 1)) ret = 1;
	return (dp[a][b] = ret);
}

int main(){
	IOFAST();
	int T; cin >> T;
	REP(cn,1,T+1){
	 	cin >> x >> y >> z;
		FILL(dp,-1);
		int ret = can(0,0);
		printf("Data set %d: %s\n", cn, ret?"yes":"no");
	}
	return 0;
}