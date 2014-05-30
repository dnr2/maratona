//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=754
//#tag 3D geometry geometria
//#tag rotation rotacao 
//#sol use formula to calculate ccw rotation of v around an axis n (v and n 3d vectors). Also rotate the axis themselves.
// Only test for intersections that actually hit the arm and not the ones that hit the servos (sneaky).
// Also, only test for when the servo goes strictly below the floor, and not just touches it.

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

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
#define EPS 1e-9
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

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

point cross(point a, point b){ return point( a.y*b.z-b.y*a.z, a.z*b.x-a.x* b.z, a.x*b.y-b.x*a.y); }
double dot(point a, point b){ return a.x * b.x + a.y * b.y + a.z * b.z; }
// ccw rotation of vector r around axis n
point rotate(point r, point n, double tet){ return (r * cos(tet)) + ( n * (dot(n,r) * (1-cos(tet)) )) + (cross(n,r) * sin(tet)); }
double norm2(point p){ return p.x * p.x + p.y * p.y + p.z*p.z; }

bool intersecth(point p1, point q1, point p2, point q2){
	point da = q1-p1;
	point db = q2-p2;
	point dc = p2-p1;
	double vol = fabs(dot(dc,cross(da,db)));
	if (vol > EPS) return false;
	double n = norm2(cross(da,db));
	double s = n < EPS ? 10 : dot(cross(dc,db),cross(da,db))/n;
	return s>EPS && s<1-EPS;
} 

bool intersect(point p1, point q1, point p2, point q2){
	return intersecth(p1,q1,p2,q2) && intersecth(p2,q2,p1,q1); 
}

point pts[20];
double dist[20];
double ang[20];

double mzero(double x){
	if( -EPS < x && x < EPS ) return 0.0;
	return x;
}

int main(){
	int n;
	int cases = 1;
	while(scanf("%d", &n) > 0 && n >= 0){
		REP(i,0,20) {
			dist[i] = 0;
			ang[i] = 0;
			pts[i] = point(0,0,0);
		}
		REP(i,0,n){
			scanf("%lf", &dist[i]);
		}
		REP(i,0,n){
			scanf("%lf", &ang[i]);
			ang[i] = (ang[i] / 180.0) * PI; 
		}
		point vec(0,0,1);
		pts[0] = point(0,0,0);
		point xz(0,1,0); // y axis
		point yz(1,0,0); // x axis
		REP(i,0,n){
			if( (i&1) == 0){
				vec = rotate(vec,xz,ang[i]);
				yz = rotate(yz,xz,ang[i]);
			} else {
				vec = rotate(vec,yz,ang[i]);	
				xz = rotate(xz,yz,ang[i]);
			}			
			pts[i+1] = pts[i] + (vec * dist[i]);
			if( pts[i+1].z < -EPS) {
				printf("Case %d: servo %d attempts to move arm below floor\n", cases++, (i+1));
				goto end; 
			}			
			REP(j,0,i-1){
				if( intersect( pts[i],pts[i+1],pts[j],pts[j+1]) ){
					printf("Case %d: servo %d causes link collision\n" , cases++, i+1);
					goto end;
				}
			}
		}
		
		printf("Case %d: robot's hand is at (%.3lf,%.3lf,%.3lf)\n", cases++, mzero(pts[n].x), mzero(pts[n].y), mzero(pts[n].z) );
		end: ;
	}
	return 0;
}