//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4093
//#tag tsm problem travelling salesman bitonic tour caxeiro viajante
//#sol application of dp bitonic tour tsm

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
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 2000;
double dp[maxn][maxn];
int n;
pdd p[maxn];

double dist( int i, int j){
	return sqrt( (p[i].F - p[j].F) * (p[i].F - p[j].F) + (p[i].S - p[j].S) * (p[i].S - p[j].S));
}

double rec( int i, int j){
	if( i == 0 && j == 0) return 0;
	if( dp[i][j] < 1e10) return dp[i][j];
	if( i < j -1) return rec( i , j -1) + dist( j-1, j );
	double opt = 1e11;
	REP(k,0,j){
		opt = min( opt, rec(k,i) + dist(k,j));
	}
	return dp[i][j] = opt;
}

int main(){
	while( scanf("%d", &n) > 0){
		REP(i,0,n){
			double a,b;
			scanf("%lf%lf" , &a, &b);
			p[i] = mp( a, b);
			REP(j,0,n+1){
				dp[i][j] = 1e11;				
			}
		}
		printf("%.2lf\n", rec( n-1, n-1) );		
	}
	return 0;
}