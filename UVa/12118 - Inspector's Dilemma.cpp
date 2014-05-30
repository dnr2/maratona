//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3270
//#tag eulerian graph
//#sol for each connected component count the number of nodes with odd degree to calculate the minimum number of edges 
//must be added to create an eulerian graph. count also the edges between components

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
//#include <sstream>
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

const int maxn = 1010;
int n, m, t;
vector<int> adj[maxn];
bool mark[maxn];

int dfs( int x) {
	if( mark[x]) return 0;
	mark[x] = true;	
	int ret = ((int)adj[x].size()) & 1;
	REP(i,0,adj[x].size()){		
		int aux = dfs( adj[x][i]);
		ret += aux;
	}
	return ret;
}

int main(){	
	int cn = 1;
	while( scanf("%d%d%d", &n,&m,&t) > 0 && (n || m || t)){
		REP(i,0,n+1) adj[i].clear();
		memset(mark,0,sizeof(mark));
		REP(i,0,m){
			int a, b; scanf("%d%d", &a, &b);
			a--; b--;
			adj[a].pb(b); adj[b].pb(a);			
		}
		int resp = m;
		int ncomp = 0;
		REP(i,0,n){
			if( !mark[i] && adj[i].size() > 0 ){				
				ncomp++;
				int ret = dfs(i);
				resp += max(0,(ret - 2) / 2);
			}
		}		
		printf("Case %d: %d\n", cn++, t * (resp + max(0,ncomp-1) ));
	}
	return 0;
}



