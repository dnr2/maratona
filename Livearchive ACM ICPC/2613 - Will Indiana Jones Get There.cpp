//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614
//#tag segment distance 2D
//#tag distancia entre segmentos 2D
//#tag binary search

#include<bits/stdc++.h>

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

typedef double co;

///geometry
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

double operator !(const pu & a ){
	return sqrt( a.x*a.x + a.y*a.y);
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

// ----- test if two segments intersect ------ //

bool between( const pu &a, const pu  & b , const pu & c ){
	return ( c.x - a.x ) * ( c.x -b.x ) <= 0 &&
		( c.y-a.y )* ( c.y-b.y ) <= 0 ;
}

bool gr( const pu &a1 , const pu &a2 , const pu &b1 , const pu &b2 ) {
	co w1 = kr( b1-a1 , a2-a1 ) , w2 = kr( a2-a1 , b2-a1 );
	if(w1 == 0 && w2 == 0)
		return between( a1 , a2 , b1 ) || between ( a1 , a2 , b2 ) ||
			between ( b1 , b2 , a1 ) || between ( b1 , b2 , a2 ) ;
	return (w1 >= 0 && w2 >= 0) || (w1 <= 0 && w2 <= 0 ) ;
}

bool intersects( const pu &a1 , const pu &a2 , const pu &b1 , const pu &b2 ) {
	return gr( a1 , a2 , b1 , b2) && gr( b1 , b2 , a1 , a2 ) ;;	
}


bool comp( double a, double b ){
	return fabs( a - b ) > EPS ; //TODO < EPS?
}

struct P{
	double x, y;
	P( double x= 0 , double y = 0 ) : x(x), y(y) {}
	P operator + ( P in ) { return P(x + in.x, y + in.y ); } 
	P operator - ( P in ) { return P(x - in.x, y - in.y ); } 
	
	double operator * ( P in ) { return x * in.x  + y * in.y ; } 
	P operator / ( P in ) { double f = (P(x,y) * in)/(in*in); return P( in.x * f, in.y * f); }
	double operator ! ( ) { return sqrt(x*x + y*y ); }
};

pu go( P & a) { return pu( a.x, a.y ); }

double distSP(P a, P b, P c) {
	if( !comp(a.x,b.x) && !comp(a.y,b.y) ) return !( c-a );
	P pp = a + (c-a)/(b-a);	
	if( !comp(!(a-pp) + !(pp-b), !(a-b)) ) return !( c-pp );
	return min(!(a-c), !(b-c));
}

double distSS( P a, P b, P c, P d){
	if( intersects( go(a), go(b), go(c), go(d)) ) return 0;	
	return min(min(distSP(a,b,c), distSP(a,b,d)),
			   min(distSP(c,d,a), distSP(c,d,b)));
}

const int maxn = 1200;

P in[maxn][2];
double dist[maxn][maxn];
int mark[maxn];
int n;

double mdist;

void dfs( int node ){
	if( mark[node] ) return;
	mark[node] = 1;
	REP(i,0,n){
		if( i == node ) continue;
		if( dist[node][i] <= mdist ){
			dfs( i );
		}
	}
}

int main(){

	while( cin >> n && n ){
		REP(i,0,n){
			double x, y , l;
			cin >> x >> y >> l;
			in[i][0] = P(x,y);
			if( l >= 0) in[i][1] = P(x+l,y);			
			else in[i][1] = P(x,y-l);			
		}
		REP(i,0,n){
			REP(j,i+1,n){
				double d = distSS( in[i][0], in[i][1], in[j][0], in[j][1]);					
				dist[i][j] = dist[j][i] = d;
			}
		}
		
		double lo = 0, hi = 1e10; int cnt = 100;
		while( fabs( lo - hi ) > EPS && cnt-- > 0){
			mdist = (lo+hi)/2.0;
			FILL( mark, 0);			
			dfs( 0 );
			if( mark[1] ) hi = mdist;
			else lo = mdist;
		}
		printf("%.2lf\n", mdist );		
	}

	return 0;
}
