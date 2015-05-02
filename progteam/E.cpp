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

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

// #define umap unordered_map

using namespace std;

vector<int> g[5010];
int mark[5010], passo = 0;
int fim = 0;

int dfs(int x, int dep){	
	if( mark[x] == passo) return -1;
	mark[x] = passo;
	if( x == fim ) {
		if( dep == 0)  printf("The fleas meet at %d.\n", x);		
		return dep;
	}
	int aux;
	fr(i,0,g[x].size()){
		aux = dfs( g[x][i], dep+1);
		if( aux >=0 ) {
			if( aux & 1 && dep == (aux>>1)){
				printf("The fleas jump forever between %d and %d.\n",  
					min(x, g[x][i]), max(x, g[x][i]));
			} else if( (aux & 1) == 0 && dep == (aux>>1)) {
				printf("The fleas meet at %d.\n", x);
			}
			return aux;
		}
	}
	return -1;
}

int main(){
	

	int n, l, a,b;
	while( scanf("%d", &n) >0 && n){
		fr(i,1,n+1) g[i].clear();		
		fr(i,0,n-1){
			scanf("%d%d", &a,&b );
			g[a].pb(b); g[b].pb(a);
		}
		cin >> l;		
		fr(i,0,l){		
			passo++;
			scanf("%d%d", &a,&b );
			fim = b;
			dfs( a, 0 );
		}		
	}
	return 0;
}