//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3712
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

const int maxn = 40;

char in[2][maxn][maxn];
char draw[maxn][maxn];

int main(){
	
	int n,m;
	while(cin >> n >> m){
		if(!(n||m)) break;		

		FILL(in,0);
		
		REP(i,0,n){
			scanf("%s", in[0][i+m]+m );
			
		}		
		
		REP(i,0,m){
			scanf("%s", in[1][i] );
		}
		
		REP(i,0,m+n){
			REP(j,0,m+n){
				REP(kk,0,2){
					if( in[kk][i][j] != '*' && in[kk][i][j] != '.'){
						in[kk][i][j] = '.';
					}
				}
			}
		}
		
		bool printed = false;
		
		FILL(draw,0);
		
		REP(x,0,n+m){
			REP(y,0,n+m){
				REP(z,0,n+m){
					REP(w,0,n+m){
						
						REP(i,0,n+m){
							REP(j,0,n+m){
								draw[i][j] = '.';
							}
						}
						
						bool ok = true;
						REP(i,0,m){
							REP(j,0,m){
								if( draw[i+x][j+y] == '*' && in[1][i][j] == '*'){
									ok = false; goto proximo;
								}
								if( draw[i+x][j+y] != '*'){
									draw[i+x][j+y] = in[1][i][j];
								}
							}
							
						}

						
						REP(i,0,m){
							REP(j,0,m){
								if( draw[i+z][j+w] == '*' && in[1][i][j] == '*'){
									ok = false; goto proximo;
								}
								if( draw[i+z][j+w] != '*'){
									draw[i+z][j+w] = in[1][i][j];
								}
							}
						}
						
						REP(i,0,n+m){
							REP(j,0,n+m){
								
								if( in[0][i][j] != draw[i][j] ){
									ok = false; goto proximo;
								}
							}
						}
						
						proximo:
						if( ok ){
							puts("1"); 
							printed = true;
							goto fim;
						}
					}
				}
			}
		}
		
		fim:
		
		if( !printed) puts("0");
		
	}
	
	return 0;
}