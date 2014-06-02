//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3198
//#tag dijkstra shortest path 
//#tag binary search
//#sol binary search the answer, test if the answer exists by using a modified dijkstra that also saves if you
//went through a road with cost at least mid (form the BS)

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
#define FILL(x,y) memset(x,y,sizeof(x))
#define EPS 1e-9
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct st{
	int node, cost, used;
	st( int node=0,int cost=0, int used=0) : node(node), cost(cost), used(used) {}
	const bool operator < ( const st & in ) const {
		return cost > in.cost;
	}
};

const int MAXN = 10010;
const int INF = 100000000;
int N, M, s, e, maxp;
vector<pii> adj[MAXN];
int dist[2][MAXN];

bool djk(int mid){
	REP(i,0,MAXN) dist[0][i] = dist[1][i] = INF;
	priority_queue<st> heap;
	heap.push( st( s, 0, 0));
	dist[0][s] = 0;
	while(!heap.empty()){
		st cur = heap.top(); heap.pop();
		// db( cur.node _ cur.cost _ cur.used );
		if( cur.node == e && cur.used){ return true; }
		FOREACH(i,adj[cur.node]){
			st next = st( i->F, cur.cost + i->S, cur.used);
			if( next.cost > maxp) continue; 
			if( dist[0][next.node] > next.cost){
				dist[0][next.node] = next.cost;
				heap.push( next );
			}
			if( (cur.used || i->S >= mid) && dist[1][next.node] > next.cost){
				dist[1][next.node] = next.cost;
				next.used = 1;
				heap.push( next );
			}
		}
	}
	return false;
}

int main(){
	int T; cin >> T;
	while(T--){
		scanf("%d%d%d%d%d", &N, &M, &s, &e, &maxp);
		REP(i,0,MAXN) adj[i].clear();
		REP(i,0,M){
			int a, b ,c;
			scanf("%d%d%d", &a,&b,&c);
			adj[a].pb(mp(b,c));
		}
		int lo = 0,hi=INF, mid;
		bool ok;
		while( lo +1 < hi){
			mid = lo+(hi-lo)/2;
			ok = djk(mid);
			if( !ok) hi = mid;
			else lo = mid;
		}
		if( !djk(lo) ) puts("-1");
		else printf("%d\n", lo);
	}	
	return 0;
}