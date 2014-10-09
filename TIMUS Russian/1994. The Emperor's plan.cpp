//http://acm.timus.ru/problem.aspx?num=1994
//#tag DP dynamic programming, programacao dinamica
//#sol He wants the expected number of not spy senators still alive after the end of the confrontation
// Consider that at night before anyone loses his powers, k good senators will be killed. After that
// we have (n-2*k) good senators and k spy. The DP will try all the possible to-be-excluded i members,
// using combinatorics to see the probability that a certain number j of spies will be excluded.
// so the DP is: DP[n][k] = ARGMAX_i_ ( SUM _j = 0 to min(i+1,k+1)_ of ( C[k][j] * C[n-k][i-j] /  C[n][i]) 
// *  DP( max(n - i - (k-j), 0)  , k - j) )
// P.S: a double is enough precision to calculate the answer.

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

const int MAXN = 210;
const int MAXM = 25;
double dp[MAXN][MAXM];
bool mark[MAXN][MAXM];
double C[MAXN][MAXN];

double solve(int n, int k){
	if( n <= k ) return 0;
	if( k == 0) return n;
	if( mark[n][k] ) return dp[n][k];
	double ret = -1;
	REP(i,1,n){
		double aux = 0;
		REP(j,0,min(i+1,k+1)){
			aux += (C[k][j] * C[n-k][i-j] /  C[n][i]) *  solve( max(n - i - (k-j), 0)  , k - j) ;
		}
		ret = max( ret, aux);
	}
	mark[n][k] = true;
	return dp[n][k] = ret;
}

int main(){
	int n , k;	
	REP(i,0,MAXN){
		REP(j,0,i+1){
			if( i == 0 && j == 0){
				C[i][j] = 1;
			} else {
				C[i][j] = ((i-1 >= 0)? C[i-1][j] : 0)  + ((j-1 >= 0 && i-1 >= 0)? C[i-1][j-1] : 0);
			}
		}
	}
	while( cin >> n >> k){
		FILL( mark, false );
		printf("%.10lf\n", solve(n-k, k));
	}	
	return 0;
}