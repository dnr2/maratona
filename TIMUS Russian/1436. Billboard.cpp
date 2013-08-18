//http://acm.timus.ru/problem.aspx?space=1&num=1436
//#tag busca ternária ternary search
//#sol fazer duas buscas ternárias, para ver o ponto da estrada com maior angulo

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

struct p{
	double x, y;
	p( double x = 0, double y =0):x(x),y(y) {}
	double operator * ( const p & in) {
		return (x * in.x) + (y * in.y);
	}
	double operator ! (){
		return hypot( x, y);
	}
	p operator + ( const p & in) {
		return p( x + in.x, y + in.y);
	}
	p operator - ( const p & in) {
		return p( x - in.x, y - in.y);
	}
	p operator * ( const double & in){
		return p( x * in, y * in);
	}
	double dist( const p & in){
		return hypot( x - in.x, y - in.y);
	}
};

p p1, p2;

double func(double in){
	p v1( p1.x - in, p1.y);
	p v2( p2.x - in, p2.y);
	return acos( ( v1 * v2) /((!v1)*(!v2)));
}

double eps = 1e-9;

double ter(double left, double right, int cont ){
	if( right - left  < eps || cont == 0) return (left + right)/2.0;
	double lt = ((2*left) + right)/3.0;
	double rt = (left + (2*right))/3.0;
	if( func(lt) < func(rt)) return ter(lt,right, cont--);
	else return ter( left, rt , cont--);
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	while( scanf("%lf%lf%lf%lf", &p1.x,&p1.y ,&p2.x, &p2.y) > 0){
		if( p1.y * p2.y <= 0) puts("3.141593");
		else if( p1.y == p2.y) printf("%.6lf\n", func((p1.x+p2.x)/2) );
		else {
			double x = ((p1.x * p2.y) - (p1.y * p2.x))/(-(p1.y -p2.y));
			// db(x);
			printf("%.6lf\n", max( func(ter( -1e6,x, 50)), func(ter( x,1e6,50))));
		}
		
	}
	return 0;
}