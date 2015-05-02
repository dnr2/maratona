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

const int maxn = 400;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int n;

struct P{
	double x, y, z;
	P( double x= 0 , double y = 0, double z = 0) : x(x), y(y), z(z) {}
	P operator + ( P in ) { return P(x + in.x, y + in.y , z + in.z ); } 
	P operator - ( P in ) { return P(x - in.x, y - in.y , z - in.z ); } 
	
	double operator * ( P in ) { x * in.x  + y * in.y + z * in.z; } 
	P operator % ( P in ) { return P(y*in.z-z*in.y, z*in.x-x*in.z, x*in.y-y*in.x ); }
	P operator / ( P in ) { double f = (P(x,y,z) * in)/(in*in); return in * f; }
	double operator ! ( ) { return sqrt(x*x + y*y ); }
};

double distSP(P a, P b, P c) {
	P pp = a + (c-a)/(b-a);
	if( !comp(!(a-pp) + !(pp-b), !(a-b)) ) return !( c-pp );
	return min(!(a-c), !(b-c));
}

double distSS(P a, P b, P c, P d) {
	P ba = b-a;
	P cd = c-d;
	P ca = c-a;
	P w = ba%cd;
	if( !comp(w*w,0) ) {
		return min(min(distSP(a,b,c), distSP(a,b,d)),
		min(distSP(c,d,a), distSP(c,d,b)));
	}
	double dd = ba%cd*w;
	double x = (ca%cd*w)/dd;
	double y = (ba%ca*w)/dd;
	double z = (ba%cd*ca)/dd;
	if( x >= 0 && x <= 1 && y >= 0 && y <= 1 ) return !(w*z);
	return min(min(distSP(a,b,c), distSP(a,b,d)),
		min(distSP(c,d,a), distSP(c,d,b)));
}

int main(){
	
	
	return 0;
}
