//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=168
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

const int maxn = 1000;

char in[maxn][maxn];

int dx[] = {1,0};
int dy[] = {0,1};

int main(){
	
	int n, m, cn = 1;
	int fline = 1;
	while( cin >> n && n ){
		cin >> m;
		
		REP(i,0,n){
			REP(j,0,m){
				cin >> in[i][j];
			}
		}
		
		if( !fline) puts("");
		else fline = 0;
		
		printf("puzzle #%d:\n", cn++);
		
		REP(kk,0,2){
			if( kk == 0 ) puts("Across");
			else puts("Down");
			int cont = 0;			
			REP(i,0,n){
				REP(j,0,m){					
					REP(nkk,0,2){
						if( in[i][j] != '*' && (i-dy[nkk] < 0 || 
							j-dx[nkk] < 0 || in[i-dy[nkk]][j-dx[nkk]] == '*') ){							
							cont++; break;						
						}
					}
					if( in[i][j] != '*' && (i-dy[kk] < 0 || j-dx[kk] < 0 || in[i-dy[kk]][j-dx[kk]] == '*') ){
						printf("%3d.", cont);						
						int ni = i, nj = j;
						while( ni < n && nj < m && in[ni][nj] != '*'){
							cout << in[ni][nj];
							ni += dy[kk];
							nj += dx[kk];
						}
						cout << endl;
					}
				}
			}
		}
	}
	return 0;
}