//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2473
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

const int MAXN = 200000;

vector<int> adj[MAXN];
int par[MAXN];
int n, t;


int dfs(int node ){	
	if( adj[node].size() == 0) return 1;
	int ret = 0;
	vector<int> aux;
	REP(i,0,(int)adj[node].size()){
		aux.PB( dfs( adj[node][i]));		
	}
	sort( aux.begin(), aux.end());
	int sz = adj[node].size();
	sz *= t; sz = (sz / 100) + ((sz % 100) > 0);	
	REP(i,0,sz){
		ret += aux[i];
	}	
	return ret;
}

int main(){
	IOFAST();	
	while( cin >> n >> t){
		if( !(n||t)) break;
		REP(i,0,n+1) adj[i].clear();
		
		REP(i,1,n+1){
			int a; cin >> a;
			par[i] = a;
			adj[a].PB( i );			
		}		
		cout <<  dfs( 0 ) << endl;
	}
	
	return 0;
}