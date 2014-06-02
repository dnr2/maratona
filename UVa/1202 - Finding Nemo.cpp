//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3643
//#tag bfs busca em largura breadth first search	
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
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0);

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct st{
	int x, y , c;
	st( int x=0,int y=0,int c=0): x(x), y(y), c(c) {}
};

const int SIZE = 200;
const int INF = 10000000;
int N,M;
int grid[SIZE][SIZE][4];
int pd[SIZE][SIZE];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(){
	while(scanf("%d%d", &M, &N) > 0 && (M>=0 || N>=0)){
		memset(grid,0,sizeof(grid));
		REP(i,0,SIZE) REP(j,0,SIZE) pd[i][j] = INF;
		REP(i,0,M){
			int x, y, d,t;
			scanf("%d%d%d%d",&x,&y,&d,&t);
			REP(i,0,t){
				if( d == 0) { grid[y][x][2] = grid[y-1][x][0] = 1; x++; }
				else { grid[y][x][3] = grid[y][x-1][1] = 1; y++; }
			}
		}
		REP(i,0,N){
			int x, y, d;
			scanf("%d%d%d",&x,&y,&d);
			if( d == 0) grid[y][x][2] = grid[y-1][x][0] = 2;
			else grid[y][x][3] = grid[y][x-1][1] = 2;
		}
		double f1, f2;
		scanf("%lf%lf", &f1,&f2);
		int tx = (int) f1;
		int ty = (int) f2;
		if( tx > SIZE || ty > SIZE ) { puts("0"); continue; };
		int pos = 0;
		queue<st> q[2];
		q[pos].push( st( 0,0,0));
		pd[0][0] = 0;
		int resp = -1;
		bool end = false;
		while(!end) {
			if( q[pos].empty() ) break;
			while(!q[pos].empty()){
				st cur = q[pos].front(); q[pos].pop();
				if( cur.x == tx && cur.y == ty) {
					resp = cur.c; end = true; break;
				}
				REP(i,0,4){
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];
					// db( i _ cur.x _ cur.y _ cur.c _ grid[cur.y][cur.x][i]);
					if( nx <0 || ny <0 || nx >= SIZE || ny >= SIZE || grid[cur.y][cur.x][i] == 1) continue; 
					int nc = cur.c + ((grid[cur.y][cur.x][i] == 2)?1:0);
					if( nc < pd[ny][nx]){
						pd[ny][nx] = nc;
						int npos = (grid[cur.y][cur.x][i] == 2)?((pos+1)%2):pos;
						q[npos].push( st( nx,ny, nc) );
					}
				}
			}
			pos = (pos+1) % 2;
		}
		printf("%d\n", resp);
	}
	return 0;
}