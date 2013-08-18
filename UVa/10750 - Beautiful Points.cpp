//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1691
//tag math matematica
//tag geometry geometria
//tag most proximate points 
//sol usar solução O( n * long(n) ) para achar o par de pontos mais próximos dentro de um conjunto de 
//pontos

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>



#define foreach(it,a,b) for(typeof(a) it =(a); it != (b); it++)
#define all(x) (x).begin(), (x).end()
#define EPS 1e-8

using namespace std;

const double pi = acos(-1);

inline int cmp(double a, double b=0){
	if (fabs(a-b) < EPS) return 0;
	if( a< b) return -1;
	return 1;
}

struct point{
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
	point operator - (point q) { return point( x - q.x, y - q.y); } 
	
	int cmp(point q) const {
		if( int t = ::cmp(x, q.x)) return t;
		return ::cmp(y , q.y);
	}
	bool operator < (point q) const { return cmp(q) < 0;}
};

typedef vector<point> poly;
typedef point vetor;

double norma(vetor v) { return hypot( v.x, v.y); }

point resp1, resp2;

bool ycmp(point a, point b){
	if( a.y != b.y) return a.y <b.y;
	return a.x < b.x;
}


double closest_pair( poly &P){
	int n = P.size();
	double d= norma(P[0] -P[1]);
	resp1 = P[0] ; resp2 = P[1];
	set<point , bool(*) (point,point)> s(&ycmp);
	sort(P.begin(),P.end());
	
	for(int i=0, j=0; i<n;i++){
		point lower(0, P[i].y - d), upper( 0, P[i].y + d);
		while( P[i].x - P[j].x > d) 
			s.erase(P[j++]);
		foreach( p, s.lower_bound(lower), s.upper_bound(upper)) {
			if( d > norma(P[i] - *p)){
				d = norma(P[i] - *p);
				resp1 = P[i];
				resp2 = *p;
				//printf("-> %lf,%lf %lf,%lf\n", resp1.x, resp1.y, resp2.x, resp2.y);
			}
			//d  = min(d, norma(P[i] - *p)); // TODP
		}
		s.insert(P[i]);
	}
	
	return d;
}


int main() {

	//freopen("a.txt","r", stdin);
	int n, a, b, maior, menor, t;
	double xin, yin, respdist;
	scanf("%d", &t);
	poly in;
	bool lol = false;
	while(t--){
		scanf("%d", &n);
		in.clear();
		for( int i =0; i< n;i++){
			scanf("%lf%lf", &xin, &yin);
			in.push_back( point(xin, yin));
		}
		respdist = closest_pair( in);
		//cout << respdist << endl;
		if( lol) puts("");
		else lol = true;
		printf("%.3lf %.3lf\n", ((resp1.x + resp2.x)/ 2.0), ((resp1.y + resp2.y)/ 2) );
	}
	
	
	return 0;	
}

