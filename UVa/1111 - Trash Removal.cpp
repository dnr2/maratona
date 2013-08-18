//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3552
//#tag geometry geometria
//#sol devemos considerar que cada uma das duas parede do lixo sempre intersectará pelo menos um ponto do polígono.
//Considerando que se cada parade (direita e esquerda) intersecta apenas um ponto, podemos rotacionar o objeto para
//conseguir uma largura do lixo menor (pois nada impede a rotação)
//assim basta pegar o convexhull do polígono e para cada lado, devemos rotacionar esse polígono tal que esse lado
//fique vertical. Assim , depois de rotacionar, calculamos qual o maiorX e menorX do polígono rotacionado
//pegamos o menor ( maiorX - menorX ) de todas as rotações possíeis

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
#define EPS 1e-9
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct point{
	double x, y;
	point ( double x= 0, double y = 0 ) : x(x), y(y) {}
	bool operator < (const point & p) const {  return (x == p.x)? y<p.y : x <p.x ; } 
	double operator * ( point & p ) { return  x*p.x + y*p.y ; } 
	point operator - ( point & p) { return point( x -p.x, y-p.y); } 
};

double cross( const point & O, const point &A, const point &B) { 
	return (A.x - O.x) * (B.y - O.y) - (A.y -O.y) * (B.x-O.x); 
}
double angle( point a, point b){
	// db( a * b  _ sqrt(a*a) * sqrt( b*b) );
	return acos( (a * b) / (sqrt(a*a) * sqrt( b*b)));
}

point rotete( point p, double ang) {
	return point( p.x * cos( ang) - p.y * sin(ang), p.x * sin(ang) + p.y * cos(ang));
}

vector<point> convexHull(vector<point> P){
	int n = P.size(),k =0; vector<point> H(2*n);
	sort(P.begin(), P.end());
	for( int i =0; i< n; i++){
		while( k>=2 && cross(H[k-2], H[k-1] , P[i]) <= 0) k--; H[k++] = P[i];
	}
	for( int i=n-2, t=k+1; i>=0; i--){
		while( k>=t && cross(H[k-2], H[k-1] , P[i]) <= 0) k--; H[k++] = P[i];
	}
	H.resize(k); return H;	
}

int main(){	
	int caso = 1; int n;
	while(scanf("%d", &n) > 0 && n){
		vector<point> in; double a, b;
		fr(i,0,n) { scanf("%lf%lf", &a, &b); in.pb(point(a,b)); }
		in = convexHull( in);  
		double resp = 10000000.0;		
		fr(i,0,in.size()-1){
			point vet;			
			if( in[i].y <= in[i+1].y) vet = (in[i+1] - in[i]); 
			else vet = (in[i] - in[i+1]);			
			double ang = atan2( vet.y, vet.x); ang = PI/2 - ang;
			double xmax = -10000.0, xmin = 100000.0;
			fr(j,0,in.size()){
				point aux = rotete( in[j], ang); 				
				xmax = max( aux.x, xmax);
				xmin = min( aux.x, xmin);
			}			
			resp = min( resp , xmax - xmin);
		}
		
		resp *= 100; resp = ceil( resp); resp /= 100; 
		printf("Case %d: %.2lf\n", caso++, resp);
	}
	return 0;
}