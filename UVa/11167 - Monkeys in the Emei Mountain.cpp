//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2108
//#tag network flow
//#sol The straightforward idea is to create m slots for each time stamp and match the
// monkeys against these slots. However there can be at most 250,000 such slots which is too
// many for any matching algorithm. We have to reduce the number of slots. You may Find
// that the slots only need to take care of the timestamps that appear as any ai; bi because
// we can combine the non-appearing timestamps. For example, if t1 and t2 are two adjacent
// timestamps, we know that we can assign monkeys to slot t1 to drink at most (t2 - t1) x m
// units of water. We also needs to pay attention that a monkey cannot drink more than 1 unit
// of water in a single time stamp. This requirement cannot be directly represented by the flow
// graph construction. However, we can get around this problem by assigning the edge capacity
// sourcing from a monkey by t2 - t1. With this construction, if there is a feasible flow, we can
// always Find a feasible drinking assignment because each monkey that drinks in [t1, t2] drinks
// at most t2 - t1 units of water and thus we can always make sure that it does not drink more
// than 1 units of water in a single time stamp. This construction only has about 300 nodes, a
// lot faster.

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
#include <set>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

#define DOTS 160000
typedef vector<int> VI;
typedef pair<int,int> PII;

const int INF = 1E9; // $\infty$: be careful to make this big enough!!!
int S; // source
int T; // sink
int FN; // number of nodes
int FM; // number of edges (initialize this to 0)
// ra[a]: edges connected to a (NO MATTER WHICH WAY!!!); clear this in the beginning
VI ra[500];
int kend[DOTS], cap[DOTS]; // size: TWICE the number of edges

// Adds an edge from a to b with capacity c and returns the number of the new edge
int addedge(int a, int b, int c) {
	int i = 2*FM;
	kend[i] = b;
	cap[i] = c;
	ra[a].push_back(i);
	kend[i+1] = a;
	cap[i+1] = 0;
	ra[b].push_back(i+1);
	FM++;
	return i;
}

///maxflow
bool fou[DOTS];
PII pre[DOTS];
// Returns the maximum flow from the source to the sink
ll solve() { // reinitialize costs if rerun
	ll totflow = 0;
	while(true) {
		memset(fou, 0, sizeof(fou));
		queue<int> qu;
		qu.push(S);
		fou[S] = true;
		while(!qu.empty()) {
			int i = qu.front();
			qu.pop();
			if (i == T)
				break;
			for (int e : ra[i]) {
				int k = kend[e];
				if (cap[e] > 0 && !fou[k]) {
					qu.push(k);
					pre[k] = PII(i,e);
					fou[k] = true;
				}
			}
		}
		if (!fou[T])
			break;
		int mk = INF;
		for (int i = T; i != S; i = pre[i].first)
			mk = min(mk, cap[pre[i].second]);
		totflow += mk;
		for (int i = T; i != S; i = pre[i].first) {
			cap[pre[i].second] -= mk;
			cap[pre[i].second^1] += mk;
		}
	}
	return totflow;
}

int in[200][3];

int main(){
	int n, m, cn = 1;
	while(scanf("%d",&n) > 0 && n){
		scanf("%d",&m);
		FM=0;
		REP(i,0,500) ra[i].clear();
		vector<int> cord;
		int tot = 0;
		REP(i,0,n){
			scanf("%d%d%d", in[i], in[i]+1, in[i]+2);			
			cord.pb( in[i][1]);
			cord.pb( in[i][2]);
			tot += in[i][0];
		}
		sort( cord.begin(), cord.end());
		cord.erase(unique(cord.begin(),cord.end()),cord.end());		
		int sz = ((int)cord.size());		
		map<int,int> rev;		
		REP(i,0,sz){ rev[cord[i]] = i; }
		S = 0, T = 1;
		REP(i,0,n){
			addedge( S , i + 2, in[i][0]);			
			int idx = rev[in[i][1]];
			while( idx < rev[in[i][2]]){
				int weight = cord[idx+1] - cord[idx];
				addedge( i +2 , idx + n + 2,  weight);				
				idx++;
			}
		}
		REP(i,0,sz-1){
			int weight = m * (cord[i+1] - cord[i]);
			addedge( i + n + 2, T, weight);
		}
		int maxf = solve();		
		map<int,int> used;
		vector<PII> resp;
		vector<PII> ugly;
		if( maxf == tot){
			printf("Case %d: Yes\n", cn++);			
			REP(i,2,n+2){
				resp.clear();
				REP(j,0,(int)ra[i].size()){
					if( kend[ra[i][j]] != S){						
						int idx = kend[ra[i][j]]-n-2;
						int remaincap = cap[ra[i][j]];
						int len = cord[idx+1] - cord[idx];						
						int drunk = ( len - remaincap );
						if( drunk == 0 ) continue;
						PII np;
						while( drunk > 0){
							int left = used[cord[idx]], right = min(left+drunk,len);
							np = PII( cord[idx] + left, cord[idx] + right);
							used[cord[idx]] = (right == len)?0:right;							
							drunk -= (right - left);
							resp.pb( np );							
						}						
					}
				}
				sort(resp.begin(), resp.end());
				ugly.clear();
				REP( x, 0, (int)resp.size()){
					int a = resp[x].first, b = resp[x].second;					
					while( x+1 < ((int)resp.size()) && resp[x+1].first == b){
						b = resp[x+1].second;
						x++;
					}
					ugly.pb( PII(a,b));
				}						
				sort(ugly.begin(), ugly.end());
				printf("%d", (int)ugly.size());
				REP( x, 0, (int)ugly.size()){					
					printf(" (%d,%d)", ugly[x].first, ugly[x].second);
				}
				puts("");
			}
		} else {
			printf("Case %d: No\n", cn++);
		}
	}	
	
	return 0;
}
