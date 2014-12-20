//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=342&page=show_problem&problem=438
//#tag bfs breadth first search / busca em largura
//#tag dfs depth first search / busca em profundidade
//#tag divisor
//#sol the problems statement is wrong, you should use the usual definition for adjacency (not the unusual one he gives
//in the description). considering this and that m1 is the smallest elements in the grid and m2 is the biggest,
//all the possible jumps are the divisors of m2 - m1. Then for each possible jump run a dfs / bfs to see if it's possible
//to go from m1 to m2. if the value of m1 and m2 are equal, then there is always a way (jump 0).

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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 110;

int in[MAXN][MAXN];
bool mark[MAXN][MAXN];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){
	
	int n, m;
	vector<int> divs;
	while( cin >> n >> m){
		if( n == -1 && m == -1 ) break;
		int m1 = INF, m2 = 0;
		divs.clear();
		REP(i,0,n) REP(j,0,m){
			scanf("%d", in[i] + j);
			m1 = min(m1, in[i][j] );
			m2 = max(m2, in[i][j] );
		}		
		if( m2 - m1  == 0){
			cout << "At least one pattern exists." << endl;
			continue;
		}
		int dif = m2 - m1;
		REP(i,1,dif+1){
			if( dif % i == 0){
				divs.PB( i );
			}
		}
		bool ok = false;
		REP(i,0,(int) divs.size()){
			int jump = divs[i];
			queue<PII> q;
			FILL( mark, false);
			REP(i,0,n) REP(j,0,m) {
				if( in[i][j] == m1 ){
					q.push( PII( i, j));
					mark[i][j] = true;
				}
			}
			while( !q.empty()){
				int y = q.front().FT, x = q.front().SD;
				q.pop();
				if( in[y][x] == m2 ) {					
					ok = true; goto end;
				}
				REP(k,0,4){
					int ni = y + dy[k];
					int nj = x + dx[k];
					if( ni < 0 || ni >= n || nj  < 0 || nj >= m || in[ni][nj] - in[y][x] != jump || mark[ni][nj] ) continue;
					mark[ni][nj] = true;
					q.push( PII( ni, nj));
				}
			}
		}
		end:
		if( ok ) cout << "At least one pattern exists." << endl;
		else cout << "No pattern can be found." << endl;
		
	}
	
	return 0;
}