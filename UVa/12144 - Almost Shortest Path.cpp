//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3296
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
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int MAXN = 510;
const int INF = 0x3f3f3f3f;
vector<pii> adj[2][MAXN];
int dist[2][MAXN];
int N, M, S , D;

void djkstra( int turn, int s ){
	REP(i,0,MAXN) dist[turn][i] = INF;
	dist[turn][s] = 0;
	priority_queue<pii> heap;
	heap.push( mp(0,s) );
	while(!heap.empty()){
		pii cur = heap.top(); heap.pop();
		if( -cur.F > dist[turn][cur.S] ) continue;
		for( vector<pii>::iterator v = adj[turn][cur.S].begin(); v != adj[turn][cur.S].end(); v++){
			// db( cur.F _ cur.S _ dist[turn][cur.S] _ v->F _ v->S);
			if( v->S < 0) continue;
			if( dist[turn][v->F] > dist[turn][cur.S] + v->S){
				dist[turn][v->F] = dist[turn][cur.S] + v->S;
				heap.push( mp( -dist[turn][v->F], v->F) );
			}
		}
	}
}

int main(){
	while(scanf("%d%d", &N,&M) > 0 && (N||M)){
		scanf("%d%d", &S,&D);
		REP(i,0,MAXN) { adj[0][i].clear(); adj[1][i].clear(); }
		REP(i,0,M){
			int a, b , c;
			scanf("%d%d%d", &a,&b,&c);
			adj[0][a].pb( mp ( b, c));
			adj[1][b].pb( mp ( a, c));
		}
		djkstra(0, S);
		djkstra(1, D);
		REP(i,0,N){
			for( vector<pii>::iterator j  = adj[0][i].begin(); j != adj[0][i].end(); ++j){
				if( dist[0][i] + j->S + dist[1][j->F] == dist[0][D]){
					j->S = -(j->S);
				}
			}
		}
		djkstra(0, S);
		printf("%d\n", (dist[0][D]==INF)? -1 : dist[0][D]);
	}
	return 0;
}