//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2742
//#tag graph tree arvore grafos
//#tag diameter diametro 
//#tag longest path 
//#sol
// It is clear that the edge we remove has to be on the longest path on the original
// tree (otherwise we cannot make the longest path shorter). The question is which edge is to be
// removed and which edge is to be added. We can consider which edge to be added first. After
// removing one edge, the tree become two trees. The edge to be added is the one that connects
// the centers of the longest paths of the two subtrees. Because the longest paths of the two
// subtrees can always yield some long path after we add the edge. The best way is to split
// them into halves. Having this in mind, we can brute-force here - try to remove every edge
// on the original longest path and add the new edges respectively.


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
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 3000;
vector<int> adj[MAXN];
int par[MAXN], vis[MAXN];
int n;

int bfs(int ini, pii ban, pii add){
	FILL(vis,-1);
	queue<int> q; q.push( ini);
	vis[ini] = 1; par[ini] = -1;
	int ret = ini;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if( cur == add.F) adj[cur].pb( add.S);
		if( cur == add.S) adj[cur].pb( add.F);
		REP(i,0,((int)adj[cur].size())){
			int next = adj[cur][i];
			if( vis[next] == -1 && !((cur==ban.F && next==ban.S) || (cur==ban.S && next==ban.F)) ){
				vis[next] = 1; par[next] = cur;
				q.push( next );
				ret = next;
			}
		}		
		if( cur == add.F || cur == add.S ) adj[cur].pop_back();
	}
	return ret;
}

vector<int> getLongest(int x, pii ban, pii add){
	x = bfs( x , ban, add);  x = bfs( x , ban, add);
	vector<int> vm;
	vm.pb( x );
	while( par[x] != -1){
		vm.pb( par[x] ); x= par[x];
	}
	return vm;
}

int main(){
	int T; cin >> T;
	while(T--){
		scanf("%d", &n);
		REP(i,0,n+1) adj[i].clear();
		int a,b;
		REP(i,0,n-1){
			scanf("%d%d", &a,&b); a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		vector<int> vm = getLongest( 0 ,mp(-1,-1), mp(-1,-1));
		int sz = vm.size();
		int best = INF;
		int rm1=0,rm2=0,add1=0,add2=0;
		REP(i,0,sz-1){
			vector<int> v1,v2,v3; int sz1 , sz2, sz3;
			v1 = getLongest( vm[i] , mp( vm[i], vm[i+1]), mp(-1,-1)); sz1 = v1.size();
			v2 = getLongest( vm[i+1] , mp( vm[i], vm[i+1]), mp(-1,-1)); sz2 = v2.size();
			v3 = getLongest( vm[i] , mp( vm[i], vm[i+1]), mp(v1[sz1/2], v2[sz2/2])); sz3 = v3.size();			
			if( sz3 < best ){
				best = sz3;
				rm1 = vm[i], rm2 = vm[i+1], add1= v1[sz1/2], add2 = v2[sz2/2];
			}
		}
		printf("%d\n%d %d\n%d %d\n", best-1, rm1+1, rm2+1, add1+1,add2+1);
	}
	return 0;
}