//http://www.spoj.com/problems/TAP2014F/
//#tag string 
//#tag hashing 
//#sol use hashing to compare if two strings are equal. Use two matrices to keep track of the position of each string
// and it's hashing at a certain time. Update the time t+1 after each season. go back in time when you have to prune 
// the strings. remember that if in the time t, if string s1 is in before string s2 and they have different hashing
// they will stay in the same position relative to each other. But if they have same hashing and are contiguous,
// you will have to reorganize them according to the new letter of the season, and their ID numbers.

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
#define PLL pair<ll,ll>
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

const int MAXN = 110;
const int MAXM = 10010;
const ll h1 = 31;


int P[MAXN][MAXM];
ll H[MAXN][MAXM];
char str[MAXN];
int ss[MAXN];

struct st{
	int l, p, j;
	st( int l = 0, int p = 0, int j = 0): l(l), p(p), j(j) {}
	bool operator < ( const st & arg ) const {
		if( l == arg.l && p == arg.p ) return j < arg.j;
		if( l == arg.l) return p < arg.p;
		return l < arg.l;
	}
};

int main(){
	
	int N, M; cin >> N >> M;
	REP(i,0,N) P[i][0] = i, H[i][0] = 0;
	int t = 0;
	vector< st > vec;
	REP(i,0,M){
		int c, p;
		scanf("%d%s%d", &c, str, &p);
		t = max( 0 , t-c);
		REP(j,0,N) ss[j] = str[P[j][t]] - 'a' + 1;
		int it = 1, lo = 0;	

		while( it <= N){
			if(!( it < N && H[it][t] == H[it-1][t])){							
				vec.clear();				
				REP(j,lo,it){
					vec.PB( st( ss[j], P[j][t]  , j ) );					
				}
				sort( vec.begin(), vec.end());				
				REP(j,lo,it){			
					P[j][t+1] = vec[j-lo].p;
					H[j][t+1] = H[ vec[j-lo].j ][t] * h1 + vec[j-lo].l;					
				}
				lo = it;
			}
			it++;
		}
		t++;
		printf("%d\n", P[p-1][t] + 1 );
	}
	return 0;
}