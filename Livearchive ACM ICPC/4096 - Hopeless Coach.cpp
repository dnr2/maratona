//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2097
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

const int maxn = 200;
int n,p; int w,d,l;
double pw, pd, pl;
int inipt;

int maxmat = 17 * 2;

double dp[maxn][maxn];

double rec( int mat, int pt ){
	if( pt >= p + inipt ) return 1;
	if( mat >= maxmat || mat >= w + d + l + n ) return 0;
	if( dp[mat][pt] != -1) return dp[mat][pt];
	
	double ret = 0;
	ret += pw * rec( mat + 1, pt + 3);
	ret += pd * rec( mat + 1, pt + 1);
	ret += pl * rec( mat + 1, pt );
	return (dp[mat][pt] = ret );
}

int main(){
	
	while( cin >> n >> p){
		if( n == 0 && p == 0) break;
		cin >> w >> d >> l;
		double sum = w + d + l;
		pw = ((double)w) / sum;
		pd = ((double)d) / sum;
		pl = ((double)l) / sum;
		inipt = w * 3 + d;
		REP(i,0,maxn) REP(j,0,maxn) dp[i][j] = -1;
		printf("%.1lf\n" , 100 * rec( sum, inipt) );
	}
	return 0;
}