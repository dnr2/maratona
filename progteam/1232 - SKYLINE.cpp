//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397
//#tag segment tree seg tree arvore de segmentos 
//#tag lazy propagation
//#sol use seg tree with lazy propagation, there are potentially too many parates, but a few queries, use
//coordinate compression to reduce the number of nodes in the tree

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
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


#define DOTS 1000000

int val[DOTS];

///segmenttree-add
int NSEG; // Number of fields (with indices $0,\dots,NSEG-1$)
pii maxin[DOTS]; // initialize to 0, WARNING: Should have at least size $2\cdot2^k+10$ with $2^k>N$ and $k\in\mathbb Z^+$
pii off[DOTS]; // initialize to 0, WARNING: Should have at least size $2\cdot2^k+10$ with $2^k>N$ and $k\in\mathbb Z^+$

pii combine( pii a, pii b){
	return pii( max( a.F, b.F) , min( a.S, b.S));
}

void relax(int i) {
	maxin[i] = combine(minin[i], off[i]);
	off[2*i+1] = combine( off[2*i+1], off[i]);
	off[2*i+2] = combine( off[2*i+2], off[i]);
	off[i] = pii( -1E9, 1E9);
}

// set(a,b,v) increases the values at $a,\dots,b-1$ by v
void set(int a, int b, int v, int i=0, int s=0, int e=NSEG) {
	if (b <= s || e <= a)
		return;
	if (a <= s && e <= b) {		
		off[i].F = max( off[i].F, v);
		off[i].S = min( off[i].S, v);
		return;
	}
	relax(i);
	add(a, b, v, 2*i+1, s, (s+e)/2);
	add(a, b, v, 2*i+2, (s+e)/2, e);
	
	maxin[i].F = max( // Change this if you want the minimum.
		max( maxin[2*i+1].F ,off[2*i+1].F) ,
		max( maxin[2*i+2].F ,off[2*i+2].F) );
	maxin[i].S = min( // Change this if you want the minimum.
		min( maxin[2*i+1].S ,off[2*i+1].S) ,
		min( maxin[2*i+2].S ,off[2*i+2].S) );	
	
}

// query(a,b) returns the maximum of the values at $a,\dots,b-1$
int query(int a, int b, int v, int i=0, int s=0, int e=NSEG) {
	if (b <= s || e <= a)
		return 0; 
	if (a <= s && e <= b){
		
	}
	relax(i);
	return 
		query(a, b, 2*i+1, s, (s+e)/2) +
		query(a, b, 2*i+2, (s+e)/2, e);
}

int in[100000][3];

int main(){
	
	int T; cin >> T;
	REP(cn,1,T+1){		
		int n, hi = 0, lo = INF; scanf("%d", &n);				
		REP(i,0,n){
			scanf("%d%d%d", in[i], in[i]+1, in[i]+2);
			hi = max( hi , in[i][2]);
			lo = max( lo , in[i][1]);
		}
		NSEG = hi - lo + 10;
		REP(i,0,NSEG * 3){
			off[i] = maxin[i] = pii( -1E9, 1E9);
		}
		int resp = 0;
		REP(i,0,n){
			resp += query(in[i][0], in[i][1], in[i][2]);
			add( in[i][0], in[i][1], in[i][2] );
		}
		printf("%d\n");
	}	
	return 0;
}