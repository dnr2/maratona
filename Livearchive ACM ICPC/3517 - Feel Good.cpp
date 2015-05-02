//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1518
//#tag RMQ range minimum query
//#tag segment tree segtree 
//#sol consider for each position P that this would be the smallest value in some interval, so you have to find 
// how long this interval could be, i.e, the closest value to the left and right that are smaller than the value in
// the considered position P, to do that you can use RMQ

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

const int maxn = 200000;
const int maxm = 3000000;
int n;
int in[maxn];
int maxval;
int idx[2][maxn];
ll sum[maxn];

int maxin[maxm];
int NSEG;


void add( int a, int b, int v, int i=0, int s = 0, int e = NSEG){
	if( b <= s || e <= a) return;
	if( a <= s && e <= b ){
		maxin[i] += v;
		return;
	}
	add( a, b ,v, 2*i+1, s ,(s+e)/2);
	add( a, b, v, 2*i+2, (s+e)/2, e);
	maxin[i] = max( maxin[2*i+1], 
					maxin[2*i+2]);
}

int query( int a, int b, int i = 0, int s = 0, int e = NSEG){
	if( b <= s || e <= a ) return -1e9;
	if( a <= s && e <= b ){
		return maxin[i];	
	}
	return max( query( a, b , 2*i+1, s, (s+e)/2),
				query( a, b , 2*i+2, (s+e)/2, e) );
}

int main(){
	int pline = false;
	while(cin >> n){
		maxval = 0;
		REP(i,0,n){
			scanf("%d", in + i);
			sum[i] = in[i] + ((i > 0)? sum[i-1] : 0);
			maxval = max(maxval, in[i] );
		}
		NSEG = maxval + 10;		
		REP(kk,0,2){
			FILL(maxin,-1);	
			
			REP(i,0,n){
				if( in[i] == 0) {
					idx[kk][i] = query( 0, in[i]+1 );
				} else {
					idx[kk][i] = query( 0, in[i] );				
				}				
				int val = query( in[i], in[i] + 1 );
				add( in[i], in[i] +1 , i - val );
			}
			reverse( in, in + n);
		}
		ll resp = -1, lr = 0, rr = 0;
		REP(i,0,n){
			int l = idx[0][i], r = n - idx[1][n-i-1] - 1;	
			r--;
			ll nresp = sum[r] - ((l>=0)? sum[l] : 0);
			nresp *= in[i];
			if( resp < nresp  ) {
				resp = nresp; lr = l + 1, rr = r;
			} else if( resp == nresp && ((rr-lr) > (r-l))  ){
				resp = nresp; lr = l + 1, rr = r;
			}
		}
		if( pline) cout << endl;
		else pline = true;
		cout << resp << endl;
		cout << (lr+1) << " "  << (rr+1) << endl;
	}
	return 0;
}