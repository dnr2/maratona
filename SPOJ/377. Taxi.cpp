//http://www.spoj.pl/problems/TAXI/
//#tag max flow fluxo
//#tag bipartite matching 
//#tag dinic
//#sol criar um grafo bipartido a partir da entrada onde cada person se liga com um taxicab se for
//possível chegar até tal loval em tempo menor que c. 

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<iostream>

#define MAX 1000
#define MAXE 2060000

using namespace std;

int in[500][2];
int fim,a,b,p,t,s,c,j;

int n, m, cont, adj[MAX], level[MAX], fila[MAX], copy_adj[MAX], cap[MAXE], to[MAXE], ant[MAXE];

void add(int x, int y, int z) {
    to[cont] = y, cap[cont] = z, ant[cont] = adj[x]; adj[x] = cont++;
    to[cont] = x, cap[cont] = 0/*z se for bidirecional*/, ant[cont] = adj[y]; adj[y] = cont++;
}

//dinic auxiliar functions (bfs and dfs)
int bfs(int source, int sink) {
    memset(level, -1, sizeof(level));
    level[source] = 0;
    int pos = 0, tam = 0;
    fila[tam++] = source;
    while(pos < tam) {
        int now = fila[pos++];
        for (int i = adj[now]; i >= 0; i = ant[i]) {
            if (cap[i] && level[to[i]] == -1) {
                level[to[i]] = level[now] + 1;
                fila[tam++] = to[i];
            }
        }
    }
    return level[sink] != -1;
}

int dfs(int no, int sink, int flow) {
    if (no == sink) return flow;
    for (int &i = copy_adj[no]; ~i; i = ant[i])
        if (cap[i] && level[no] + 1 == level[to[i]]) {
            int nflow = dfs(to[i], sink, min(flow, cap[i]));
            if (nflow) {
                cap[i] -= nflow, cap[i^1] += nflow;
                return nflow;
            }
        }
    return 0;
}

//the dinic algorithm
int dinic(int source, int sink) {
    int mf = 0;
    while(true) {
        if (bfs(source, sink)) {
            memcpy(copy_adj, adj, sizeof(adj));
            while(true) {
                int add = dfs(source, sink, 1<<30);
                if (add) mf+=add;
                else break;
            }
        }
        else break;
    }
    return mf;
}

int main(){
	// freopen("in.txt","r", stdin);
	// freopen("out.txt","w", stdout);
	int caso;
	cin >> caso;
	while(caso--){
		int i;
		cont = 0;
		memset(adj, -1, sizeof(adj));
		memset( in, 0, sizeof(in));
		scanf("%d%d%d%d", &p, &t, &s, &c);
		for( i=1;i<=p;i++){
			add(0, i, 1);
		}
		fim = p + t + 1;
		for( i=p+1;i<fim;i++){
			add(i, fim, 1);
		}
		
		for( i=1;i<=p;i++){
			scanf("%d%d", &a, &b);
			in[i][0] =a;
			in[i][1] =b;
		}
		for( i=1;i<=t;i++){
			scanf("%d%d", &a, &b);
			for( j = 1;j<=p;j++){
				if( 200 * (abs( a - in[j][0]) + abs( b - in[j][1])) <=  c * s) {
					add(j, p + i, 1);
				}
			}
		}
		
		int resp = dinic(0, fim);
		printf("%d\n", resp);
		
	}
	return 0;
}

