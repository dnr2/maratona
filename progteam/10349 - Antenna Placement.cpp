//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1290
//#tag graph grafos
//#tag bipartite matching emparelhamento
//#sol Split the grids into two like a chess board. Then the job is to match the white
// grids against the nearby black grids where the grid has the '*'. Each pair of matching needs one rectangle. 
// The rest requires one rectangle each. Therefore the goal is to maximize the matching, which is a
// typical bipartite matching instance.

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

const int MAXN = 100;

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
		for (int y : ad1[x]) {
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
	for (int y : ad1[x]) {
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

char str[100][100];

int main(){
	
	int T; cin >> T;
	while(T--){
		REP(i,0,DOTS) ad1[i].clear();
		int n,m; cin >> n >> m;
		REP(i,0,n) {
			scanf("%s", str[i]);
		}
		int x = 0;
		N1 = N2 = 0;
		map<int,int> mapa;
		REP(i,0,n) REP(j,0,m){
			if( str[i][j] == '*'){
				x++;
				if( (i + j) & 1 ){
					mapa[i*m+j] = N1++;		
					if( i > 0 && str[i-1][j] =='*' ) ad1[mapa[i*m+j]].pb(mapa[(i-1)*m+j]);
					if( j > 0 && str[i][j-1] =='*' ) ad1[mapa[i*m+j]].pb(mapa[i*m+(j-1)]);
				} else {					
					mapa[i*m+j] = N2++;
					if( i > 0 && str[i-1][j] =='*' ) ad1[mapa[(i-1)*m+j]].pb(mapa[i*m+j]);
					if( j > 0 && str[i][j-1] =='*' ) ad1[mapa[i*m+(j-1)]].pb(mapa[i*m+j]);
				}				
			}
		}
		int y = solve();
		cout << (x - y) << endl;
	}
	
	return 0;
}