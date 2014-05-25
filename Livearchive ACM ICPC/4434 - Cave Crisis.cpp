//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2435
//#tag geometry
//#tag distance segment segment point
//#tag point inside polygon
//#tag binary search
//#sol binary search diameter (radius), with the value of the radio create a graph where each polygon is a node, 
// the polygon (nodes) are connected if the distance between them is less or equal to the radios. consider the 
// floor and the ceiling as polygons as well.
// its possible to go through the cave if and only if there is no path between the floor and ceiling nodes.

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
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct point{
	double x, y, z;
	point( double x = 0, double y = 0, double z =0) : x(x), y(y), z(z) {}
	const point operator + (const point & a) const { return point( x + a.x , y + a.y, z+a.z);}
	const point operator - (const point & a) const { return point( x - a.x , y - a.y, z-a.z);}
	const point operator * (const double & a) const { return point( x * a , y * a, z *a);}
	const point operator / (const double & a) const { return point( x / a , y / a, z / a);}
};

point cross(point a, point b){
	return point( a.y*b.z-b.y*a.z, a.z*b.x-a.x* b.z, a.x*b.y-b.x*a.y);
}

double cross2( point a, point b){
	return a.x * b.y - b.x * a.y;
}

double dot(point a, point b){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

double norm(point p){
	return sqrt(p.x * p.x + p.y * p.y + p.z*p.z);
}

point project(point a, point b){
	return b * (dot(a,b) / dot(b,b)); 
}

bool comp( double a, double b){
	return fabs(a - b) > EPS;
}

double distSP(point a, point b, point c){
	point pp = a + project((c-a), (b-a));
	if( !comp( norm(a - pp) + norm(pp-b), norm(a-b)) ) return norm(c-pp);
	else return min( norm(a-c), norm(b-c));
}

double distSS(point a, point b , point c, point d){
	point ba = b-a;
	point cd = c-d;
	point ca = c-a;
	point w = cross(ba , cd);	
	if( !comp( dot(w,w), 0)){
		return min( min( distSP(a,b,c), distSP(a,b,d)), min(distSP(c,d,a), distSP(c,d,b))); 
	}
	double dd = dot( cross(ba,cd), w);
	double x = dot( cross(ca, cd), w)/ dd;
	double y = dot( cross(ba, ca), w)/ dd;
	double z = dot( cross(ba, cd), ca)/ dd;
	if( x >= 0 && x <= 1 && y >= 0 && y <= 1) return norm( w * z);
	return min( min( distSP(a,b,c), distSP( a,b,d)), min( distSP(c,d,a), distSP(c,d,b)));
} 

const int maxn = 110;
vector<point> polys[maxn];
double dists[maxn][maxn];
vector<int> adj[maxn];
int mark[maxn];

// see if point lie inside polygon, 0 = outside, 1 = inside, 2 = border
int inpolygon( point a, vector<point> & poly ){
	int num = 0;
	int N = poly.size();
	REP(i,0,N){
		point b = poly[i] - a;
		point c = poly[(i+1)%N]-a;
		if( fabs(b.x) < EPS && fabs(b.y) < EPS)
			return 2;		
		if( b.y > c.y)
			swap( b,c);
		if( (b.x * c.x < 0 || b.y * c.y < 0) && fabs(cross2( b,c)) < EPS)
			return 2;
		if( b.y < 0 && c.y >= 0 && cross2(b,c) >= 0)
			num++;
	}
	return num%2;
}

void getDists( int n, double w){
	REP(i,0,n){
		REP(j,i+1,n){
			double dist = 1e10;
			//dist SS
			int sz1 = polys[i].size();
			int sz2 = polys[j].size();
			REP(a,0,sz1){
				REP(b,0,sz2){
					dist = min( dist, distSS( polys[i][a], polys[i][(a+1)%sz1], polys[j][b], polys[j][(b+1)%sz2]) );
				}
			}
			//test if one polygon is inside another
			REP(a,0,sz1) if( inpolygon( polys[i][a], polys[j])) dist = 0;
			REP(b,0,sz2) if( inpolygon( polys[j][b], polys[i])) dist = 0;
			
			dists[i][j] = dist;
			dists[j][i] = dist;
		}
	}
	REP(i,0,n){
		double dist[2];
		dist[0] = dist[1] = 1e10;
		REP(j,0,2){
			REP(k,0,(int)polys[i].size()){
				double nw = (1-2*j) * (w/2);
				dist[j] = min( dist[j], sqrt( pow( nw - polys[i][k].y, 2)));
			}
		}
		dists[i][101] = dists[101][i] = dist[0];
		dists[i][102] = dists[102][i] = dist[1];
	}
}

bool test( double rad , int n){
	REP(i,0,maxn) adj[i].clear();
	REP(i,0,n){
		REP(j,i+1,n){
			if( dists[i][j] <= rad){
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	REP(i,0,n){
		if( dists[i][101] <= rad){
			adj[i].pb(101);
			adj[101].pb(i);
		}
		if( dists[i][102] <= rad){
			adj[i].pb(102);
			adj[102].pb(i);
		}
	}
	
	queue<int> q;
	memset(mark, 0, sizeof( mark));
	q.push(101);
	mark[101] = 1;
	while( !q.empty()){
		int cur = q.front(); q.pop();
		if( cur == 102) return false;
		REP(i,0,(int)adj[cur].size()){			
			if( !mark[adj[cur][i]] ){
				mark[adj[cur][i]] = 1;
				q.push( adj[cur][i]);
			}
		}
	}
	return true;
}

int main(){
	int n,w;
	while(scanf("%d%d", &w,&n) > 0 && (n||w) ){
		REP(i,0,maxn) polys[i].clear();
		REP(i,0,n){
			int m; scanf("%d", &m);
			REP(j,0,m){
				point p; scanf("%lf %lf", &p.x, &p.y);
				polys[i].pb(p);		
			}
		}
		REP(i,0,n) {
			REP(j,0,n) dists[i][j] = 1e10;
			dists[i][i] = 0;
		}
		double lo = 0, mid, hi = w;
		double resp = -1;
		getDists(n, w);
		REP(it,0,30){
			if( fabs(hi - lo) < EPS) break;
			mid = (lo+hi)/2;
			if( test( mid, n) ){
				resp = mid;
				lo = mid;
			} else {
				hi = mid;
			}
		}
		REP(i,0,n){
			int sz= (int)polys[i].size();
			REP(j,0,sz){
				double ndist = distSP( polys[i][j], polys[i][(j+1)%sz], point( 0, 0));	
				resp = min( resp , 2 * ndist);
			}
		}
		
		if( resp == -1){
			puts("impossible");
		} else {
			printf("%.2lf\n", resp/2.0);
		}
	}
	return 0;
}