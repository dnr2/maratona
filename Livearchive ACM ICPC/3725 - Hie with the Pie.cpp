//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
//#tag: Djkstra variant
//#tag: Graph, grafo 


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;


struct No{
	int n, cost, mask;
	No(int n=0, int cost=0, int mask = 0) : n(n), cost(cost), mask(mask) {}
	bool operator < ( const No & a ) const {
		return cost >= a.cost;
	}
};

int  i, j, k, m, n, a, b, c, d;
int in[15][15];
bool mark[15][1050];
No aux;
int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &n) > 0 && n){
		n++;
		memset(mark,false,sizeof(mark));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d", &in[i][j]);
			}
		}
		priority_queue<No> q;
		q.push(No(0,0,0));
		int r =0;
		while(!q.empty()){
			aux = q.top(); q.pop();
			// printf("no: %d custo: %d mask : %d\n", aux.n, aux.cost, aux.mask );
			if(aux.mask == ((1<<n) -1) && aux.n == 0){
				r = aux.cost;
				break;
			}
			if(mark[aux.n][aux.mask]) continue;
			mark[aux.n][aux.mask] = true;
			// cout << "lol" << endl;
			for(i=0;i<n;i++){
				if( i == aux.n) continue;
				m = (aux.mask) | (1<<i);
				q.push(No(i,aux.cost+in[aux.n][i], m));
			}
		}
		cout<< r << endl;
	}
	return 0;
}
