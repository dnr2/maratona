//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=385&page=show_problem&problem=761
//#tag max flow
//#tag graph


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>


using namespace std;

int a,b,c,d,i,k,j,n,m, caso=1;
int s,f, g[110][110];
bool mark[110];
int from[210];

int flow(){
	for(int x= 0; x<200; x++) from[x] = -1;
	queue<int> q;
	q.push(s);
	mark[s] = true;
	int w,cap = 100000000, prev;
	bool lol = true;
	while(!q.empty() && lol){	
		w = q.front();
		q.pop();
		for(int x = 0; x <=n; x++){
			if(!mark[x] && g[w][x] > 0){
				// printf("x - %d y - %d\n", w, x);
				q.push(x);
				mark[x] = true;
				from[x] = w;
				if( x == f) {	
					lol = false;
					break;
				}
			}
		}
	}
	
	w = f;
	while(from[w] > -1){
		prev =from[w];
		cap = min(cap, g[prev][w]);
		w = prev;
	}
	w = f;
	while(from[w] > -1){
		prev =from[w];
		g[prev][w] -= cap;
		g[w][prev] += cap;
		w = prev;
	}
	if(cap == 100000000) cap = 0;
	return cap;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &n) >0 && n != 0){
		memset(g, 0, sizeof(g));
		scanf("%d%d%d", &s, &f, &m);
		for(i=0;i<m;i++){
			scanf("%d%d%d", &a, &b, &c);
			g[a][b] += c;
			g[b][a] += c;
		}
		int total = 0;
		while(true){
			memset(mark, false, sizeof(mark));
			a = flow();
			// print();
			if(a==0) break;
			total += a;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", caso++, total); 
	}	
	return 0;
}
