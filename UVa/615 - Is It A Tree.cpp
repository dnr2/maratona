//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=556
//#tag: graphs, grafos, arvores
//#tip: problema ao interpretar a questão, podia haver uma floresta? podia haver aresta dupla?
// 		erro ao codar bfs -_-

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int a, b, c, d, n, m , i, j, k;
int caso =  1, ini, num;
vector<int> g[50000];
map<int,int> h;
int mark[50000];
int hasf[50000];
queue<int> fila;
bool isTree;
int aux;

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	num = 1;
	ini = 1;

	while(scanf("%d%d", &a, &b) > 0 && a >= 0){
		if( a != 0 ){
			if(!h[a]) h[a] = ini++;
			if(!h[b]) h[b] = ini++;			
			g[h[a]].push_back(h[b]);
			hasf[h[b]]++;
			// cout << a << "->" << h[a] << " " << b << "->" << h[b] << endl;			
		} else  {
			isTree  = true;		
			
			for( i = 1; i < ini && isTree; i++){
				if( hasf[i] > 1) {
					isTree = false;
					// cout << "bugou no numero de flechas: " << i << " ";
					// puts("");
				}
			}
			for( i = 1; i < ini && isTree; i++){
				if( hasf[i] == 0 ){ // root
					fila.push(i);						
					// cout << "root: " << i << endl;
					while(!fila.empty() && isTree){
						int x = fila.front();
						fila.pop();
						if( mark[x] ) continue;
						mark[x] = 1;
						// printf("%d\n", x);
						for( vector<int>::iterator it = g[x].begin(); it < g[x].end() && isTree; it++){														
							fila.push(*it);	
						}		
					}
					break;
				}
			}
			for( i = 1; i < ini && isTree; i++){
				if( mark[i] == 0){
					isTree = false;
					// cout << "bugou pois " << i << " nao ta marcado" << " "; 
				}
			}
			printf("Case %d is %sa tree.\n", 	caso++, (isTree)? "": "not ");
			for( i = 1; i <= ini; i++){
				mark[i] = 0;
				hasf[i] = 0;
				g[i].clear();			
			}
			num = 1;
			ini = 1;
			h.clear();
		}
		
	}
	
	
	
	return 0;
}


