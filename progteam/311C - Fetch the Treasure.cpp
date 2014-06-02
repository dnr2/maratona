//http://codeforces.com/blog/entry/7785
//#tag
//#sol
//things I've learned: 
//1 - when use a priority queue we can use flags to change elements.
//2 - to test if an vector can be generated from the linear combination (discrete numbers) of other vectors,
//and one of the base vectors v is the vector with smallest size, then we can ...

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
#define pii pair<int,int>
#define pll pair<ll,ll>
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
// #define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

#define DOTS 1000000

const int maxn = 100100;
const ll INF = (ll) 4E18;

ll pos[maxn];
ll val[maxn];
ll md[maxn], mdpos;
ll D[maxn];

int main(){
	IOFAST();
	ll h,n,m,k;
	while( cin >> h >> n >> m >> k){		
		mdpos = 0;
		priority_queue<pll> pq;
		REP(j,0,k+1) D[j] = INF;
		D[0] = 0;
		
		REP(i,0,n){ 
			cin >>  pos[i] >>  val[i]; 
			pos[i]--;
			if( pos[i] % k == 0) { pq.push( mp( val[i] , -i)); }
		}
		
		REP(i,0,m){
			ll type; cin >> type;
			if( type == 1){
				ll x; cin >> x;
				md[mdpos++] = x;
				REP(j,0,k+1) D[j] = INF;
				priority_queue<pll> q; q.push(mp(0,0)); D[0] = 0;
				while( !q.empty()){
					ll x = -q.top().F, y = q.top().S; q.pop();
					REP(j,0,mdpos){
						ll ny = (y + md[j])%k;
						ll nx = x + (y + md[j])/k;
						if( nx >= D[ny]  ) continue;
						D[ny] = nx;
						q.push( mp( -nx, ny) );
					}
				}				
				REP(j,0,n){
					if( val[j] > 0 && D[pos[j]%k] <= pos[j]/k ){
					
						pq.push( mp(val[j], -j) );
					}
				}
			} else if( type == 2){
				ll x, y; cin >> x >> y; x--;
				val[x] -= y;
				if( D[pos[x]%k] <= pos[x]/k ){
					pq.push( mp( val[x], -x) );					
				}
			} else if( type == 3){
				while(true){
					if( pq.empty()) { cout << 0 << endl; break; }
					ll a = pq.top().F, b = -pq.top().S; pq.pop();
					if( val[b] == a ) { cout << a << endl; val[b] = 0; break; }
				}
			}
		}
	}
	return 0;
}