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

const int maxn = 11000;

int tran[][5] = { {0,0,0,0,0}, 
				  {0,1,2,3,4}, 
				  {0,2,-1,4,-3}, 
				  {0,3,-4,-1,2}, 
				  {0,4,3,-2,-1} };
				  
int comb[maxn][maxn];
int mapa[250];

int main(){
	
	int T; cin >> T;
	mapa['i'] = 2;
	mapa['j'] = 3;
	mapa['k'] = 4;
	
	REP(cn,1,T+1){
		int n, m; cin >> n >> m;
		string s, str = ""; 
		cin >> s; 
		REP(i,0,m){
			str += s;
		}
		n *= m;
		bool ok = false;
		// DB( str );
		REP(i,0,n){
			comb[i][i] = mapa[(int)str[i]];
			// DB( i _ i _ comb[i][i] );
			REP(j,i+1,n){
				comb[i][j] = tran[abs(comb[i][j-1])][mapa[(int)str[j]]];
				if( comb[i][j-1] < 0 ) comb[i][j] *= -1;
				// DB( j _ j _ comb[i][j] );
			}
		}
		REP(i,1,n){			
			REP(j,i+1,n){
				if( comb[0][i-1] == 2 && 
					comb[i][j-1] == 3 && 
					comb[j][n-1] == 4 ){
					//DB( str _ i _ j );
					ok = true; goto goans;
				}
			}
		}
		goans :
		printf("Case #%d: ", (int)cn);
		if( ok ) puts("YES");
		else puts("NO");
	}
	
	return 0;
}