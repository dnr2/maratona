//http://br.spoj.pl/problems/TUBOS/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>

using namespace std;


int E, L, X, Y, aux, i;
bool grafo[1005][1005];
int cor[1005];
int dfsNum[1005];
int num;
int n;
bool temPontes;

int dfs( int u, int p ) {
	cor[u] = 1;
	dfsNum[u] = num++;
	int leastAncestor = num;
	for( int v = 0; v < n; v++ ) {
		if( grafo[u][v] && v != p ) {
			if( cor[v] == 0 ) {
				// (u,v) is a forward edge
				int rec = dfs( v, u );
				if( rec > dfsNum[u] ){
					//cout << "Bridge: " << u << " " << v << endl;
					temPontes = true;
					}
				leastAncestor = ( leastAncestor <  rec )? leastAncestor: rec;
			} else {
				// (u,v) is a back edge
				leastAncestor = ( leastAncestor< dfsNum[v] )? leastAncestor : dfsNum[v];
			}
		}
	}
	cor[u] = 2;
	return leastAncestor;
}
	
 

int main(){
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout );
    
	
	scanf("%d %d", &E, &L);
	while(E != 0 || L != 0 ){
		temPontes = false;
		memset( grafo, false, sizeof(grafo));
		memset( cor, 0, sizeof(cor));
		
		for( i = 0; i < L; i++){
			scanf("%d %d", &X, &Y);
			grafo[Y-1][X-1] = true;
			grafo[X-1][Y-1] = true;
		}
		n = E;
		num = 0;
		dfs(0, -1);
		if(!temPontes)
			printf("S\n");
		else 
			printf("N\n");
		scanf("%d %d", &E, &L);	
	}
	
	
    return 0;

}
