//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3319
//#tag SCC 
//#sol transform each CC in one onde, after that cound the number of nodes with inside edges and outside edges.
// to make the graph connected just have to add a number of edges equivalent to the number  of components minus
// the minimum between the number of nodes with inside edges and nodes with outside edges.

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

const int maxn = 60000;

#define DOTS 30000
typedef vector<int> VI;

int N;
VI adj[DOTS];
int tim;
int vis[DOTS], low[DOTS];
stack<int> st;
int comp[DOTS]; // \verb|comp[i]| is the number of the component containing node i
int compnr; // Number of components (numbered from 0 to compnr-1)

void visit(int i) {
	if (vis[i])
		return;
	tim++;
	vis[i] = low[i] = tim;
	st.push(i);
	for (int kk = 0; kk < (int)adj[i].size(); kk++) {
		int k  = adj[i][kk];
		visit(k);
		low[i] = min(low[i], low[k]);
	}
	if (low[i] == vis[i]) {
		while(true) {
			int k = st.top();
			st.pop();
			comp[k] = compnr;
			low[k] = 1E9;
			if (k == i)
				break;
		}
		compnr++;
	}
}
void solve() {
	tim = 0;
	compnr = 0;
	fill_n(vis, N, 0);
	REP(i,0,N)
		visit(i);
}


int main(){
	
	IOFAST();
	int T; cin >> T;
	REP(cn,1,T+1){
		cin >> N; int m; cin >> m;
		REP(i,0,N) adj[i].clear();	
		REP(i,0,m){
			int a, b ; cin >> a >> b;
			a--; b--;
			adj[a].PB( b );
		}
		solve();
		set<int> in, out;
		// DB( N ) ;
		REP(i,0,N){
			// DB( comp[i] );
			REP(j,0,(int)adj[i].size()){
				if( comp[i] != comp[adj[i][j]] ){
					out.insert( comp[i] );
					in.insert( comp[adj[i][j]] );
				}
			}	
		}		
		// DB( compnr _ in.size() _ out.size() );
		if( compnr == 1 ){
			cout << 0 << endl;
		} else {
			cout << (compnr - min( in.size(), out.size()))  << endl;
		}
	}
	
	return 0;
}