//
//#tag
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

const int maxn = 1000;

int cp[10][2];
int checkpos[10];
const ull ONE = 1ULL;

struct st{
	ull mask; 
	int y, x;
	st (ull mask = 0, int y = 0, int x = 0) : mask(mask), y(y), x(x) {}
		bool operator < ( const st & in ) const {
		if( mask == in.mask && y == in.y ) return x < in.x;
		if( mask == in.mask) return y < in.y;
		return mask < in.mask;
	}
};

set<st> endst[2];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int n, m; 
char aux[20];

string DB_bits(ull x){
	string ret;
	REP(i,0,n*m){		
		if( i % m == 0) ret += "\n";
		ret += (x & 1ULL) + '0';
		x >>= 1;
	}
	ret += "\n";
	return ret;
}

ull fmask, cmask;

bool reachable(ull ma, int y, int x){
	queue<PII> fila;
	ma =  ma | (ONE << (y * m + x));
	fila.push( PII(y,x) );	
	while( !fila.empty()){
		PII cur = fila.front(); fila.pop();
		y = cur.FT, x = cur.SD;		
		if( ma == cmask ) return true;
		REP(i,0,4){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if( ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if( ma & (ONE << (ny * m + nx))) continue;
			ma =  ma | (ONE << (ny * m + nx));
			fila.push( PII(ny,nx) );
		}
	}
	return false;
}

int bfsdist[20][20];

int getdist(ull ma, int y, int x, int ty, int tx){
	queue<PII> fila;
	ma =  ma | (ONE << (y * m + x));
	fila.push( PII(y,x) );	
	FILL(bfsdist,0);
	bfsdist[y][x] = 0;
	while( !fila.empty()){
		PII cur = fila.front(); fila.pop();
		y = cur.FT, x = cur.SD;	
		// DB( y _ x _ ty _ tx _ bfsdist[y][x] );
		if( y == ty && x == tx ) return bfsdist[y][x];
		REP(i,0,4){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if( ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if( ma & (ONE << (ny * m + nx))) continue;
			ma =  ma | (ONE << (ny * m + nx));
			bfsdist[ny][nx] = bfsdist[y][x] + 1;			
			fila.push( PII(ny,nx) );
		}
	}
	return INF;
}

ull lolmask;

bool used( int x, int y){
	return ( (lolmask & (ONE << (y * m + x))) > 0);
}

bool divid2(ull mask , int x, int y) {
    static int v[9], i, j;	
	lolmask = mask;
    v[0] = x-1 < 0 || y-1 < 0 || used(x-1,y-1);
    v[1] = x-1 < 0 || used(x-1,y);
    v[2] = x-1 < 0 || y+1 >= n || used(x-1,y+1);
    v[3] = y+1 >= n || used(x,y+1);
    v[4] = x+1 >= m || y+1 >= n || used(x+1,y+1);
    v[5] = x+1 >= m || used(x+1,y);
    v[6] = x+1 >= m || y-1 < 0 || used(x+1,y-1);
    v[7] = y-1 < 0 || used(x,y-1);
    v[8] = v[0];
    for(i = 0, j = 0; i < 8; i++){
		// DB( i _ v[i] _ v[i+1]);
        if(v[i] != v[i+1])
            j++;
	}
    return j >= 4;
}

int countbits( ull mm ){
	int ret = 0;
	while( mm > 0) {
		ret += mm & 1;
		mm >>= 1;
	}
	return ret;
}

int main(){
	
	int cn = 1;
	while(cin >> n >> m){
		
		if( !(n||m) ) break;
		// DB( n _ m );
		REP(i,0,3) REP(j,0,2) cin >> cp[i+1][j] ;
		cp[0][0]= 0, cp[0][1] = 0;
		cp[4][0]= 0, cp[4][1] = 1;
		REP(i,1,4) checkpos[i] = (i*n*m)/4;
		checkpos[0] = 1, checkpos[4] = n*m;
		queue<st> fila[2];		
		st bb = st( 1<<0, 0, 0 ), ee = st( 1<<1, 0, 1 );
		fila[0].push( bb );	fila[1].push( ee );
		map<st,int> dep[2];
		dep[0][bb] = 1; dep[1][ee] = n*m;
		map<st,ll> ways[2];
		ways[0][bb] = 1; ways[1][ee] = 1;
		
		fmask = ( ONE << (cp[2][0] * m + cp[2][1] ));
		cmask = (( ONE << (m*n-1))-1) | ( ONE << (m*n-1));
		// DB( "->" _ fmask _ DB_bits(fmask) );
		// DB( "-> -> " _ cmask _ DB_bits(cmask) );		
		
		//TODO case when n = 2 && m = 2, or when final state is on 3th checkpoint		
		// REP(i,0,5) DB( i _ cp[i][0] _ cp[i][1] _ checkpos[i]);
		REP(kk,0,2){
			endst[kk].clear();
			int stcont = 0;
			while( !fila[kk].empty()){
				st cur = fila[kk].front(); fila[kk].pop();
				if( (int) dep[kk][cur] == checkpos[2]){
					endst[kk].insert( cur );
					// DB( cur.mask _ DB_bits(cur.mask ) );
					continue;
				}
				int cdep = dep[kk][cur];
				ll cways = ways[kk][cur];
				stcont++;
				// DB( kk _ cur.y _ cur.x _ cur.mask _ cdep);
				// DB( cur.mask _ DB_bits(cur.mask ) );
				REP(i,0,4){
					int ny = cur.y + dy[i];
					int nx = cur.x + dx[i];
					if( ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
					if( cur.mask & (ONE << (ny * m + nx))) continue;
					
					
					
					int ndep = cdep + ((kk==0)?1:-1); 
					bool ok = true;			
					REP(j,0,5){
						if( ( ndep == checkpos[j] && (ny != cp[j][0] || nx != cp[j][1]) ) ||
							( ndep != checkpos[j] && (ny == cp[j][0] && nx == cp[j][1]) ) ) {
							ok = false; break;
						}
					}					
					if( !ok ) continue;
					
					ull nmask = cur.mask | (ONE << (ny * m + nx));
					
					ok = true;
					REP(j,0,5){
						if( kk == 0 && j > 0 && ndep >= checkpos[j-1] && ndep < checkpos[j] ){
							int gdist = abs( ny - cp[j][0]) + abs( nx - cp[j][1] );							
							// int gdist = getdist( nmask, ny, nx, cp[j][0], cp[j][1]);														
							if( gdist > checkpos[j] - ndep ) { ok = false; break; }
						}
						if( kk == 1 && j > 0 &&  ndep > checkpos[j-1] && ndep <= checkpos[j] ){
							int gdist = abs( ny - cp[j-1][0]) + abs( nx - cp[j-1][1] );
							// int gdist = getdist( nmask, ny, nx, cp[j-1][0], cp[j-1][1]);
							if( gdist > ndep - checkpos[j-1] ) { ok = false; break; }
						}
					}
					if( !ok ) continue;
					
					if( divid2(cur.mask, nx, ny) ){
						continue;
					}
					
					
					// if( kk == 0 && !reachable( nmask, 0, 1) ) continue;					
					// if( kk == 1 && !reachable( nmask, 0, 0) ) continue;															
					
					st ncur( nmask, ny, nx );
					if( dep[kk].count( ncur ) > 0){
						ways[kk][ncur] += cways;
						continue;
					}
					ways[kk][ncur] = cways;
					dep[kk][ncur] = ndep;
					fila[kk].push(ncur);
				}
			}
			// DB( kk _ stcont );
		}
		ll resp = 0;		
		
		// DB( endst[0].size() _ endst[1].size() );
		// REP(i,0,(int) endst[0].size()){
		for( set<st>::iterator it = endst[0].begin(); it != endst[0].end(); it++){	
			st a = *it;
			st b(  ((~a.mask) & cmask) ^ fmask, a.y, a.x );
			// if( ((~( a.mask  ^ b.mask )) & cmask) == fmask ){
			if( endst[1].count( b ) > 0){
				// DB( a.mask _ DB_bits(a.mask) );
				// DB( b.mask _ DB_bits(b.mask) );
				// DB( ways[0][a] _ ways[1][b] );
				resp += ways[0][a] * ways[1][b];
			}			
		}
		cout << "Case " << (cn++) << ": " << resp << endl;
	}
	
	
	return 0;
}