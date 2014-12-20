//
//#tag
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
#include <set>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define P PDD
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-10
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 100;


struct PT{
	double x, y;
	PT( double x = 0, double y = 0) : x(x) , y(y) {}
	const PT operator + (const PT & in) const { return PT( x + in.x , y + in.y); }
	const PT operator - (const PT & in) const { return PT( x - in.x , y - in.y); }
	const double operator * (const PT & in) const { return x * in.x + y * in.y; }
	const PT operator / (const PT & in) const { 
		PT ret(x,y);
		double val = (ret * in) / (in * in );		
		return PT(in.x * val, in.y * val);
	}
	const double operator ! () const {return sqrt( x*x + y*y); }
};

bool comp( double a, double b) {
	return fabs( a - b) > EPS;
}

double distSP(PT a, PT b, PT c) {
	PT pp = a + (c-a)/(b-a);
	if( !comp(!(a-pp) + !(pp-b), !(a-b)) ) return !( c-pp );
	return min(!(a-c), !(b-c));
}

PT in[MAXN][4];

double dx[] = {-1,1,1,-1};
double dy[] = {-1,-1,1,1};

int main(){		
	int T; cin >> T;
	REP(cn,1,T+1){
		int n; cin >> n;
		REP(i,0,n){
			double a, b,c,d;
			scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
			in[i][0] = PT( a, b );
			in[i][1] = PT( c, b );
			in[i][2] = PT( c, d );
			in[i][3] = PT( a, d );
		}
		double r , dist; scanf("%lf%lf", &r, &dist);
		double lo = 0, hi = 1e7, mid = 0; int cont = 0;
		while( cont++ < 55 ){
			mid = (lo+hi) / 2;			
			bool close = false;
			REP(i,0,n){
				REP(j,i+1,n){
					PT pts[2][4];
					REP(pt,0,2) REP(k,0,4) pts[pt][k] = in[(pt==0)?i:j][k];						
					REP(pt,0,2) REP(k,0,4){						
						pts[pt][k].x += dx[k] * r * mid;
						pts[pt][k].y += dy[k] * r * mid;						
					}
					
					//intersection
					REP(pt,0,2){
						int pt2 = ( pt + 1 ) % 2;
						if( !(  pts[pt][2].y < pts[pt2][0].y ||
								pts[pt][0].y > pts[pt2][2].y ||
								pts[pt][2].x < pts[pt2][0].x ||
								pts[pt][0].x > pts[pt2][2].x ) ) {							
							close = true; goto end;
						}
					}
					
					//dist seg to seg					
					REP(pt,0,2){
						int pt2 = (pt+1)%2;
						REP(u,0,4){
							int v = (u+2)%4, u2= (u+1)%4;
							if(  distSP( pts[pt][u], pts[pt][u2] , pts[pt2][v]) <= dist){								
								close = true; goto end;
							}
							v = (u+3)%4;
							if(  distSP( pts[pt][u], pts[pt][u2] , pts[pt2][v]) <=  dist){
								close = true; goto end;
							}
						}		
					}
				}
			}	

			end :
			if( close) hi = mid;
			else lo = mid;
		}
		printf("Case %d: %.3lf\n",cn, mid + 1e-6);
	}
	return 0;
}