//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=342&page=show_problem&problem=439
//#tag binary search / busca binaria
//#tag bellman ford 
//#tag graph / grafos
//#sol Binary search the minimum distance the volunteer army member has to be able to jump in order to get to the 
//last disc. given this value, calculate the number of volunteer who can complete the task, if it is the minority
//then the answer is "valid" otherwise "NOT valid"


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

const int MAXN = 100;
int in[30101];
PDD pts[MAXN];
int mark[MAXN];
double dist[MAXN][MAXN];

int main(){
	IOFAST();
	int n , m ;
	while( cin >> n >> m){
		if( n == -1 && m == -1) break;
		REP(i,0,n) cin >> in[i];
		REP(i,0,m){
			double a, b; cin >> a >> b;
			pts[i] = MP( a, b);			
		}
		REP(i,0,m) REP(j,0,m) dist[i][j] = sqrt( pow( pts[i].FT - pts[j].FT , 2.0) + pow( pts[i].SD - pts[j].SD , 2.0) );
		double lo = 0, hi = 1000000, mid = 0;
		while( fabs( hi - lo ) > EPS){			
			mid = (lo+hi)/2;
			FILL(mark,0);
			mark[0] = 1;					
			REP(i,0,m) REP(j,0,m) REP(k,0,m){
				if( mark[j] && dist[j][k] <= mid ) mark[k] = 1;
			}
			if( mark[1] == 1) hi = mid;
			else lo = mid;
		}
		// DB( mid );
		sort( in, in + n);
		int v = 0;
		while(v < n && in[v] + EPS < mid ) v++;
		if( v > n/2) puts("valid");
		else puts("NOT valid");
		
	}
	return 0;
}	