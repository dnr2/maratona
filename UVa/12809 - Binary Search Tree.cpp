//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4674
//#tag DP dynamic programming , programacao dinamica PD
//#sol

#include <bits/stdc++.h>

#define fr(i,m,n) for(int i = (m); i < (n); ++i)

#define st first
#define nd second

#define clr(a, b) memset(a, b, sizeof a)

#define sd(x) scanf("%d", &x);
#define spii(x) scanf("%d %d", &x.st, &x.nd)

#define dbg(x) cout << x << endl
#define db2(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, pdd> pdv;


const int MAXN = 110;
double pro[MAXN];
double dp[MAXN][MAXN];
double sum[MAXN][MAXN];


double solve( int a, int b ){
	if( dp[a][b] >= -1e-6) return dp[a][b];
	if( a == b ) return dp[a][b] = pro[a];
	if( b < a ) return dp[a][b] = 0;
	double ret = 1e20;
	fr(i,a,b+1) ret = min(ret, solve(a , i-1) + solve(i+1,b) + sum[a][b]) ; 
	return dp[a][b] = ret;
}

int main()
{
	
	int n;
	while( scanf("%d" , &n) > 0){
		fr(i,0,n) fr(j,0,n) dp[i][j] = -1;
		fr(i,0,n){
			scanf("%lf", pro + i );
		}		
		fr(i,0,n) fr(j,i,n) {
			if( j > i)  sum[i][j] = sum[i][j-1] + pro[j];
			else sum[i][i] = pro[i];
		}
		printf("%.6lf\n", solve(0, n-1));
	}
	
	return 0;
}