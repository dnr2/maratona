//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1593
//#tag convex Hull 
//#tag graham 
//#tag geometry geometria
//#sol simplesmente calcular todos os pontos dos cantos dos retângulos e usar o algoritmo convex hull
// e dividir a soma das áreas dos tetângulos pela área do pelígono retornado pelo CH.


#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#define PI acos(-1)

#define EPS 1e-8

using namespace std;

double p[4][2];

inline int cmp(double a, double b =0){
	if( fabs(a-b)<=EPS) return 0;
	if( a< b) return -1;
	return 1;
}

struct point{
	double x, y;
	point(double x =0, double y= 0): x(x), y(y) {}
	int cmp(point q) const { 
		if( int t= ::cmp(x,q.x)) return t;
		return ::cmp(y,q.y);
	}
	point operator -( point q) { return point( x - q.x, y- q.y);}
	double operator %( point q) { return x * q.y - y * q.x;}
	
};

typedef vector<point> poly;
typedef point vetor;

double norma (vetor v) { return hypot(v.x,v.y);} //hypot

int ccw(point a, point b, point c){
	return cmp((b-a)%(c-a));
}

point pivo;

bool cmp_radial( point a, point b){
	int aux = ccw(pivo, a,b);
	return ((aux<0) || (aux ==0 && norma(a-pivo) < norma(b-pivo) ));
}

bool cmp_pivo( point p, point q){
	int aux = cmp( p.x, q.x );
	return ((aux<0) || (aux ==0 && cmp(p.y , q.y) < 0));
}

poly graham(poly p){
	int i,j,n = p.size();
	poly g;
	pivo = *min_element(p.begin(), p.end(), cmp_pivo);
	sort( p.begin(), p.end(), cmp_radial);
	// n previous declared
	for( i=j=0; i<n;i++){
		while( j>=2 && ccw( g[j-2] , g[j-1], p[i]) >=0){
			g.pop_back(); j--;
		}
		g.push_back(p[i]); j++;
	}
	return g;
}


int main(){
	// freopen("in.txt","r", stdin);
	// freopen("out.txt","w", stdout);
	int t ;
	cin >>t;
	int n;
	while(t--){
		scanf("%d", &n);
		int cont =0;
		vector<point> g,resp;
		double area =0, hullarea =0,x,y,w,h,ph;
		for( int i=0;i<n;i++){ 
			scanf("%lf%lf%lf%lf%lf", &x,&y,&w,&h,&ph);
			ph *= acos(-1)/180;
			p[0][0] = sin(ph) * h / 2;
			p[0][1] = cos(ph) * h / 2;
			ph += (acos(-1) / 2.0);
			p[1][0] = sin(ph) * w / 2;
			p[1][1] = cos(ph) * w / 2;
			
			g.push_back(point( x + p[0][0] + p[1][0], y + p[0][1] + p[1][1]));
			g.push_back(point( x - p[0][0] + p[1][0], y - p[0][1] + p[1][1]));
			g.push_back(point( x + p[0][0] - p[1][0], y + p[0][1] - p[1][1]));
			g.push_back(point( x - p[0][0] - p[1][0], y - p[0][1] - p[1][1]));
			area += w * h;
		}
		// for( int i=0;i<g.size();i++){
			// printf("p -> %lf %lf\n", g[i].x,  g[i].y);
		// }
		// cout << "area " << area << endl;
		resp = graham( g);
		// ConvexHull( g);
		 
		// for( int i=0;i<resp.size();i++){
			// printf("graham -> %lf %lf\n", resp[i].x,  resp[i].y);
		// }
		
		for( int i=1,j=0;j<resp.size(); i = (i + 1) % resp.size(), j++ ){
			
			hullarea += resp[j].x * resp[i].y;
			hullarea -= resp[i].x * resp[j].y;
		}
		hullarea = fabs( hullarea / 2.0);
		// cout << "hull area " << hullarea << endl;
		printf("%.1lf %c\n", (100.0 * area / hullarea) , '%'); 
	}
	return 0;
}
