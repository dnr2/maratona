//
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

const int maxn = 60;
double dp[maxn][maxn][maxn][2];
double dice = 1.0/6.0;

double rec( int a, int b, int c, int p){
	db( a _ b _ c _ p );
	if( dp[a][b][a][p] > -1) return dp[a][b][c][p];
	if( a == 0 && b == 0 && c == 0) {
		if( p == 1) return 1;
		if( p == 0) return 0;
	}
	int in[3] = {a,b,c};
	double ret[3];
	REP(i,0,3) ret[i] = 0;
	REP(j,0,3){
		REP(i,1,7){
			if( in[j] > 0) ret[j] += dice * rec( in[0], in[1] , in[2] , (p+1)%2);
		}
	}
	return dp[a][b][c][p] = max( ret[0], max( ret[1], ret[2]));
}

int main(){
	
	int T; cin >> T;
	while(T--){
		int a,b,c;
		cin >> a >> b >> c;
		REP(i,0,maxn) REP(j,0,maxn) REP(k,0,maxn) dp[i][j][k][0] = dp[i][j][k][1] = -1;
		printf("%.4lf\n", rec( a, b , c, 0));
	}
	
	return 0;
}