//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
//#tag: Graph
//#tag: Bellman-Ford
//#tag: Single Source Sortest Path


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<queue>


#define INF 10000000
using namespace std;

struct Edge{

	int p, v;
	
	Edge(int p=0,int v=0): p(p), v(v) {}

	bool operator  < (const Edge & e) const{
		return p > e.p;
	}
};

int i,j,k,n,m,num,a,b,c,d, caso;
vector<Edge> g[1100];
int dist[1100];


int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	cin >> caso;

	while(caso--){	
		scanf("%d%d", &n, &m);
		for(i=0;i<m;i++){
			scanf("%d%d%d", &a, &b, &c);
			Edge e(c,b);
			g[a].push_back(e);
		}
		
		for(i=0;i<n;i++){
			dist[i] = INF;
		}
		dist[0] = 0;
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(vector<Edge>::iterator it = g[j].begin(); it < g[j].end(); it++){
					//printf("%d -> %d dist : %d\n", j, it->v,dist[it->v] );
					if( dist[j] != INF &&  ( dist[j] + it->p < dist[it->v] || dist[it->v] == INF) ){
						dist[it->v] = dist[j] + it->p;
						//printf(" now : %d\n", dist[it->v]);
					}
				}
			}	
		}
		//cout << endl;
		//for(i=0;i<n;i++){
		//	cout << dist[i] << endl;
		//}
		bool resp = true; // não tem ciclo negativo
		for(j=0;j<n;j++){
			for(vector<Edge>::iterator it = g[j].begin(); it < g[j].end(); it++){
				if( dist[j] + it->p < dist[it->v] ){
					resp = false; // tem ciclo negativo
					//printf("%d -> %d dist : %d\n", j, it->v,dist[it->v] );
					break;
				}
			}
			if(!resp) break;
		}	

		if(resp) printf("not possible\n");
		else printf("possible\n");

		for(i=0;i<=n;i++){
			g[i].clear();
		}
		
		//cout << endl;

	}


	return 0;
}
