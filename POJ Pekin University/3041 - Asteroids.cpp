//http://poj.org/problem?id=3041
//#tag graph grafos
//#tag bipartite matching emparelhamento
//#sol We construct a bipartite graph with n nodes on the left and n nodes on the
// right, representing the rows and columns respectively. If there is a grid (x; y) to be covered,
// we add an edge from the x-th row to the y-the column, meaning that either the x-th row or
// the y-th column shall be selected. Then the question turns out to be the MVC of a bipartite
// graph, which is equivalent to the MCBM.

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
#define F first
#define S second
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

#define DOTS 10000
#define VI vector<int> 
///bimatch-hk
const int INF = 1E9;
int N1, N2; // Number of nodes in $M_1$ and $M_2$
VI ad1[DOTS]; // ad1[a]: Nodes in $M_2$ that are connected to $a\in M_1$
int ni1[DOTS]; // The node in $M_2$ that is matched to $a\in M_1$; -1 if unmatched
int ni2[DOTS]; // The node in $M_1$ that is matched to $a\in M_2$; -1 if unmatched
int dst[DOTS];

bool bfs(){
	queue<int> que;
	REP(i,0,N1){
		if(ni1[i]==-1) { dst[i]=0; que.push(i); }
		else dst[i] = INF;
	}
	int maxdst = INF;
	while(!que.empty()){
		int x = que.front(); que.pop();
		if(dst[x]==maxdst) continue;
		REP(yy,0,(int)ad1[x].size()) {
			int y = ad1[x][yy];
			if(ni2[y]==-1){
				maxdst = dst[x];
			}else if(dst[ni2[y]]==INF){
				dst[ni2[y]] = dst[x]+1;
				que.push(ni2[y]);
			}
		}
	}
	return maxdst < INF;
}
bool dfs(int x){
	REP(yy,0,(int)ad1[x].size()){
		int y = ad1[x][yy];
		if(ni2[y]==-1 || (dst[ni2[y]]==dst[x]+1 && dfs(ni2[y]))){
			ni1[x] = y;
			ni2[y] = x;
			return true;
		}
	}
	dst[x] = INF;
	return false;
}
int solve(){
	REP(i,0,N1) ni1[i] = -1;
	REP(i,0,N2) ni2[i] = -1;
	int ans = 0;
	while(bfs()){
		REP(i,0,N1) if(ni1[i]==-1) ans += dfs(i);
	}
	return ans;
}

int main(){
	int N, K; cin >> N >> K;
	N1 = N2 = N;
	REP(i,0,K){
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		ad1[a].pb(b);
	}
	cout << solve() << endl;
	return 0;
}