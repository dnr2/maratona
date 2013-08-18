//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2119
//#tag geometry geometria
//#sol calcular as trisectors e depois calcular os pontos D E e F a partir da interseção das retas

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
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct point{
	double x,y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator +(point q){ return point(x + q.x, y + q.y); }
	point operator -(point q){ return point(x - q.x, y - q.y); }
	point operator *(double t){ return point(x * t, y * t); }
	point operator /(double t){ return point(x / t, y / t); }
	double operator *( point q){ return x * q.x + y * q.y; }
	double operator %( point q){ return x * q.y - y * q.x; }
};

point in[3];
point out[3];
point inter[6];

point intersect(point p, point r, point q, point s){
	double t = ((q-p) % s)/(r%s);
	return p +(r*t);
}

double angle( point a, point b){
	return acos( (a * b) / (sqrt(a*a) * sqrt(b*b)) );
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t; cin >> t;
	while(t--){
		scanf("%lf%lf%lf %lf%lf%lf", &in[0].x, &in[0].y, &in[1].x, &in[1].y, &in[2].x, &in[2].y);
		fr(i,0,3){
			double ang = angle( in[(i+1)%3] - in[i], in[(i+2)%3] - in[i]);
			// db(ang);
			ang /= 3.0;
			inter[(2*i)].x = cos(ang) * (in[(i+1)%3] - in[i]).x - sin(ang) * (in[(i+1)%3] - in[i]).y;
			inter[(2*i)].y = sin(ang) * (in[(i+1)%3] - in[i]).x + cos(ang) * (in[(i+1)%3] - in[i]).y;
			// db( inter[(2*i)].x _ inter[(2*i)].y);
			ang *= 2.0;
			inter[(2*i)+1].x = cos(ang) * (in[(i+1)%3] - in[i]).x - sin(ang) * (in[(i+1)%3] - in[i]).y;
			inter[(2*i)+1].y = sin(ang) * (in[(i+1)%3] - in[i]).x + cos(ang) * (in[(i+1)%3] - in[i]).y;
			// db( inter[(2*i)+1].x _ inter[(2*i)+1].y);
		}
		
		out[2] = intersect( in[0] , inter[0] , in[1], inter[3]);
		out[0] = intersect( in[1] , inter[2] , in[2], inter[5]);
		out[1] = intersect( in[0] , inter[1] , in[2], inter[4]);
		
		fr(i,0,3){
			if( i > 0) printf(" ");
			printf("%.8lf %.8lf", out[i].x , out[i].y);
		}
		puts("");
	}
	return 0;
}