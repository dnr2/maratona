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

const ll MAXN = 400000;

#define DOTS 400000

///segmenttree-add
ll NSEG; // Number of fields (with indices $0,\dots,NSEG-1$)
ll maxin[DOTS]; // initialize to 0, WARNING: Should have at least size $2\cdot2^k+10$ with $2^k>N$ and $k\in\mathbb Z^+$
ll off[DOTS]; // initialize to 0, WARNING: Should have at least size $2\cdot2^k+10$ with $2^k>N$ and $k\in\mathbb Z^+$

void relax(ll i) {
	maxin[i] |= off[i];
	off[2*i+1] |= off[i];
	off[2*i+2] |= off[i];
	off[i] = 0;
}

// add(a,b,v) increases the values at $a,\dots,b-1$ by v
void add(ll a, ll b, ll v, ll i=0, ll s=0, ll e=NSEG) {
	if (b <= s || e <= a)
		return;
	if (a <= s && e <= b) {
		off[i] |= v;
		return;
	}
	relax(i);
	add(a, b, v, 2*i+1, s, (s+e)/2);
	add(a, b, v, 2*i+2, (s+e)/2, e);
	maxin[i] = // Change this if you want the minimum.
		(maxin[2*i+1] | off[2*i+1]) & (maxin[2*i+2] | off[2*i+2]) ;
}

// query(a,b) returns the max of the values at $a,\dots,b-1$
ll query(ll a, ll b, ll i=0, ll s=0, ll e=NSEG) {
	if (b <= s || e <= a)
		return -1; // Change this if you want the minimum (should be a neutral element).
	if (a <= s && e <= b)
		return off[i] | maxin[i];
	relax(i);
	return  // Change this if you want the minimum.
		query(a, b, 2*i+1, s, (s+e)/2) & query(a, b, 2*i+2, (s+e)/2, e);
}


ll N, M;
ll in[MAXN][3];
ll resp[MAXN];

int main(){
	IOFAST();
	while( cin >> N >> M){
		FILL( resp, 0);
		REP(i,0,M){
			cin >> in[i][0] >> in[i][1] >> in[i][2];
		}
		NSEG = N + 1;
		bool ok = true;
		
		REP(j,0,MAXN) maxin[j]  = 0;
		REP(j,0,MAXN) off[j]  = 0;
		REP(i,0,M){
			add( in[i][0], in[i][1]+1, in[i][2] );
		}
		REP(i,1,N+1){
			resp[i] = query( i, i+1);
		}
		REP(i,0,M){			
			if( query( in[i][0] , in[i][1]+1 ) != in[i][2] ){
				ok = false;
				goto end;
			}
		}
		
		end:
		if( !ok ){
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			REP(i,1,N+1){
				if( i > 1) cout << " ";
				cout << resp[i] ;
			}
			cout << endl;
		}
	}
	
	return 0;
}