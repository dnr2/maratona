//
//#tag
//#sol

#include <bits/stdc++.h>


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
#define EPS 1e-7
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 1000;

struct pt { 
	double x,y; 
	pt( double x = 0, double y = 0):x(x), y(y) {}
	bool operator<(const pt &p) const{
		return( fabs(x -p.x) < EPS) ? y<p.y : x<p.x; 
	}
	pt operator + (pt arg) { return pt( x + arg.x, y + arg.y); } 
	pt operator - (pt arg) { return pt( x - arg.x, y - arg.y); } 
	double operator !() {return sqrt( x*x + y*y );}
	double operator *(pt arg) {return x*arg.x + y*arg.y; }
	pt operator / (pt arg) { 
		pt clone = pt(x,y); 
		double fact = (clone*arg)/(arg*arg);
		return pt( arg.x * fact, arg.y * fact);
	}
};

double comp( double x, double y){
	return fabs( x - y ) > EPS;
}

double distSP(pt a, pt b, pt c) {
	pt pp = a + (c-a)/(b-a);
	if( !comp(!(a-pp) + !(pp-b), !(a-b)) ) return !( c-pp );
	return min(!(a-c), !(b-c));
}

double cross(const pt &O, const pt &A, const pt &B)
{ return (A.x-O.x) * (B.y-O.y) - (A.y-O.y) * (B.x-O.x); }

// Returns a list of convex hull in counter-clockwise order.
// In case of collinear points, only end-points are taken (not middle).
// The last point is the same as the first one.
vector<pt> ConvexHull(vector<pt> P) {
	int n = P.size(), k = 0; vector<pt> H(2*n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; i++)
	{ while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
	for (int i = n-2, t = k+1; i >= 0; i--)
	{ while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
	H.resize(k); return H; 
}

pt in[maxn];

int main(){

	int T; cin >> T;
	REP(cn,1,T+1){
		int n;cin >> n;
		REP(i,0,n){
			cin >> in[i].x >> in[i].y ;
		}
		vector<pt> vec;
		printf("Case #%d:\n", cn);
		REP(i,0,n){
			int mresp = n;
			// DB( i );
			REP(mask,0,1<<n){				
				if( mask & (1<<i) ){
					vec.clear();
					REP(j,0,n){
						if( mask & (1<<j) ){
							vec.PB( in[j] );
						}
					}
					vec = ConvexHull( vec);
					int sz = vec.size();
					bool ok = false;					
					if( sz < 3) {
						ok = true;
					} else {
						REP(j,1,sz){
							if( distSP( vec[j], vec[j-1], in[i]) < EPS ){
								ok = true; break;
							}
						}
					}
					if( ok ){
						int cont = 0, maux = mask;
						REP(i,0,n){
							cont += maux & 1;
							maux >>= 1;
						}
						mresp = min( mresp, n - cont);
					}
				}
			}
			cout << mresp << endl;
		}
	}
	return 0;
}