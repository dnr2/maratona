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

#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
typedef long long ll;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define FILL(x,v) memset(x,v,sizeof(x))
const int INF = (int)1E9;
#define MAXN 105
#define MAXFN 305
#define MAXM (105*305)
int N, M, FN, S, T;
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
int xv[MAXN], xb[MAXN], xe[MAXN], mk[2*MAXN][5];
vector< pair<int,int> > anss[MAXN];
int main(){
	int csn = 0;
	while(1){
		scanf("%d", &N);
		if(!N) break;
		scanf("%d\n", &M);
		int a,b;
		vector<int> vt;
		int bans = 0;
		L = 0; FILL(adj, -1);
		REP(i,0,N){
			scanf("%d%d%d", xv+i,xb+i,xe+i);
			bans += xv[i];
			vt.push_back(xb[i]); vt.push_back(xe[i]);
		}
		sort(vt.begin(), vt.end());
		vt.erase(unique(vt.begin(),vt.end()), vt.end());
		int sz = vt.size();
		S = 0; T = N+sz; FN = T+1;
		REP(i,0,N){
			insertList(adj[S], i+1, xv[i]);
			insertList(adj[i+1], S, 0);
			REP(j,0,sz-1){
				if(xb[i]<=vt[j] && xe[i]>=vt[j+1]){					
					insertList(adj[i+1], N+j+1, vt[j+1]-vt[j]); 
					insertList(adj[N+j+1], i+1, 0);
				}
			}
		}
		REP(j,0,sz-1){
			insertList(adj[N+j+1], T, M*(vt[j+1]-vt[j]));
			insertList(adj[T], N+j+1, 0);
			REP(k,0,M) mk[j][k] = vt[j];
		}
		int ans = sap();
		printf("Case %d: ", ++csn);
		if(ans==bans) {
			puts("Yes");
			REP(i,0,N){
				int t = adj[i+1];
				anss[i].clear();
				while(t!=-1){
					int y = lists[t].id;
					if(y>N && y<T && lists[t].f>0){
						int f = lists[t].f, j = y-N-1;
						REP(k,0,M){
							if(mk[j][k] == vt[j+1]) continue;
							if(mk[j][k] + f >  vt[j+1]){
								int hf = vt[j+1] - mk[j][k];
								if(anss[i].size() && anss[i].back().first == vt[j+1]) anss[i].back().first -= hf;
								else anss[i].push_back( make_pair(mk[j][k], mk[j][k]+hf) );
								mk[j][k] += hf; f -= hf;
							}else{
								if(anss[i].size() && anss[i].back().first == mk[j][k]+f) anss[i].back().first -= f;
								else anss[i].push_back( make_pair(mk[j][k], mk[j][k]+f) );
								mk[j][k] += f;
								break;
							}
						}
					}
					t = lists[t].next;
				}
			}
			REP(i,0,N){
				sort(anss[i].begin(), anss[i].end());
				printf("%d", anss[i].size());
				REP(j,0,anss[i].size()) printf(" (%d,%d)", anss[i][j].first, anss[i][j].second);
				puts("");
			}
		}else puts("No");
	}
	return 0;
}