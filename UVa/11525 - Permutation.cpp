//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2520
//#tag binary indexed tree bit
//#tag binary search
//#sol fill an array with numbers 1,2,3...K, for each S_i, get the element in i-th position in array and delete this element.
//for efficiency should use some kind of tree to delete and retrieve in O(log K). used binary indexed tree here.

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
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 60000;

int bit[maxn<<3], n;
void update(int x, int v) { while( x <= n ) { bit[x] += v; x += x & -x; } }
int sum(int x) { int ret=0; while(x>0){ ret += bit[x]; x -= x & -x; } return ret; }

int get(int x){
	int lo= 1, hi = n, mid, a, b;
	while( lo <= hi ){
		mid = (lo + hi ) >> 1;
		a = sum(mid); b = sum(mid-1);
		if( (a == x) && (a - b) ){
			update( mid, -1);
			return mid;
		} else if( a < x) lo = mid + 1;
		else  hi = mid - 1;		
	}
	return 0;
}

int main(){
	
	int T,a; cin >> T;
	while(T--){
		cin >> n;
		memset(bit,0,sizeof(bit));
		REP(i,0,n){ update( i+1,1); }
		REP(i,0,n){
			scanf("%d", &a);
			if( i ) printf(" ");
			printf("%d", get(a+1));
		}
		puts("");
	}
	return 0;
}