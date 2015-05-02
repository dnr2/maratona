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

const int maxn = 100;

int mat[maxn][maxn];

char format[10];

int main(){
	
	int n; bool pline = false;
	while( cin >> n){
		
		FILL(mat,0);
		int y = 0, x = (n/2);
		int num = 1;
		REP(i,0,n){			
			REP(j,0,n){
				mat[y][x] = num++;
				if( j + 1 == n ) break;
				y--, x++;				
				if( y < 0) y = n-1;
				if( x >= n) x = 0;				
			}
			// DB( i _ y _ x );
			y++;
			if( y >=n ) y = 0;
		}
		
		int sum = 0;
		REP(i,0,n) sum += mat[i][0];
		
		if( pline) puts("");		
		else pline = true;
		printf("n=%d, sum=%d\n", n, sum);
		
		int sz = 0, aux = n * n;
		while( aux > 0){
			sz++; aux /= 10;
		}
		sz++;
		
		
		format[0]= '%';
		sprintf(format+1, "%dd",  sz);
		
		
		REP(i,0,n){
			REP(j,0,n){
				printf( format, mat[i][j]);
			}
			puts("");
		}		
		
	}
	
	return 0;
}