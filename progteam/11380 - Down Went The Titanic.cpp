//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2375
//#tag max flow
// #sol Note that as long as people don't move, she won't get drowned. Therefore the
// order of moves does not matter as long as the 0/1/infinite passing requirements are satisfied.`
// This is a typical vertex capacity requirement. We can model this easily. The remaining part
// is that each safe location can take at most P people. There is no need to send more than P
// flow to a safe location. Thus P is just the edge capacity from these safe locations to T.

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
#include <stack>
#include <map>
#include <sstream>
#include <climits>
#include <set>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

#define MAXN 905
#define MAXFN (2*MAXN)
#define MAXM (8*MAXN)

int N, M, P, FN, S, T;
int L, adj[MAXFN];
int dst[MAXFN], gap[MAXFN];

struct llist{
	int id,next,c,f;
	llist(){}
	llist(int _id, int _next, int _c, int _f) {id=_id;next=_next;c=_c;f=_f;}
} lists[2*MAXM];

void insertList(int &a, int b, int c){
	lists[L] = llist(b,a,c,0);
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


void insertEdge(int a, int b, int c){
	insertList(adj[a], b, c);
	insertList(adj[b], a, 0);
}

char grid[35][35];
int num[35][35];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){
	while( scanf("%d%d%d", &N, &M , &P) > 0){		
		L = 0; FILL(adj, -1);
		int B = N*M;
		S = 0; T = 2*B+1; FN = T+1;		
		int sz =1;
		REP(i,0,N) REP(j,0,M) num[i][j] = sz++;
		REP(i,0,N) scanf("%s", grid[i]);
		REP(i,0,N) REP(j,0,M){			
			if( grid[i][j] == '*'){
				insertEdge( num[i][j], num[i][j]+B, 1);
				insertEdge(S, num[i][j], 1);
			} else if( grid[i][j] == '.'){
				insertEdge( num[i][j], num[i][j]+B, 1);
			} else if( grid[i][j] == '@'){
				insertEdge( num[i][j], num[i][j]+B, INF);
			} else if( grid[i][j] == '#'){
				insertEdge( num[i][j], num[i][j]+B, INF);
				insertEdge( num[i][j] + B, T, P);
			}
			if( grid[i][j] != '~'){
				REP(k,0,4){
					int ni = i + dy[k], nj = j + dx[k];
					if( ni < 0 || ni >= N || nj < 0 || nj >= M || grid[ni][nj] == '~' ) continue;					
					insertEdge( num[i][j]+B, num[ni][nj], INF);
				}
			}
		}
		printf("%d\n", sap());
	}
	return 0;
}