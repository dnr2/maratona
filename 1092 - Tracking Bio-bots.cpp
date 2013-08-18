#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) if(1) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long
#define PI acos(-1)
#define EPS 1e-9

using namespace std;

struct st{
	int x1,x2,y;
};

st in[1110];
int y[2110];
int x[2110];
int py, px;
int cx, cy;
ll contx[4110], conty[4110];
int grid[4110][4110], passo= 1;

int main(){
	
	int caso = 1, n,m,w;
	int a,b,c,d;
	while(scanf("%d%d%d", &m,&n,&w) > 0 && (n || m ||w)){
		cx = cy = py = px = 0; 
		map<ll,ll> mapx, mapy;
		if( w== 0){ printf("Case %d: %d\n", caso++, 0); continue; }
		fr(i,0,w){
			scanf("%d%d%d%d", &a,&b,&c,&d);
			y[py++] = b; x[px++] =a; x[px++] =c;
			in[i].x1 = a; in[i].x2 = c; in[i].y = b; 
		}
		
		
		x[px++] = -1; x[px++] = n; y[py++] = -1; y[py++] = m;
		
		sort( x, x+px);
		sort( y, y+py);
		px = unique( x, x+px) - x;
		py = unique( y, y+py) - y;	
		//fr(i,0,px) db(x[i]);
		fr(i,1,px) {
			if( i > 0 && x[i-1] < (x[i]-1) ) {	// not wall
				contx[cx] = x[i] - x[i-1] -1;
				cx++;
			}
			if( x[i] == n) continue;
			contx[cx] = (i&1==0)? (x[i] - x[i-1]): 1;
			mapx[x[i]] = cx++;
		}
		fr(i,1,py) {
			if( i > 0 && y[i-1] < (y[i]-1) ) {	// not wall
				conty[cy] = y[i] - y[i-1] -1;
				cy++;
			}
			if( y[i] == m) continue;
			conty[cy] = (i&1==0)? (y[i] - y[i-1]): 1;
			mapy[y[i]] = cy++;
		}		
  		fr(i,0,w){
			int lol = mapx[in[i].x2], aux = mapy[ in[i].y];
			for( int j = mapx[in[i].x1] ; j <= lol; j++){
				//db( aux _ j);
				grid[ aux ][j] = passo;
			}
		}
		fr(i,0,cx) grid[cy][i] = passo; 
		fr(i,0,cy-1) grid[i][cx] = passo;
		//for(int i = cy; i >= 0; i--){
		//	fr(j,0,cx+1) cout << grid[i][j];  
		//	cout << endl;
		//}
		ll resp = 0;
		for(int j = cx-1; j>=0; j--){
			for(int i = cy-1; i>= 0; i--){
				if( grid[i][j] != passo && grid[i+1][j] == passo && grid[i][j+1] == passo){
					grid[i][j] = passo; 
					resp += contx[j] * conty[i]; 
					
				}
			}
		}
		//cout << endl;
		//for(int i = cy; i >= 0; i--){ fr(j,0,cx+1) cout << grid[i][j] ;  cout << endl; }
		passo++;
		printf("Case %d: %lld\n", caso++, resp);
	}
	return 0;
}
