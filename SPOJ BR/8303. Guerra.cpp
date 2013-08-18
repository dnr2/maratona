//http://br.spoj.pl/problems/GUERRA/
//#tag distancia distance dist 
//#tag math matematica
//#tag geometria geometry
//#sol: caculate the distance between spaceships line segment, and then between spaceships planes

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pii pair<int,int>
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define EPS 1e-9

using namespace std;

int i,j,k,a,b,c,d, n,m,t;
int caso =1;

bool comp(double a, double b){
	return (a-b) > EPS;
}

struct P{
	double x,y,z;
	P(double x =0, double y=0,double z =0) : x(x), y(y) , z(z) {}
	P operator + (const P & in){
		return P(x +in.x, y+in.y, z+in.z);
	}
	P operator - (const P & in){
		return P(x -in.x, y-in.y, z-in.z);
	}
	double operator * ( const P & b ){
		return (x * b.x + y * b.y + z * b.z);
	}
	P operator * ( const double & fat){
		return P( x * fat, y*fat, z*fat);
	}
	double operator ! (){
		return hypot( hypot(x,y), z);
	}
	P operator / ( const P & b){
		double aux = (x*b.x+y*b.y+z*b.z), aux2 = hypot(hypot(b.x,b.y),b.z); 
		aux /= (aux2 * aux2);
		return P(b.x*aux,b.y*aux,b.z*aux);
	}
	P operator % ( const P & b) {
		return P(y*b.z-b.y*z, z*b.x-b.z*x, x*b.y-b.x*y);
	}
};

double distSP(P a, P b, P c){
	P pp = a + (c-a)/(b-a);
	if( !comp( !(a-pp) + !(pp-b) , !(a-b)) ) return !(c-pp);
	return min( !(a-c), !(b-c));
}

double distSS(P a, P b, P c, P d){
	P ba = b-a;
	P cd = c-d;
	P ca = c-a;
	P w = ba%cd;
	if( !comp(w*w,0.0)){
		// printf("aqui: %lf %lf %lf\n", w.x, w.y,w.z);
		return min( min( distSP(a,b,c), distSP(a,b,d)), 
			min( distSP(c,d,a), distSP(c,d,b)));
	}
	double dd = ba%cd*w;
	double x = (ca%cd*w)/dd;
	double y = (ba%ca*w)/dd;
	double z = (ba%cd*ca)/dd;
	if( x >=0 && x <= 1 && y >= 0 && y <= 1) return !(w*z);
	return min( min( distSP(a,b,c), distSP(a,b,d)), 
			min( distSP(c,d,a), distSP(c,d,b)));
}

double distPP(P a, P b, P c, P d) {
	P ba = b-a;
	P ca = c-a;
	P da = d-a;
	P w = ba%ca;
	P q = d-da/w;
	double x=(b-a)%(q-a)*w, y=(c-b)%(q-b)*w, z=(a-c)%(q-c)*w;
	if(x <= 0 && y <= 0 && z <= 0||x >= 0 && y >= 0 && z >= 0)
		return !(da/w);
	return min( min(distSP(a,b,d), distSP(b,c,d)),
	distSP(c,a,d));
}

P p[4], q[4];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	cin >> t;
	while(t--){
		fr(i,0,4) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
		fr(i,0,4) scanf("%lf%lf%lf", &q[i].x, &q[i].y, &q[i].z);
		double dist = 1.0/0.0;
		fr(i,0,4) fr(j,i+1,4) fr(k,j+1,4) fr(l,0,4) {
			double d = distPP(p[i], p[j], p[k], q[l]);
			if( d < dist ) dist = d;
			d = distPP(q[i], q[j], q[k], p[l]);
			if( d < dist ) dist = d;
		}
		fr(i,0,4) fr(j,i+1,4) fr(k,0,4) fr(l,k+1,4) {
			// printf("%d %d %d %d: %lf\n", i ,j,k,l,dist);
			double d = distSS(p[i], p[j], q[k], q[l]);
			if( d < dist ) dist = d;
		}
		printf("%.2lf\n", dist);
	}
	return 0;
}