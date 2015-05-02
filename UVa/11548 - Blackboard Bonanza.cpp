//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2543
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

string in[maxn];

int main(){
	
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		REP(i,0,n){
			cin >> in[i];			
		}
		int resp = 0;
		REP(i,0,n){
			REP(j,i+1,n){			
				REP(kk,0,2){
					REP(off,0,(int)in[i].size()){
						int cont = 0;
						REP(k,0,(int)in[i].size()){					
							if( k + off >= (int) in[j].size()) break;
							if( in[i][k] == in[j][k+off] ) cont++;
						}
						resp = max(resp, cont );
					}
					swap(i,j);
				}
			}
		}
		cout << resp << endl;
	}
	
	return 0;
}