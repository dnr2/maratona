//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3520
//#tag all pair shortest path
//#tag floyd warshall
//problema simples de all pair shortest path

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) if(1) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long

using namespace std;

map<string, int> mapa;
int g[60][60];
bool mark[60];
int dist[60][60];
int cont;
int n,m; int caso = 1;

void dfs(int x){
	if( mark[x] ) return;
	mark[x] = 1;
	fr(i,1,n) if(g[x][i]) dfs( i);
}

int main(){
	
	while(scanf("%d%d", &n, &m) > 0 && (n||m)){
		cl(mark); cl(g); n++; memset( dist, 0x3f, sizeof(dist));
		string a, b;  cont =1; mapa.clear();
		fr(i,0,m){
			cin >> a >> b;
			if( !mapa[a] ) mapa[a] = cont++;
			if( !mapa[b] ) mapa[b] = cont++;
			g[mapa[a]][mapa[b]] = 1; g[mapa[b]][mapa[a]] = 1;
		}
		dfs(1) ;
		bool disc = false;
		fr(i,1,n){
			disc = disc || (mark[i] == 0);
		}
		if( disc) {
			printf("Network %d: DISCONNECTED\n\n", caso++);
		} else {
			fr(i,1,n) dist[i][i] = 0;
			fr(i,1,n) fr(j,0,n) if( g[i][j] ) dist[i][j] = 1;
			fr(i,1,n){
				fr(j,1,n){
					fr(k,1,n){
						dist[j][k] = min( dist[j][i] + dist[i][k] , dist[j][k] );
					}
				}
			}
			int resp = 0;
			fr(i,1,n) fr(j,1,n) resp = max( resp , dist[i][j] );
			printf("Network %d: %d\n\n", caso++, resp);
		}
	}
	
	return 0;
}