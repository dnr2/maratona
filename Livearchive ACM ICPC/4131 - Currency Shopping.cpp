//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=342&page=show_problem&problem=2132
//#tag graph
//#tag bellman ford
//#sol solve this problems as a maximum distance in graph

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
#define EPS 1e-7
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 110;
double in[MAXN][MAXN];
double dist[MAXN];

int main(){
	
	int cn; cin >> cn;
	
	while( cn-- ){
		int n; cin >> n;
		map<string,int> mapa;
		REP(i,0,n) {
			string a; cin >> a;
			mapa[a] = i;
		}
		REP(i,0,n) REP(j,0,n) scanf("%lf", &in[i][j]);
		string aa,bb; cin >> aa >> bb;
		int b = mapa[aa], e = mapa[bb];
		REP(i,0,n) dist[i] = 0;
		dist[b] = 1;
		REP(k,0,n) REP(i,0,n) REP(j,0,n){
			dist[j] = max( dist[j] , dist[i] * in[i][j] );
		}		
		bool ok = true;
		REP(i,0,n) REP(j,0,n){	
			if( dist[j] + EPS < dist[i] * in[i][j] ) ok = false;
		}
		if( ok) {
			printf("%.4lf\n", dist[e] );
		} else {
			puts("Break the bank!");
		}
	}	
	return 0;
}