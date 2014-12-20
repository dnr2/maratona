//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=342&page=show_problem&problem=440
//#tag binary search
//#sol do a binary search on the answer and test if it's big enough on the sorted input.

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

const int MAXN = 10100;

int in[MAXN];

int main(){
	int n, m, q, cn = 1;
	while( cin >> n >> m >> q){
		if( n == -1 && m == -1 && q== -1) break;
		cout << "Race " << (cn++) << ": ";
		REP(i,0,q) scanf("%d", in + i);
		sort( in , in + q);
		
		if( n * m < q ) {
			cout << "Organization Fault!"  << endl;
			continue;
		}		
		int lo = -1, hi = (in[q-1] - in[0]) + 10, mid;
		while( lo + 1 < hi ){
			mid = (lo+hi) /2;
			int fst = in[0], left = n-1, groups = 1, resp = 0;
			bool ok = true;
			REP(i,1,q){
				if( in[i] - fst <= mid && left >= 1 ){
					left--; 
				} else {
					resp = max(resp, in[i-1] - fst);
					fst = in[i];
					groups++;
					left = n-1;
				}
				if( groups > m ) { ok = false; break; }
			}			
			if( ok ) hi = mid;
			else lo = mid;
		}
		cout << hi << endl;
		
	}
	return 0;
}