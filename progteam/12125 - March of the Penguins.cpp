//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3277
//#tag max flow fluxo
//#tag graphs  grafos
//#sol This is a maximum ow problem with vertex capacity. We create a copy x0 for
// each vertex x. If a penguin can jump from x to y, we add an edge from x0 to y with capacity
// lx. For a vertex x with initially k penguins, we add an edge from S to x with capacity k.
// Finally we enumerate T and run maximum 
// ow with each T to find the answer.

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
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

#define DOTS 60000
typedef vector<int> VI;
typedef pair<int,int> PII;

const int INF = 1E9; // $\infty$: be careful to make this big enough!!!
int S; // source
int T; // sink
int FN; // number of nodes
int FM; // number of edges (initialize this to 0)
// ra[a]: edges connected to a (NO MATTER WHICH WAY!!!); clear this in the beginning
VI ra[DOTS];
int kend[DOTS], cap[DOTS]; // size: TWICE the number of edges
// Adds an edge from a to b with capacity c and returns the number of the new edge
int addedge(int a, int b, int c) {
	
	int i = 2*FM;
	kend[i] = b;	
	cap[i] = c;
	ra[a].push_back(i);
	kend[i+1] = a;
	cap[i+1] = 0;
	ra[b].push_back(i+1);
	FM++;
	return i;
}


///maxflow
bool fou[DOTS];
PII pre[DOTS];
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

int in[200][4];
int n; double d;
int npeng;

void create_graph(){
	REP(i,0,3*n) ra[i].clear();
	FM = 0;
	REP(i,0,n) {
		addedge( S , i, in[i][2] );
		addedge( i , i+n, in[i][3] );
		REP(j,0,n){
			if( i == j) continue;
			if( d + EPS >= sqrt( pow(in[i][0] - in[j][0],2) + pow(in[i][1] - in[j][1],2) ) ){
				addedge(i+n, j , 100000);
			}
		}
	}
}

int main(){
	int cn; cin >> cn;
	while(cn--){
		cin >> n >> d;
		npeng = 0;
		REP(i,0,n){
			scanf("%d%d%d%d", in[i], in[i]+ 1, in[i]+2, in[i]+3);
			npeng += in[i][2];
		}
		S = 2*n;
		
		vector<int> nodes;
		REP(i,0,n){
			create_graph();
			T = i;
			int aux = solve();
			if( aux == npeng) nodes.pb( i );			
		}
		if( nodes.size() == 0){
			puts("-1");
		} else {
			bool prim = true;
			for( int i : nodes ){
				if( prim ) prim = false;
				else printf(" ");
				printf("%d", i);
			}
			puts("");
		}
	}
	return 0;
}