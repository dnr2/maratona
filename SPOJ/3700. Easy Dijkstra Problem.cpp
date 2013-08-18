//http://www.spoj.pl/problems/EZDIJKST/
//#tag: graphs, dijkstra
//#tips: pay attention for the description of the graph! if it is directed or undirected!
//#time: 24H

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct edge{
	int e, peso;
	
	bool operator <(const edge & x) const{
		return (peso >= x.peso);	
	}
	
};

int i , j , k , n , m , a, b, c, d;

vector<edge> g[10100];
int mark[10100];
// int markdfs[10100];
int dist[10100];
priority_queue<edge> heap;

// void dfs(int s){
	// if(markdfs[s]) return;
	// markdfs[s] = 1;
	// for( vector<edge>::iterator it = g[s].begin(); it < g[s].end(); it++){
		// dfs(it->e);
	// }
// }

void djkstra(int s){	
	memset(dist, -1, sizeof(dist));
	memset(mark, 0, sizeof(mark));
	edge start;
	start.e = s;
	start.peso = 0;
	heap.push(start);
	vector<edge>::iterator it;
	dist[s] = 0;
	
	while(!heap.empty()){
		edge x = heap.top();
		heap.pop();
		if( mark[x.e] == 1) continue;
		mark[x.e] = 1;
		for( it = g[x.e].begin(); it < g[x.e].end(); it++){
			if( dist[it->e] < 0 || dist[it->e] > dist[x.e] + it->peso ) {
				dist[it->e] = dist[x.e] + it->peso;
				edge aux;
				aux.e = it->e;
				aux.peso = dist[it->e];
				heap.push(*it);
			}
		}
		// for( int y = 1 ; y <= n; y++){
			// printf("\t%d", dist[y]);
		// }
		// puts("");
	}
	
}


int main(){	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);	
	int caso;
	scanf("%d", &caso);
	while(caso--){
		
		scanf("%d %d", &n, &m);
		// memset(dist, 1000000, sizeof(dist));
		// memset(markdfs, 0, sizeof(markdfs));
		for( i = 0 ; i <= n ; i++){
			g[i].clear();
		}
		
		for( i = 0 ; i < m ; i++){
			scanf("%d%d%d", &b, &c, &d);
			edge e1, e2; 
			e1.e = b;
			e2.e = c;
			e1.peso = e2.peso = d;
			g[b].push_back(e2);
			// g[c].push_back(e1);
		}
		scanf("%d%d", &b, &c);
		
		djkstra(b);
		if( dist[c] == -1) printf("NO\n");
		else printf("%d\n", dist[c]);
		// dfs(b);
		// printf("%d\n\n", markdfs[c]);
	}
	
    return 0;
}

