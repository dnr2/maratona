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
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(ll (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 100010;

ll in[MAXN];
list<ll> resp[MAXN];

bool cmp( ll a, ll b){
	if( (a&1) == (b&1)) return a < b;
	return (a&1) < (b&1);
}

int main(){
	IOFAST();
	ll n, k, p;
	while(cin >> n >> k >> p){		
		REP(i,0,k) resp[i].clear();
		REP(i,0,n){
			cin >> in[i];
		}
		sort( in, in+n, cmp);
		REP(i,0,n) db( i _ in[i] _ (in[i]&1));
		ll pos = 0;
		string ans = "YES";
		REP(i,0,k){
			if( i < p){
				if( (in[pos]&1) == 0){
					if( pos < n) resp[i].pb( in[pos++] );
					else ans = "NO";
				} else {
					if( pos+1 < n){
						resp[i].pb( in[pos++] );
						resp[i].pb( in[pos++] );
					} else ans = "NO";
				}
			} else {
				while( pos < n && (in[pos]&1) == 0 ){
					resp[i].pb( in[pos++] );
				}
				if( pos < n){
					resp[i].pb( in[pos++] );
				} else ans = "NO";	
			}
			if( ans == "NO") break;
		}		
		if( ans == "YES"){
			while( pos + 1 < n){
				resp[0].pb( in[pos++] );
				resp[0].pb( in[pos++] );
			}
		}
		if( pos < n) ans = "NO";
		cout << ans << endl;
		if( ans == "YES"){
			REP(i,0,k){
				cout << resp[i].size();
				for(list<ll>::iterator it = resp[i].begin(); it != resp[i].end(); it++){
					cout << " " << (*it);
				}
				cout << endl;
			}
		}
	}
	return 0;
}