//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=926
//#tag BFS
//#sol add to the BFS state (the postiion) also time mod 4

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

const int maxn = 600;

int in[maxn][maxn];
int mark[4][maxn][maxn];
char str[100];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};


int main(){
	
	int n, m;
	while(scanf("%d%d", &n, &m) > 0){
		REP(i,0,n){
			REP(j,0,m){
				if( i == n-1 && j == m-1) continue;
				in[i][j] = 0;
				scanf("%s", str);
				int sz = strlen( str );
				REP(kk,0,sz){
					if( str[kk] == 'N') in[i][j] |= 1 << 1;
					if( str[kk] == 'E') in[i][j] |= 1 << 2;
					if( str[kk] == 'S') in[i][j] |= 1 << 3;
					if( str[kk] == 'W') in[i][j] |= 1 << 4;
				}
			}
		}
		FILL(mark,INF);
		queue< pair< PII ,int > > fila;
		fila.push( MP( PII(0,0) , 0 ));
		mark[0][0][0] = 0;
		int resp = -1;
		while( !fila.empty()){
			PII pos = fila.front().FT; int dir = fila.front().SD;
			int y = pos.FT, x = pos.SD;
			fila.pop();
			if( y == n -1 && x == m - 1 ){
				resp = mark[dir][y][x]; break;
			}
			REP(i,0,4){
				int aux = (((i-dir) + 4) % 4) + 1;
				if( ((1<<aux) & in[y][x]) == 0) continue;
				int ny = y+ dy[i], nx = x+dx[i], ndir = (dir + 1) % 4;
				if( ny < 0 || ny >= n || nx <0 || nx >= m || mark[ndir][ny][nx] < INF) continue;
				mark[ndir][ny][nx] = mark[dir][y][x] + 1;
				fila.push( MP( PII( ny,nx), ndir ) );
			}
		}
		if( resp == -1){
			cout << "no path to exit" << endl;
		} else {
			cout << resp << endl;
		}
	}
	return 0;
}