//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1421
//#tag min cut max flow fluxo
//#sol basic application of min cut / max flow 

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
#define INF 1E9
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map
using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }


#define DOTS 10000

typedef vector<int> VI;
typedef pair<int,int> PII;
///maxflow
bool fou[DOTS];
PII pre[DOTS];

///mincostflow-common
int S; // source
int T; // sink
int FN; // number of nodes
int FM; // number of edges (initialize this to 0)
// ra[a]: edges connected to a (NO MATTER WHICH WAY!!!); clear this in the beginning
VI ra[DOTS];
int kend[DOTS], cap[DOTS], cost[DOTS]; // size: TWICE the number of edges

// Adds an edge from a to b with capacity c and cost d and returns the number of the new edge
int addedge(int a, int b, int c, int d) {
	int i = 2*FM;
	kend[i] = b;
	cap[i] = c;
	cost[i] = d;
	ra[a].push_back(i);
	kend[i+1] = a;
	cap[i+1] = c;
	cost[i+1] = -d;
	ra[b].push_back(i+1);
	FM++;
	return i;
}

// Returns the maximum flow from the source to the sink
ll solve() { // reinitialize costs if rerun
	ll totflow = 0;
	while(true) {
		memset(fou, 0, sizeof(fou));
		queue<int> qu;
		qu.push(S);
		fou[S] = true;
		while(!qu.empty()) {
			int i = qu.front();
			qu.pop();
			if (i == T)
				break;
			for (int e : ra[i]) {
				int k = kend[e];
				if (cap[e] > 0 && !fou[k]) {
					qu.push(k);
					pre[k] = PII(i,e);
					fou[k] = true;
				}
			}
		}
		if (!fou[T])
			break;
		int mk = INF;
		for (int i = T; i != S; i = pre[i].first)
			mk = min(mk, cap[pre[i].second]);
		totflow += mk;
		for (int i = T; i != S; i = pre[i].first) {
			cap[pre[i].second] -= mk;
			cap[pre[i].second^1] += mk;
		}
	}
	return totflow;
}

int main(){
	int n,m;
	while(scanf("%d%d", &n, &m) > 0 && (n||m)){
		REP(i,0,n+1) ra[i].clear();
		REP(i,0,m){
			int a, b, c; scanf("%d%d%d", &a, &b, &c); a--, b--;
			addedge( a, b ,c , 0);
		}
		S = 0, T = 1, FM = 0;
		ll mincut = solve();
		set<int> v1,v2,v3;
		REP(i,0,n){
			if( fou[i]) v1.insert( i);
			else v2.insert(i);
		}
		db(mincut);
		for(int i : v1){			
			for(int j : ra[i]){				
				if( v2.count( kend[j] ) > 0) printf("%d %d\n", (i+1) , kend[j]+1);
			}
		}
		puts("");
	}
	
	return 0;
}