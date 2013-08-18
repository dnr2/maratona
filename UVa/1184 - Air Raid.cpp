//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3625
//#tag: Minimum path cover in directed acyclic graph
//#tag: max flow
//#tag: graph
//#sol: using the max flow ford fulkerson algorith you create a new graph from initial such that the
// minimum path cover will be exatly n - f, where n is the number of nodes in the input graph 
// and f is the max flow
// the new graph G =(V,E) will be such that V = {x0, x1, x2 ..., xn} U {y0, y1, y2 ..., yn} and 
// E  = { (x0 , xi) | i in (1..n) } U { (yi , y0) | i in (1..n) } U { (xi , yj) | 
// (i,j) belongs to the original graph }

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int g[300][300];
int pai[300];
bool mark[300];
int n,m,fim,a,b;

void dfs(int v, int p){
	mark[v] = true;
	for( int i=0;i<=fim; i++){
		if( g[v][i] && !mark[i]){
			pai[i] = v;
			if( i == fim) return;
			dfs(i, v);
		}
	}
}

int maxflow(){
	int fluxo = 0;
	while(true){
		memset( mark, false, sizeof(mark));
		memset( pai, -1, sizeof(pai));
		dfs(0,-1);
		
		int cur = fim;
		int mini = 10000000;
		while(pai[cur] != -1){
			mini = min( mini, g[pai[cur]][cur]);
			cur = pai[cur];
		}
		
		if( mini == 10000000) break;
		
		cur = fim;
		while(pai[cur] != -1){
			g[pai[cur]][cur] -= mini;
			g[cur][pai[cur]] += mini;
			cur = pai[cur];
		}
		
		fluxo += mini;
	}
	return fluxo;
}

int main(){
	// freopen("in.txt","r", stdin);
	// freopen("out.txt","w", stdout);
	int t;
	cin >> t;
	while(t--){
		int i;
		memset( g, 0, sizeof(g));
		scanf("%d%d", &n, &m);
		for( i=1;i<=n;i++){
			g[0][i] = 1;
		}
		fim = (2*n)+1;
		for( i=n+1;i<fim;i++){
			g[i][fim] = 1;
		}
		
		for( i=0;i<m;i++){
			scanf("%d%d", &a, &b);
			g[a][n+b] = 1;
		}
		
		
		int resp = maxflow();
		printf("%d\n", n - resp);
		
	}
	return 0;
}

