//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3638
//#tag set 
//#tag ad hoc
//#sol 

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
#include <set>
#include <sstream>
#include <climits>

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
#define INF 0x3f3f3f3f
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 30100;
const int maxm = 510;
int in[maxm][maxn];
int num[maxm];
int mark[maxn];
vector<int> adj[maxn];
int n, m;
set<int> s;

void dfs( int g){
	if( s.find(g) != s.end()) return;
	s.insert( g);
	REP(i,0,num[g]){
		if( mark[in[g][i]] ) continue;
		mark[in[g][i]] = 1;
		REP(j,0,adj[in[g][i]].size()){
			dfs(adj[in[g][i]][j]); 
		}
	}
}

int main(){
	while(scanf("%d%d", &n ,&m) > 0 && (n || m )){		
		memset(mark,0,sizeof(mark));
		s.clear();
		REP(i,0,n) adj[i].clear();
		REP(i,0,m){
			scanf("%d", num+i);
			REP(j,0,num[i]){
				scanf("%d", in[i]+j);
				adj[in[i][j]].pb( i);
			}
		}
		mark[0] = 1;
		REP(i,0,adj[0].size()) dfs( adj[0][i]);
		set<int> students;
		for( set<int>::iterator it = s.begin(); it != s.end(); it++){
			REP(i,0,num[*it]){
				students.insert(in[*it][i]);
			}
		}
		if( students.size() == 0) puts("1");
		else cout << ((int) students.size()) << endl;		
	}
	
	return 0;
}