//http://www.spoj.com/problems/TAP2014J/
//#tag DP dynamic programming
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
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

#define MAXN 200000
int in[MAXN];
int dp[MAXN];
int T;
int rec(int pos){
	if( pos == T) return 1;
	if( pos > T) return 2;
	if( dp[pos] > 0) return dp[pos];
	return dp[pos] = rec( pos + in[pos] + 1);
}

int main(){
	vector<int> resp;
	while( cin >> T){
		// DB( "" );
		FILL( dp, 0);
		REP(i,0,T){
			scanf("%d", in+i);
		}
		resp.clear();
		REP(i,1,T+1){
		
			if( rec( i ) == 1) resp.PB( i );
			// DB( i _ rec(i) );
		}
		REP(i,0,(int) resp.size()){
			printf("%d\n", resp[i]); 
		}
	}
	return 0;
}