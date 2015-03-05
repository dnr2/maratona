//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3053
//#tag graph / grafos
//#tag BFS / DFS
//#sol test for each node if it's reachable from the node 0, now for each node x = 0 .. N test if the other nodes can be 
//reached if you remove the node x from the graph. if you can reach the node y from node 0 when you have x in the graph,
//but you cannot reach y when you remove x, then x is a dominator of y.

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
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
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

template <class _T> inline string tostr(const _T& a){ ostringstream 
os(""); os<<a;return os.str(); }

const int MAXN = 200;

int in[MAXN][MAXN];
int mark[MAXN];
int from[MAXN];
int n; 

void bfs(int rem){
	
	queue<int> q;
	mark[0] = 1;
	q.push(0);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if( cur == rem) continue;
		REP(i,0,n){
			if( in[cur][i] == 1 && mark[i] == 0 && i != rem){

				mark[i] = 1;
				q.push( i );
			}
		}
	}
}

char str[2 * MAXN];

int main(){
	int K; cin >> K; int cn = 1;
	while( K--){
		cout << "Case " << (cn++) << ":"  << endl;
		cin >> n;
		str[0] = '+';
		REP(i,1,2*n) str[i] = '-';
		str[2*n] = '+';
		str[2*n+1] = 0;
		puts(str);
		
		REP(i,0,n){
			REP(j,0,n){
				scanf("%d", &in[i][j] );
			}
		}
		
		FILL(from,0);
		queue<int> q;
		from[0] = 1;
		q.push(0);
		while(!q.empty()){
			int cur = q.front(); q.pop();
			REP(i,0,n){
				if( in[cur][i] == 1 && from[i] == 0 ){
					from[i] = 1;
					q.push( i );
				}
			}
		}
		
	
		REP(rem,0,n){
			FILL(mark,0);
			bfs( rem );
			printf("|");
			REP(j,0,n){
				if( (from[j] == 1 && mark[j] == 0) || (from[j] == 1 && rem == j) ){
					printf("Y");
				} else {
					printf("N");
				}
				printf("|");
			}
			puts("");
			puts(str);
		}
	}
	
	return 0;
}