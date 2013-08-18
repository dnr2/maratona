//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1867&mosmsg=Submission+received+with+ID+9870804
// #tag: DAG
// #tag: DFS

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int i,j,k,n,m,a,b,c,d;

vector<int> g[110];
int mark[110];

int dfs(int x ){
	if(mark[x]) return 0;
	if(g[x].empty()) {
		mark[x] =1;
		return 1;
	}
	mark[x] = 1;
	int retorno = 0;
	for( vector<int>::iterator it = g[x].begin(); it < g[x].end(); it++){
		retorno += dfs(*it);
	}
	return retorno + 1;
}

int main(){	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &n) > 0 && n != 0){
		
		for(i=1;i<=n;i++){
			scanf("%d", &m);
			for(j=0;j<m;j++){
				scanf("%d", &a);
				g[i].push_back(a);
			}
		}
		int maior = 0, index = 1, aux = 0;
		for(i=1;i<=n;i++){
			memset(mark, 0, sizeof(mark));
			aux = dfs(i);
			if(maior < aux) {
				maior= aux;
				index = i;
			}
		}
		printf("%d\n", index);
		for(i=0;i<=n;i++){
			g[i].clear();
		}
	}
	
	return 0;
	
}
