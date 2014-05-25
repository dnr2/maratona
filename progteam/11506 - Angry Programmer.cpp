//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2501
//#tag dinic
//#tag maxflow with  flow on the nodes
//#sol transform each node to two other nodes n_i1 and n_i2. make the graph direct by connecting inner edges to n_i1 and the outer edges in_i2.

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
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


const int maxN = 5005;
const int maxE = 70000;
const int inf = 1000000005;

int nnode, nedge, src, snk;

int Q[ maxN ], pro[ maxN ], fin[ maxN ], dist[ maxN ];
int flow[ maxE ], cap[ maxE ], to[ maxE ], next[ maxE ];

void init( int _nnode, int _src, int _snk ) {
	nnode = _nnode, nedge = 0, src = _src, snk = _snk;
	REP(i,1,nnode) fin[i] = -1;
}

void add( int a, int b, int c1, int c2 ) {
	to[nedge]=b, cap[nedge]=c1, flow[nedge]=0, next[nedge]=fin[a], fin[a]=nedge++;
	to[nedge]=a, cap[nedge]=c2, flow[nedge]=0, next[nedge]=fin[b], fin[b]=nedge++;
}
bool bfs() {	
	memset(dist, -1, sizeof(dist));
	dist[src] = 0;
	int st = 0, en = 0;
	Q[en++] = src;
	while( st < en ) {		
		int u = Q[ st++ ];
		for(int e = fin[u]; e >= 0; e = next[e] ) {			
			int v = to[e];			
			if( flow[e] < cap[e] && dist[v] == -1 ) {
				dist[v] = dist[u] + 1;
				Q[en++] = v;
			}
		}
	}
	return dist[snk] != -1;
}

int dfs(int u, int fl) {
	if( u == snk ) return fl;
		for( int& e = pro[u]; e >= 0; e = next[e] ) {
			int v = to[e];
			if( flow[e] < cap[e] && dist[v] == dist[u]+1 ) {
			int x = dfs( v, min( cap[e] - flow[e] , fl ) );
			if( x > 0 ) {
				flow[ e ] += x, flow[ e^1 ] -= x;
				return x;
			}
		}
	}
	return 0;
}

ll dinic() {
	ll ret = 0;	
	while( bfs() ) {		
		REP(i,1,nnode) pro[i] = fin[i];
		while( 1 ) {						
			int delta = dfs( src, inf );
			if( !delta ) break;
			ret += delta;
		}
	}
	return ret;
}

int M, W;

int mark[60];
vector<pii> adj[60];

int dfs( int x){	
	if( x == M) return 1;
	if( mark[x] ) return 0;	
	mark[x] = 1;
	REP(i,0,adj[x].size()){
		if( dfs( adj[x][i].F) == 1) return 1;
	}
	return 0;
}

int main(){	
	while(scanf("%d%d", &M, &W) > 0 && (M||W)){
		init( 2 * M + W , 1, M);
		REP(i,0,60) adj[i].clear();
		memset( mark, 0, sizeof(mark));		
		REP(i,2,M){
			int a, b; 
			scanf("%d%d", &a, &b);		
			add( a, a + M, b, 0);			
		}
		REP(i,0,W){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[a].pb( pii(b,c));
			adj[b].pb( pii(a,c));
			int x = min(a,b), y = max( a, b);
			if( x == 1) add( x, y , c, 0);
			else {
				add( a+M, b , c, 0);
				add( b+M, a , c, 0);
			}
		}
		
		if( dfs(1) == 0) puts("0");
		else {
			cout << dinic() << endl;
		}		
	}
	return 0;
}