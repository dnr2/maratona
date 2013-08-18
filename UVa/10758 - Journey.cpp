//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1699
//#tag dijkstra
//#tag graph grafos
//#tag geometry geometria
//#sol usar os dados da entrada para montar um grafo e ir calculando as distâncias de acordo com o 
// enunciasdo, após isso usar o algoritmo de djkstra para achar a distância entra S e F se houver 

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>
#include<queue>

using namespace std; 

struct p{
	int n, a;
	double c;
	p( int n = 0, double c = 0, int a = 0) : n(n), c(c) , a(a) {}
	bool operator < ( const p & in) const {
		return c > in.c;
	}
};


vector<p> g[1011];
double pos[1011][2];
double mark[1010];
double dist[1010];
int pai[1010];

double k;
int N,M,S,F;

double djkstra( int ini, int fim){
	memset(mark, false, sizeof(mark));
	memset(pai, -1, sizeof(pai));
	for( int i = 1 ; i <= N; i++){
		dist[i] = 10000000.0;
	}
	priority_queue<p> heap;
	p cur( ini , 0.0, -1);
	heap.push(cur);
	dist[ini] = 0;
	double aux = 0.0, aux2 = 0.0;
	while(!heap.empty()){
		
		cur = heap.top();
		heap.pop();
		if( mark[cur.n]) continue;
		mark[cur.n] = true;
		dist[cur.n] = cur.c;
		pai[cur.n] = cur.a;
		if ( cur.n == fim) break;
		for( vector<p>::iterator it = g[cur.n].begin(); it < g[cur.n].end(); it++){
			if( cur.a != -1){ 
				aux2 = k * 180 * acos(  
					(( pos[cur.n][0] - pos[cur.a][0]) * ( pos[(*it).n][0] - pos[cur.n][0]) + 
					( pos[cur.n][1] - pos[cur.a][1]) * ( pos[(*it).n][1] - pos[cur.n][1])) 
					/ 
					( hypot( (pos[cur.n][0] - pos[cur.a][0]), ( pos[cur.n][1] - pos[cur.a][1])) *
					hypot( (pos[(*it).n][0] - pos[cur.n][0]), ( pos[(*it).n][1] - pos[cur.n][1])) )
				) / acos( -1) ;
				// cout << "aux2 " << aux2 << endl;
			}
			aux = dist[cur.n] + (*it).c + ((cur.a != -1)? (aux2) : 0);
			// printf("%d -> %d : %lf %d\n", cur.n, (*it).n, aux, cur.a);
			if( !mark[(*it).n] && dist[(*it).n] >= aux ){
				heap.push( p( (*it).n, aux, cur.n));
			}
		}
		
	}
	return dist[fim];
}

void pilha(int x){
	if( x == -1) return;
	pilha( pai[x]);
	printf("%d ", x);
}


int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int i,j,t,a,b,c,d;
	cin >> t;
	double aux;
	bool space = false;
	while(t--){

		scanf("%d%d%d%d%lf", &N, &M, &S, &F, &k);
		for( i = 0; i<=N;i++){
			g[i].clear();
		}
		memset( pos, 0, sizeof(pos));
		for( i = 1; i<= N;i++){
			scanf("%lf%lf" , &pos[i][0], &pos[i][1]);
		}
		for( i = 0; i< M;i++){
			scanf("%d%d" , &a, &b);
			g[a].push_back( p( b, hypot( pos[a][0] - pos[b][0], pos[a][1] - pos[b][1]) , 0)); 
		}	
		
		aux= djkstra( S, F);
		if( space) puts("");
		else space = true;
		if( aux == 10000000.0) printf("Impossible\n");
		else {
			printf("%.3lf\n", aux);
			pilha(pai[F]);
			printf("%d\n", F);
		}
	}
	return 0;
}