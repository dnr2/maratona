//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=953
//#tag math matematica
//#tag geometry geometria
//#sol use pitagoras to find the next x position. be careful when calculating the rightmost side of the rectangle

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

const int maxn = 10;
double in[maxn];
double seq[maxn];


int main(){
	
	int T; cin >> T;
	while(T--){
		int n; scanf("%d", &n);
		REP(i,0,n){
			scanf("%lf", &in[i]);
		}
		sort(in,in+n);
		double resp = 1e10;
		do{
			REP(i,0,n){
				seq[i] = in[i];
				REP(j,0,i){
					double o = fabs( in[j] - in[i] );
					double h =  (in[j] + in[i]);
					double d = sqrt( h * h - o * o ) ;
					seq[i] = max( seq[i], seq[j] + d );
				}
			}
			double right = 0;
			REP(i,0,n){
				right = max( right, seq[i] + in[i]);
			}
			resp = min( resp, right );
		} while( next_permutation( in, in+n));
		printf("%.3lf\n", resp );
	}
	return 0;
}