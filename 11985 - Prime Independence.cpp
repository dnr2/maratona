//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3136

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pair<int,int> pii

using namespace std;

int i,j,k,a,b,c,d, n,m;
int caso =1;

int in[40005];
int ant[40005];
bool mark[40005];
vector<pii> g[40005];
int crivo[500100];
map<int,int> mapa;


void dfs(int x, int & f){
	
	if( mark[x]) return;
	mark[x] = true;
	for( vector<pii>::iterator it = g[x].begin(); it < g[x].end();it++){
		ant[(*it).first] = x;
		if((*it).first == f) {
			return;
		}
		dfs( *it, f);
	}
	return;
}

int maxflow(int x, int f){
	int ret = 0;
	while( true){
		
		memset( ant, -1, sizeof(ant));
		dfs( x, f);
		
		int current = f, mini = 1000000;
		while( ant[current] != -1){
			//TODO
			mini = min( mini, dist[current][ant[current]]);
			current = ant[current];
		}
		
		int current = f ;
		while( ant[current] != -1){
			//TODO
			dist[current][ant[current]] += min;
			dist[ant[current]][current] -= min;
			current = ant[current];
		}
		if( mini = 1000000) break;
		ret += mini;
	}
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for( i= 0; i< 500001; i++){
		crivo[i] = i;
	}
	i = 2;
	while(i<500001){
		// printf("%d\n", i);
		for( j=i+i;j<500001;j+=i){
			crivo[j] = i;			
		}
		i++;
		while( crivo[i] != i && i<500001){
			i++;
		}
	}
	int t;
	cin >> t;
	
	while( t--){
		scanf("%d" , &n);
		mapa.clear();
		
		for( i=1;i<=n;i++){
			scanf("%d", &in[i]);
			mapa[in[i]] = i;
			g[i].clear();
		}
		for( i=1;i<=n;i++){
			a = in[i];
			while( a != 1){
				a /= crivo[a];
				
			}
		}
		
	}
	return 0;
}