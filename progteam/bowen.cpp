#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef long long ll;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define FILL(x,v) memset(x,v,sizeof(x))
const int INF = (int)2E9+5;
#define MAXN 905
#define MAXFN (2*MAXN)
#define MAXM (8*MAXN)
int N, M, P, FN, S, T;
int L, adj[MAXFN];
int dst[MAXFN], gap[MAXFN];
struct list{
	int id,next,c,f;
	list(){}
	list(int _id, int _next, int _c, int _f) {id=_id;next=_next;c=_c;f=_f;}
} lists[2*MAXM];
void insertList(int &a, int b, int c){
	lists[L] = list(b,a,c,0);
	a = L++;
}
void bfs(){
	REP(i,0,FN) dst[i] = FN;
	dst[T] = 0; 
	FILL(gap, 0); 
	gap[0] = FN;
	queue<int> que; que.push(T);
	while(!que.empty()){
		int x = que.front(); que.pop();
		int t = adj[x];
		while(t!=-1){
			if(t&1){ 
				int y = lists[t].id;
				if(dst[y]==FN){
					dst[y] = dst[x]+1;
					gap[dst[y]]++;
					que.push(y);
				}
			}
			t = lists[t].next;
		}
	}
}
int dfs(int x, int inflow){
	if(x==T) return inflow;
	int outflow = inflow, delta = 0, minh = FN-1;
	int t = adj[x];
	while(t!=-1){
		int y = lists[t].id;
		if(lists[t].c != lists[t].f){
			if(dst[x]==dst[y]+1){
				delta = dfs(y, min(outflow, lists[t].c-lists[t].f));
				lists[t].f += delta;
				lists[t^1].f -= delta;
				outflow -= delta;
				if(dst[S]==FN) return inflow-outflow; 
				if(outflow==0) break;
			}
			minh = min(minh, dst[y]);
		}
		t = lists[t].next;
	}
	if(inflow==outflow){ 
		gap[dst[x]]--;
		if(gap[dst[x]]==0) dst[S] = FN; 
		dst[x] = minh + 1;
		gap[dst[x]]++;
	}
	return inflow-outflow;
}
int sap(){
	int maxflow = 0;
	bfs();
	while(dst[S]<FN) maxflow += dfs(S, INF);
	return maxflow;
}
char gd[35][35];
void insertEdge(int a, int b, int c){
	insertList(adj[a], b, c);
	insertList(adj[b], a, 0);
}
#define GN(X,Y) ((X)*M+(Y))
int main(){
	while(scanf("%d%d%d", &N, &M, &P)!=EOF){
		L = 0; FILL(adj, -1);
		int B = N*M;
		S = 0; T = 2*B+1; FN = T+1;
		REP(i,0,N) {
			scanf("%s", gd[i]);
			REP(j,0,M){
				char c = gd[i][j];
				if(c=='*'){
					insertEdge(1+GN(i,j), 1+GN(i,j)+B, 1);
					insertEdge(S, 1+GN(i,j), 1);
				}else if(c=='.') insertEdge(1+GN(i,j), 1+GN(i,j)+B, 1);
				else if(c=='@') insertEdge(1+GN(i,j), 1+GN(i,j)+B, INF);
				else if(c=='#') {
					insertEdge(1+GN(i,j), 1+GN(i,j)+B, INF);
					insertEdge(1+GN(i,j)+B, T, P);
				}
				if(c!='~'){
					if(i-1>=0) insertEdge(1+GN(i,j)+B, 1+GN(i-1,j), INF);
					if(j+1<M) insertEdge(1+GN(i,j)+B, 1+GN(i,j+1), INF);
					if(i+1<N) insertEdge(1+GN(i,j)+B, 1+GN(i+1,j), INF);
					if(j-1>=0) insertEdge(1+GN(i,j)+B, 1+GN(i,j-1), INF);
				}
			}
		}
		printf("%d\n", sap());
	}
	return 0;
}