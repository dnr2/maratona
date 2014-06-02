//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1390
//#tag graph grafos
//#tag bellman ford
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

const int MAXN = 210;
const int INF = 10000000;

int N,M,Q;
int cost[MAXN];
bool vis[MAXN];
bool neg[MAXN];
vector<pii> adj[MAXN];

void dfs( int x){
	if( vis[x] ) return;
	vis[x] = true;
	FOREACH(i,adj[x]) dfs(i->F);
}

int main(){
	int csn = 1;
	while(scanf("%d", &N) > 0){
		REP(i,0,N){ 
			scanf("%d", cost+i); adj[i].clear(); vis[i] = false; neg[i] = false;
		}
		scanf("%d", &M);
		REP(i,0,M) {
			int a,b; scanf("%d%d", &a,&b);
			a--; b--;
			int c = cost[b] - cost[a];
			adj[a].pb( mp( b, c * c * c)); 
		}
		dfs(0);
		REP(i,0,N) cost[i] = INF;
		cost[0] = 0;
		REP(i,0,N) REP(j,0,N) {
			FOREACH(k,adj[j]){
				int nc = cost[j] + k->S;
				if( nc < cost[k->F] ) cost[k->F] = nc; 
			}
		}
		REP(j,0,N) {
			FOREACH(k,adj[j]){
				int nc = cost[j] + k->S;
				if( nc < cost[k->F] ) cost[k->F] = -INF; 
			}
		}
		printf("Set #%d\n", csn++);
		scanf("%d", &Q);
		REP(i,0,Q){
			int que; scanf("%d", &que); que--;
			if( cost[que] < 3 || !vis[que] ) puts("?");
			else printf("%d\n", cost[que]);
		}
		
	}
	return 0;
}