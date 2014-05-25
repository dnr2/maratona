//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2153
//#tag map hash
//#tag bfs busca em largura
//#tag bidirectional search 
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
#include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
#define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

ll swapfront(ll mask, ll a, ll b){
	ll ret = 0LL;
	a <<= 2LL; b <<= 2LL;
	ret |= (mask & ((1LL<<b)-1LL)) >> a;
	ret |= (mask & ((1LL<<a)-1LL)) << (b-a);
	ret |= (mask >> b) << (b);
	return ret;
}

int main(){
	int n, cn = 1;
	while(scanf("%d", &n) > 0 && n) {
		ll s = 0, e =0;
		REP(i,0,n){
			ll a; scanf("%lld", &a);
			s |= (a <<(i*4));
			e |= ((i+1) <<(i*4));
		}
		
		umap<ll,int> mapa[2];
		queue<ll> q[2];
		q[0].push(s);
		q[1].push(e);
		mapa[0][s] = mapa[1][e] = 1;		
		int resp =0;
		if( s == e) goto end;
		REP(dist,1,10){
			REP(it,0,2){			
				while( mapa[it][q[it].front()] == dist){
					ll cur = q[it].front(); q[it].pop();
					REP(i,0,n){
						REP(j,i,n){
							ll next = swapfront(cur, i,j+1);			
							int cont =-4;						
							REP(k,j-i,n){
								if( cont >= 0){
									ll tmp2 = swapfront( next >> cont , j-i+1, j-i+2) << cont;
									ll tmp = (next & ((1LL<<(cont))-1LL)) | tmp2;
									next = tmp;
								}						
								cont+=4;
								if( mapa[it][next] == 0){								
									mapa[it][next] = mapa[it][cur] + 1;
									if( (mapa[0][next] > 0 && mapa[1][next] > 0) || (it==0 && next == e) || (it==1 && next == s)){
										resp = mapa[0][next] + mapa[1][next] -2;
										goto end;
									}
									q[it].push( next );
								}							
							}
						}
					}
					
				}
			}
		}
		end:
		printf("Case %d: %d\n", cn++, resp);
	}	
	return 0;
}