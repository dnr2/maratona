//
//#tag
//#sol

#include<bits/stdc++.h>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define F first
#define S second
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

const int MAXN = 200;

string in[MAXN];
int rem[MAXN];

int main(){
	IOFAST();
	int n,m; cin >> n >> m;
	REP(i,0,n){
		cin >> in[i];
	}
	int resp = 0;
	// DB( n _ m);
	REP(k,0,m){
		string a = "", b = "";
		bool ok = true;
		REP(j,0,m){
			if( !rem[j] ) a += in[0][j];
		}
		REP(i,1,n){
			b = "";
			REP(j,0,m){
				if( !rem[j] ) b += in[i][j];
			}
			// DB( k _ i _ a _ b );
			if( a > b){
				ok = false;
				int x = 0;
				REP(pos,0,m){
					if( rem[pos]) continue;
					if( a[x] > b[x] ) {
						// DB( pos );
						rem[pos] = 1; break;
					}
					x++;
				}
			}
			a = b;
			if( ok == false ) break;
		}
		if(ok){
			break;
		}
		resp++;
	}
	cout << resp << endl;
	return 0;
}
