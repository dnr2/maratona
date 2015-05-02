//
//#tag
//#sol

#include <bits/stdc++.h>


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

const int maxn = 27;

char grid[maxn][maxn];
int dist[maxn][maxn][10][10];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

struct st{
	int dir, y, x, cor;
	st( int y = 0, int x = 0, int dir = 0, int cor = 0 ) 
		: dir(dir) , y(y), x(x), cor(cor) {}
};

int main(){
	
	int n, m;
	int cn = 1; 
	while(cin >> n >> m){
		if( !(n||m)) break;
		PII ini, end;
		REP(i,0,n){
			scanf("%s", grid[i]);		
			REP(j,0,m){					
				if( grid[i][j] == 'S' ) ini = PII( i, j );
				if( grid[i][j] == 'T' ) end = PII( i, j );
			}			
		}	
		// DB( ini.FT _ ini.SD);
		// DB( end.FT _ end.SD);
		FILL(dist,INF);
		dist[ini.FT][ini.SD][0][0] = 0;
		queue< st > fila;
		fila.push( st( ini.FT, ini.SD, 0, 0  ) );
		int resp = -1;
		while( !fila.empty()){
			st cur = fila.front(); fila.pop();
			if (cur.y == end.FT && cur.x == end.SD && cur.cor == 0 ){
				resp = dist[cur.y][cur.x][cur.dir][cur.cor]; break;
			}
			// int aux = dist[cur.y][cur.x][cur.dir];
			// DB( cur.y _ cur.x _ cur.dir _ aux);
			
			int kk = cur.dir;
			int ny = cur.y + dy[kk];
			int nx = cur.x + dx[kk];
			int ncor = (cur.cor + 1) % 5;
			if( !(ny < 0 || ny >= n || nx < 0 || nx >= m 
				|| (grid[ny][nx] == '#') )){
				if( dist[ny][nx][cur.dir][ncor] == INF ){
					dist[ny][nx][cur.dir][ncor] = 
						dist[cur.y][cur.x][cur.dir][cur.cor] + 1;
					fila.push( st( ny, nx, cur.dir , ncor ));
				}
			}
			
			REP(k,-1,1+1){				
				if( k == 0 ) continue;
				int ndir = cur.dir + k;
				ndir = ((ndir + 4 ) % 4 );
				int ny = cur.y, nx = cur.x;				
				int ncor = cur.cor;
				//TODO copy
				if( dist[ny][nx][ndir][ncor] == INF ){
					dist[ny][nx][ndir][ncor] = 
						dist[cur.y][cur.x][cur.dir][cur.cor] + 1;
					fila.push( st( ny, nx, ndir, ncor ));
				}
			}
		}
		
		if( cn > 1 ) puts("");
		if( resp == -1 ) printf("Case #%d\ndestination not reachable\n",cn );
		else printf("Case #%d\nminimum time = %d sec\n",cn, resp);
		cn++;
	}
	
	
	return 0;
}