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
#define DB(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 2010;
const ll mod = 1000000007ll;
ll invm2 = 0;

int in[MAXN][MAXN];
ll up[MAXN][MAXN];

struct st{
	ll h, w, hs, as;
	st( ll h = 0, ll w = 0, ll hs = 0, ll as = 0) : h(h), w(w), hs(hs), as(as) {}
};

st pilha[MAXN];

ll comb(ll x){
	return ((((x * (x+1))) % mod) * invm2) % mod; // TODO inverse multiplicative of 2
}

ll powmod( ll a, ll b){
	ll e = a, r = 1;
	for(ll i = 0; (1ll << i) <= b; i++){
		if( b & (1ll << i)) r = (r * e) % mod;
		e = (e*e)% mod;
	}
	return r;
}

int main(){
		
	int n, m; 
	invm2 = powmod( 2, mod - 2);		
	while( cin  >> n >> m){
		REP(i,0,m){
			int a, b; scanf("%d%d", &a,&b);
			a--; b--;
			in[a][b] = 1;
		}
		ll resp = 0;
		REP(kk,0,2){
			if( kk == 1 ) REP(i,0,n) REP(j,0,n) in[i][j] ^= 1;
			REP(j,0,n){ //TODO maybe too slow, use i first then j
				ll sum = 0;
				REP(i,0,n){
					if( in[i][j] == 1) sum = 0;
					else sum++;
					up[i][j] = sum;					
				}
			}
			
			REP(i,0,n){
				ll ppos = 0;
				REP(j,0,n){
					ll aux = up[i][j];
					pilha[ppos++] = st( aux, 1, comb(aux) , comb( aux) ) ;
					if( in[i][j] == 1) ppos = 0; 
					while( ppos > 1 && pilha[ppos-2].h >= pilha[ppos-1].h ){
						st cur = pilha[ppos-1];
						st back = pilha[ppos-2];
						pilha[ppos-2] = st( cur.h , (cur.w + back.w ) % mod, 0, 0);
						ppos--;
					}					
					if( ppos == 1){
						st & cur = pilha[ppos-1];
						cur.hs = (cur.w * comb( cur.h )) % mod;
						cur.as = (comb(cur.w) * comb( cur.h)) % mod;
					} else if( ppos > 1 ){					
						st & cur = pilha[ppos-1];
						st back = pilha[ppos-2];
						cur.hs = (back.hs + ((cur.w * comb( cur.h )) % mod )) % mod;
						cur.as = ((comb(cur.w) * comb( cur.h)) % mod + (( back.as + ((cur.w * back.hs )%mod ) ) %mod) ) %mod;
					}					
					if( ppos > 0){
						st cur = pilha[ppos-1];												
						resp = (resp + cur.as) % mod; // TODO make module
					}
				}
			}
		}
		cout << (resp % mod) << endl;
	}
	return 0;
}