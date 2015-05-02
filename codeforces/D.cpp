#include<bits/stdc++.h>

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

const int maxn = 210;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
char in[maxn][maxn];
char out[maxn][maxn];
char tmp[maxn][maxn];

int main(){
	
	int n; cin >> n;
	REP(i,0,n){
		scanf("%s", in[i]);
	}
	FILL(out,'.');
	out[n-1][n-1] = 'o';
	
	int m = 2*n-1;
	
	REP(i,0,m){
		REP(j,0,m){
			if( i == n-1 && j == n-1 ) continue;
			char move = 'x'; int c1 = 0;
			REP(y,0,n){
				REP(x,0,n){
					if( in[y][x] == 'o'){						
						int ny = y + (i-(n-1));
						int nx = x + (j-(n-1));
						if( ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
						c1++;
						if( in[ny][nx] == '.'){
							move = '.'; goto proximo;
						}					
					}
				}
			}			
			if( c1 == 0) move = '.';
			proximo:
			out[i][j] = move;
		}
	}
	
	FILL(tmp,'.');
	
	REP(i,0,m){
		REP(j,0,m){
			if( i == n-1 && j == n-1 ) continue;
			if( out[i][j] == 'x'){
				REP(y,0,n){
					REP(x,0,n){
						if( in[y][x] == 'o'){
							int ny = y + (i-(n-1));
							int nx = x + (j-(n-1));
							if( ny < 0 || nx < 0 || ny >= n || nx >= n) continue;							
							tmp[ny][nx] = 'x'; 							
						}
					}
				}
			}			
		}
	}
	
	REP(i,0,n){
		REP(j,0,n){
			if( (tmp[i][j] == 'x' && in[i][j] == '.') || 
				(tmp[i][j] == '.' && in[i][j] == 'x') ){
					
				puts("NO"); return 0;
			}
		}
	}
	puts("YES");
	REP(i,0,m){
		REP(j,0,m){
			printf("%c", out[i][j]);
		}
		puts("");
	}
	
	return 0;
}

