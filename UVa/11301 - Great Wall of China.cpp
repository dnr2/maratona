//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2276
//#tag minimum cost flow / fluxo de custo minimo
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
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

#define MAXN 12000
#define MAXM MAXN * 5
typedef vector<int> VI;

const int INF = 1E9; // $infinity$: be careful to make this big enough!!!
int S; // source
int T; // sink
int FN; // number of nodes
int FM; // number of edges (initialize this to 0)
// ra[a]: edges connected to a (NO MATTER WHICH WAY!!!); clear this in the beginning
VI ra[MAXN];
int kend[MAXM], cap[MAXM], cost[MAXM]; // size: TWICE the number of edges

// Adds an edge from a to b with capacity c and cost d and returns the number of the new edge
int addedge(int a, int b, int c, int d) {
	int i = 2*FM;
	kend[i] = b;
	cap[i] = c;
	cost[i] = d;
	ra[a].push_back(i);
	kend[i+1] = a;
	cap[i+1] = 0;
	cost[i+1] = -d;
	ra[b].push_back(i+1);
	FM++;
	return i;
}

int dst[MAXM], pre[MAXM], pret[MAXM];
bool spfa(){
	REP(i,0,FN) dst[i] = INF;
	dst[S] = 0;
	queue<int> que; que.push(S);
	while(!que.empty()){
		int x = que.front(); que.pop();
		for (int t : ra[x]){
			int y = kend[t], nw = dst[x] + cost[t];
			if(cap[t] > 0 && nw<dst[y]){
				dst[y] = nw; pre[y] = x; pret[y] = t; que.push(y);
			}
		}
	}
	return dst[T]!=INF;
}
// returns the maximum flow and the minimum cost for this flow
pair<ll,ll> solve(){
	ll totw = 0, totf = 0;
	while(spfa()){
		int minflow = INF;
		for (int x = T; x!=S; x = pre[x]){
			minflow = min(minflow, cap[pret[x]]);
		}
		for (int x = T; x!=S; x = pre[x]){
			cap[pret[x]] -= minflow;
			cap[pret[x]^1] += minflow;
		}
		totf += minflow;
		totw += minflow*dst[T];
	}
	return make_pair(totf, totw);
}

char in[6][1010];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){
	
	int n;
	while( scanf("%d", &n ) > 0 && n ){		
		FN = 10 * n + 2;
		REP(i,0,5){
			scanf("%s" , in[i]);
		}
		FM = 0;
		REP(i,0,FN + 1) ra[i].clear();
		int OFF = 5 * n;
		S =  2 * OFF;
		T = S + 1;
		REP(i,0,5){
			if( in[i][0] == '@') addedge( S , i * n , 1 , 0 );						
			addedge( ((i+1)*n) - 1 + OFF, T, 5, 0);	
			REP(j,0,n){				
				addedge( i * n + j, i * n + j + OFF, 1, (in[i][j] == '@')? 0 : in[i][j] - '0');				
				REP(k,0,4){
					int ny= i + dy[k], nx = j+ dx[k];
					if( ny < 0 ||  ny >= 5 || nx < 0 || nx >= n ) continue;
					addedge( i * n + j + OFF, ny * n + nx , 5, 0);
				}
			}
		}				
		printf("%d\n", (int) solve().second );
	}	
	return 0;
}