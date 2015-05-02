//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2896
//#tag geometry / geometria
//#tag ternary search / busca ternaria
//#sol for the case where the dogs walk on a straght path you can use ternary search to find the max and min
// distance between them, even if they walk with different speeds because they take the same time to walk their paths.
// So initially calculate the speed for both dogs, then try to "cut" the sequence of paths such that you will
// be always comparing two sequences where the dogs walk on straight paths and it takes for both of them the same
// time to walk from the begining to the end of the sequence.

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

const int maxn = 100;

struct pt{
	double x, y ;
	pt( double x = 0, double y = 0) : x(x), y(y) {}	
	pt operator - ( pt & arg ) { return pt ( x-arg.x, y-arg.y); }
	pt operator + ( pt & arg ) { return pt ( x+arg.x, y+arg.y); }
	double operator ! () { return sqrt( x * x + y * y ); }	
	pt operator * ( double arg) { return pt( x * arg, y * arg ); }
};

pt in[2][maxn];
int sz[2];
double speed[2];

double maxdist, mindist;

// initial point A, initial point B, final point A, final point B,
// position A and position B
void dogdist( pt ia, pt ib, pt fa, pt fb, int pa, int pb){	
	
	double mint; int pos;
	pt afa = fa;
	pt afb = fb;
	if(  ((!(ia - fa))/speed[0]) < ((!(ib - fb))/speed[1] ) ){
		mint = ((!(ia - fa))/speed[0]); pos = 0;
		pt dir = (fb - ib) * (1/(!(fb - ib)));
		afb = ( dir * speed[1] * mint) + ib;
	} else {
		mint = ((!(ib - fb))/speed[1]); pos = 1;
		pt dir = (fa - ia) * (1/(!(fa - ia)));
		afa = ( dir * speed[0] * mint) + ia;
	}	
	
	//ternary search for min and max, respectively
	REP(kk,0,2){
		double lo = 0, hi = 1, m1, m2; int cont = 0;
		while( cont++ < 100 && fabs( hi - lo ) > EPS ){
			m1 = lo + ((hi - lo ) / 3);
			m2 = hi - ((hi - lo ) / 3);
			
			pt cura1 = (((afa-ia) * m1) + ia );
			pt curb1 = (((afb-ib) * m1) + ib );
			double mm1 = !(cura1 - curb1);
			pt cura2 = (((afa-ia) * m2) + ia );
			pt curb2 = (((afb-ib) * m2) + ib );
			double mm2 = !(cura2 - curb2);			
			
			if( kk == 1 ) swap( mm1, mm2 );
			if( mm1 < mm2 ) lo = m1;
			else hi = m2;
		}
		double mid = ((hi+lo)/2);
		pt cura = (((afa-ia) * mid ) + ia );
		pt curb = (((afb-ib) * mid ) + ib );
		double dist = !(cura - curb);		
		if( kk == 1) mindist = min( mindist, dist);
		else maxdist = max( maxdist, dist);
		
	}
	
	if( pos == 0 && pa + 1 < sz[0] ){
		dogdist( afa, afb, in[0][pa+1], fb, pa + 1, pb );
	} else if( pos == 1 && pb + 1 < sz[1] ) {
		dogdist( afa, afb, fa, in[1][pb+1], pa, pb + 1 );
	}
}

int main(){
	
	int T; cin >> T;
	REP(cn,1,T+1){
		REP(i,0,2) cin >> sz[i];
		
		REP(kk,0,2){
			speed[kk] = 0;
			REP(i,0,sz[kk]){
				double a, b; 
				scanf("%lf%lf", &a, &b);
				in[kk][i] = pt( a,  b);
				if( i > 0){
					pt aux = in[kk][i] - in[kk][i-1];
					speed[kk] += !aux;
				}
			}
		}		
		
		maxdist = 0;
		mindist = 1e12;
		
		dogdist( in[0][0], in[1][0], in[0][1], in[1][1], 1, 1 );		
		printf("Case %d: %.0lf\n", cn, maxdist - mindist);
	}
	
	return 0;
}