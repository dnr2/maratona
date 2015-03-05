//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3686
//#tag graph
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
#include <cassert>

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

const int MAXN = 30100;

int in[MAXN][3];

struct st{
	int v;
	double d;
	int p;
	st( int v = 0, double d = 0, int p = 0) : v(v), d(d), p(p) {}
	bool operator < ( const st & in) const {
		return d > in.d;
	}
};

vector<st> adj[MAXN];
double dp[2][MAXN];


int main(){
	
	int n, m, s, t, dif;
	while( cin >> n >> m){
		if(!(n||m)) break;
		REP(i,0,n){
			REP(j,0,3){
				scanf("%d", in[i] + j);
			}
		}
		REP(i,0,n+1) adj[i].clear();
		REP(i,0,m){
			int u, v; 
			scanf("%d%d", &u, &v); u--, v--;
			double run = sqrt( pow( in[u][0] - in[v][0], 2.0) +  pow( in[u][1] - in[v][1], 2.0) );			
			double dist = sqrt( pow( in[u][0] - in[v][0], 2.0) +  pow( in[u][1] - in[v][1], 2.0) + pow( in[u][2] - in[v][2], 2.0) );
			int pu = (( in[u][2] < in[v][2] )? (int) ( 100.0 * abs(in[u][2] - in[v][2]) / run  ): 0);
			int pv = (( in[v][2] < in[u][2] )? (int) ( 100.0 * abs(in[v][2] - in[u][2]) / run  ): 0);			
			assert( dist < 1e20);
			adj[u].PB( st( v, dist , pu ) );
			adj[v].PB( st( u, dist , pv ) );
		}
		scanf("%d%d%d", &s, &t, &dif);
		s--, t--;
		priority_queue<st> heap;
		REP(i,0,2) REP(j,0,n+1) dp[i][j] = 1e20;
		heap.push( st( s, 0, 0) );
		dp[0][s] = 0;
		double resp = -1;
		while( !heap.empty()){
			st cur = heap.top(); heap.pop();			
			if( cur.v == t && cur.p == 1) {
				resp = cur.d; break;
			}
			REP(i,0,(int)adj[cur.v].size()){
				if( adj[cur.v][i].p > dif) continue;
				st edge = adj[cur.v][i];
				st next( edge.v , edge.d + cur.d, max( cur.p , (int)( edge.p == dif)));
				if( dp[next.p][next.v] > next.d ){
					dp[next.p][next.v] = next.d;
					heap.push( next );
				}
			}
			
		}		
		if( resp < 0){
			puts("None");
		} else {
			printf("%.3lf\n", resp );
		}
	}
	
	return 0;
}