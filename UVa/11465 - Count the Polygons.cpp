//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2460
//#tag bit mask mascara de bit
//#tag geometry geometria
//#sol usar o método meet in the meedle para reduzir a complexidade de 2^30 para 2^15
// consideramos a fórmula que S - M > M, onde S é a soma dos tamanhos de todos os palitos e M é o
// maior palito dentre o conjunto de palitos escolhidos

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

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
// #define umap unordered_map
#define MAXN 110

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

ll in[MAXN];
pll p1[1<<16+1];
ll p2[33][1<<16+1];
int p2len[33];

bool cmpF(pll a, pll b){
	return a.F < b.F;
}

bool cmpS(pll a, pll b){
	return a.S < b.S;
}

bool cmp( ll a, ll b ) { return a < b ; }
int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t; cin >> t; int caso =1;
	while(t--){
		cl( p1); cl(p2); cl(p2len);
		int n , k;
		scanf("%d%d", &n, &k);
		fr(i,0,n) scanf("%lld", &in[i]);
		sort(in,in+n);
		int n1 = n/2, n2 = n - n1;
		for(int i = 0; i<(1<<n1); i++){
			ll cont = 0; ll num = 0; int lol = i;
			while(lol > 0){
				if(lol&1) {p1[i].S += in[cont]; num++; }
				cont++;
				lol >>= 1;
			}
			p1[i].F = num;
			//db( i _ p1[i].F _ p1[i].S );
		}
		for(int i = 0; i<(1<<n2); i++){
			ll cont = 0; ll maxn = 0; ll num = 0; ll sum = 0; int lol = i;
			while(lol > 0){
				if(lol&1) { sum -= in[n1 + cont]; maxn = max(in[n1+cont], maxn); num++;  }
				cont++;
				lol >>= 1;
			}
			sum += 2 * maxn;
			p2[num][ p2len[num]++ ] = sum;
			//db( i _ num _ sum );
		}
		fr(i,0,n+1){
			sort( p2[i], p2[i] + p2len[i]);
		}
		ll resp = 0;
		for(int i = 0; i<(1<<n1); i++){
			//db( i _ p1[i].F ) ;
			if( k > p1[i].F ) { 
				int q = k - p1[i].F;
				ll pos = lower_bound( p2[q], p2[q] + p2len[q] , p1[i].S) - p2[q]; //low or up?
				//db( i _ q _ pos _ p1[i].S) ;
				resp += pos;
			} else if( p1[i].F == k ) {
				ll cont = 0; ll num = 0; ll bigger = 0; ll lol = i;
				while(lol > 0){
					if(lol&1) { num += in[cont]; bigger = max( bigger, in[cont]); }
					cont++;
					lol >>= 1;
				}
				if( num - bigger > bigger ) resp++;
			}
		}
		printf("Case %d: %lld\n", caso++, resp );
	}
	return 0;
}
