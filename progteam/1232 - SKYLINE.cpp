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
int NSEG; // Number of fields (with indices 0 ... NSEG-1)
pii arr[DOTS];
bool lazy[DOTS];

// query(a,b,v) how many elements is less or equal to v between a ... b-1 and set max and min of skyline
int query(int a, int b, int v, int i=0, int s=0, int e=NSEG) {
	// db( a _ b _ v _ i _ s _ e);
	if (b <= s || e <= a)
		return 0; 
	if (a <= s && e <= b){
		if( v >= arr[i].F ){
			lazy[i] = true;
			arr[i].F = arr[i].S = v;
			return (e-s);
		}
		if( v < arr[i].S || a == b) return 0;
	}
	if( lazy[i] ){
		query(s, e, arr[i].F, 2*i+1, s, (s+e)/2); //TODO s,e?
		query(s, e, arr[i].F, 2*i+2, (s+e)/2, e); //TODO s,e?
		lazy[i] = 0;
	}
	int left = query(a, b, v, 2*i+1, s, (s+e)/2);
	int right = query(a, b, v, 2*i+2, (s+e)/2, e);
	arr[i].F = max( arr[2*i+1].F , arr[2*i+2].F);
	arr[i].S = min( arr[2*i+1].S , arr[2*i+2].S);
	return left + right;
}

int in[100000][3];

int main(){
	
	int T; cin >> T;
	REP(cn,1,T+1){	
		int n, hi = 0; scanf("%d", &n);				
		REP(i,0,n){
			scanf("%d%d%d", in[i], in[i]+1, in[i]+2);			
			hi = max( hi, in[i][1]);
		}
		NSEG = hi+1;
		REP(i,0, NSEG * 3){
			arr[i] = pii(0,0); lazy[i] = false;
		}
		ll resp = 0;
		REP(i,0,n){
			resp += query(in[i][0], in[i][1], in[i][2]+1);			
		}
		printf("%lld\n", resp);
	}	
	return 0;
}