//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1513
//#tag geometry
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
#include <cassert>
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
#define DINF 1e15
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 110;

typedef double co;

struct pu {
	co x,y;
	pu(co a=0, co b=0) {x=a;y=b;}
};
pu operator-(const pu &a, const pu &b) {
	return pu(a.x-b.x,a.y-b.y);
}
// Not always necessary!
bool operator==(const pu &a, const pu &b) {
	return a.x == b.x && a.y == b.y;
}
pu operator*(co a, const pu &b) {
	return pu(a*b.x, a*b.y);
}
///orientation
co kr(const pu &a, const pu &b) { // z component of the cross product $a\times b$
	return a.x*b.y-b.x*a.y;
}
co kr(const pu &a, const pu &b, const pu &c) { // z component of the cross product $(b-a)\times (c-a)$
	return kr(b-a,c-a);
}
// Intersection of the (infinite) lines $a_1a_2$ and $b_1b_2$ (if they aren't parallel).
// You obviously have to use floating point numbers, here!
pu inter(const pu &a1, const pu &a2, const pu &b1, const pu &b2) {
	return (1/kr(a1-a2,b1-b2))*(kr(a1,a2)*(b1-b2) - kr(b1,b2)*(a1-a2));
}

struct st{
	char let;
	int x, y;
	int pos;
	st( char let =0, int x=0, int y=0, int pos=0): let(let), x(x), y(y), pos(pos) {}
};

bool cmp( const st & a, const st & b){
	if( a.y == b.y ) return a.x < b.x;
	return a.y < b.y;
}

bool cmp2( double a, double b){
	if( fabs( a - b ) < EPS ) return true;
	return false;
}

bool cmp3( const pair<double,int> & a, const pair<double,int> & b ) {
	return a.FT > b.FT;
}

st in[maxn];
double xx[maxn*maxn];

vector< PDD > resp;
vector< pair<double,int> > vecc;

int main(){	
	int n;
	while( cin >> n){
		string ini, str; cin >> ini;
	
		REP(i,0,n){
			int x, y;
			cin >> str >> x >> y;
			in[i] = st( str[0], x, y, -1);
		}
		int xsz = 0;
		sort( in, in + n , cmp);
		REP(i,1,n){
			REP(j,0,i){
				if( in[j].y >= in[i].y ) break;
				pu point = inter( pu( 0,0) , pu( 1,0), pu( in[i].x, in[i].y), pu(in[j].x, in[j].y));
				xx[xsz++] = point.x ;
			}
		}
		xx[xsz++] =  DINF; 
		xx[xsz++] =  -DINF;
		sort( xx, xx + xsz );
		xsz = unique( xx, xx + xsz , cmp2 ) - xx;
		
		resp.clear();
		
		REP(kk,1,xsz){
			string seq = "";
			double xaux;
				
			vecc.clear();
			xaux = xx[kk-1] + (xx[kk] - xx[kk-1]) / 2; 
			REP(i,0,n){
				vecc.PB( MP( atan2( in[i].y, in[i].x - xaux ), i ) );
			}
			sort( vecc.begin(), vecc.end(), cmp3 );
			
			seq = "";
			REP(i,0,n){
				seq += in[vecc[i].SD].let;
			}
			
			if( seq == ini ){
				resp.PB( MP( xx[kk-1], xx[kk]) );
			}	
		}
		
		cout << resp.size() << endl;
		REP(i,0,(int)resp.size()){
			double l = resp[i].FT, r = resp[i].SD;
			if( i > 0) printf(" ");
			if( fabs( l ) == DINF  ) printf("*");
			else printf("%.6lf", l);
			if( fabs( r ) == DINF  ) printf(" *");
			else printf(" %.6lf", r);
		}
		puts("");
		puts("");
	}
	
	return 0;
}