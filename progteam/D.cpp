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
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
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

ll a[MAXN], b[MAXN];

int main(){	
	IOFAST();
	ll n,m;
	while(cin >> n >> m){
		REP(i,0,n) cin >> a[i];
		REP(i,0,m) cin >> b[i];
		sort( a, a+n);
		sort( b, b+m, greater<ll>());
		ll mini = a[0];
		ll maxi = b[0];
		ll posa= 0, posb =0;
		ll resp = 0, steps;
		while( mini < maxi){
			while(posa < n && a[posa] <= mini) posa++;
			while(posb < m && b[posb] >= maxi) posb++;
			steps = 1e10;
			if( posa < posb){
				if( posa < n){
					steps = abs(a[posa] - a[posa-1]);
				}
				steps = min( steps, abs(  maxi - mini));
				resp += steps * posa;
				mini += steps;
			} else {
				if( posb < m){
					steps = abs(b[posb] - b[posb-1]);
				}
				steps = min( steps, abs(  maxi - mini));				
				resp += steps * posb;
				maxi -= steps;	
			}
		}
		cout << resp << endl;
	}
	return 0;
}