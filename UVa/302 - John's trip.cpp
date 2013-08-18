//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=238
//#tag: Graph
//#tag: Hierholzer Algorithm, Fleury's Algorithm
//#tag: Caminho Euleriano, Eulerian Path

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>

#define INF 100000

using namespace std;

struct Edge{
	int num, v;
	Edge(int num=0, int v=0) : num(num), v(v) {}
	bool operator < ( const Edge & e) const {
		return num >= e.num;
	}
};

int i,j,k,n,m,num,a,b,c,d, caso =1;
int v[50], ed[2000];
priority_queue<Edge> g[50];

//heirholzer
list<int> rec(int x){	
	//printf("entrando no vertice %d\n", x);
	list<int> ret, func;
	while(!g[x].empty()){
		Edge aux = g[x].top();
		g[x].pop();
		if(ed[aux.num]) continue;
		ed[aux.num] = 1;
		func = rec(aux.v);
		ret.splice(ret.begin(), func);
		ret.push_front(aux.num);
	}
	/*printf("returning from vertex %d : ", x);
	for(list<int>::iterator it = ret.begin();it!= ret.end();it++){
		if(it != ret.begin()) printf(" ");
		printf("%d", *it);
	}
	puts("");
	*/
	return ret;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int start = 0;
	while(scanf("%d%d", &a,&b)>0 && a!=0 && b!=0){
		num = 0;
		memset(v,0,sizeof(v));
		memset(ed,0,sizeof(ed));
		scanf("%d", &c);
		for(i=0;i<50;i++){ 
			while(!g[i].empty()){
				g[i].pop();
			}
		}
		Edge e1(c,b);
		g[a].push(e1);
		Edge e2(c,a);
		g[b].push(e2);
		
		v[a]++; v[b]++;
		num = max(num, max(a,b));
		start = min(a,b);
		while(scanf("%d%d", &a,&b)>0 && a!=0 && b!=0){
			scanf("%d", &c);
			Edge e3(c,b);
			Edge e4(c,a);
			g[b].push(e4);
			g[a].push(e3);
			v[a]++; v[b]++;
			num = max(num, max(a,b));
		}
		bool par = true;
		for(i=0;i<=num;i++){
			if(v[i]&1){
				par = false;
			}
		}
		if(!par) printf("Round trip does not exist.\n\n");
		else{
			list<int> l = rec(start);
			for(list<int>::iterator it = l.begin();it!= l.end();it++){
				if(it != l.begin()) printf(" ");
				printf("%d", *it);
			}
			puts("\n");
		}
		
	}
	return 0;
}
