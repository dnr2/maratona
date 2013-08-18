//uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=945&mosmsg=Submission+received+with+ID+9182647

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, k, a, b, c, d, n ,m;
int e;
vector<int> g[210];
vector<int>::iterator it;
int mark[210];
int cor[210];

bool bicolor(int start){

	queue<int> f;
	f.push(start);	
	memset(mark, 0, sizeof(mark));
	memset(cor, -1, sizeof(cor));
	int c = 1;
	cor[start] = 0;	
	while(!f.empty()){
		int ac = f.front();
		f.pop();
		mark[ac] = 1;
		for( it = g[ac].begin(); it != g[ac].end(); it++){
            //printf("%d (%d) -> %d (%d)\n", ac, cor[ac], *it, cor[*it]);
			if( mark[*it] == 0 ){
				f.push(*it);
				cor[*it] = (cor[ac] + 1) % 2;	
			} 
			if( cor[*it] == cor[ac]){
				return false;
			}
		}
	}
	return true;
}


int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while( scanf("%d", &n) > 0 && n != 0){
		scanf("%d", &e);
		for( i = 0 ; i < e; i++){
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}		
		if( bicolor(0) ) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
		for( i = 0 ; i < 210; i++){
			g[i].clear();
		}
    }	
	return 0;
}
