//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4369
//#tag binary search
//#sol binary search the answer, to test if it works just sort the array and try to to create a bucket to each pair.

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

const int MAXN = 1000001;

int in[MAXN];

int main(){
	int n , k, len, off, lo, hi, mid;
	while(scanf("%d%d", &n, &k) > 0 ){
		len = 2*n*k, off = 2 * (k-1); 
		hi = 0;
		REP(i,0,len){ scanf("%d", in + i); hi = max(hi,in[i]); }
		sort( in,in +len);
		lo = in[1]-in[0]-1, 
		hi++; len--;
		while( lo + 1 < hi){
			mid = (lo+hi)>>1;
			bool works = false;
			int skip = 0, pairs = 0;
			REP(i,0,len){
				if( in[i+1] - in[i] <= mid){
					pairs++; skip += off; i++;
				} else {
					skip--;
					if( skip < 0) break;
				}
				if( pairs == n){
					works = true; break;
				}
			}
			if( works){
				hi = mid;
			} else {
				lo = mid;
			}
		}
		printf("%d\n", hi);
	}
	return 0;
}