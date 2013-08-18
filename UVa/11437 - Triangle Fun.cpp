//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2432
//tag geometry geometria 
//tag triangle triangulo
//sols encontrar cada ponto R P Q como descrito, usando uma função para achar interseção de linhas


#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for( int (i)=0; (i) < (n);++(i))
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 

using namespace std;

struct pt{
	double x, y;
	pt( double x = 0, double y = 0): x(x), y(y) {};
	pt operator + ( const pt & in) const {
		return pt ( x+ in.x, y + in.y);
	}
	pt operator - ( const pt & in) const {
		return pt ( x - in.x, y - in.y);
	}
	pt operator * ( const double & in) const {
		return pt ( x * in, y * in);
	}
	pt operator / ( const double & in) const {
		return pt ( x / in, y / in);
	}
	double operator % ( const pt & in) const {
		return x * in.y - y * in.x;
	}
};

pt in[3];
pt aux[3];
pt p[3];

pt inter(pt p, pt r, pt q, pt s){
	double t = (((q-p)%s)/(r%s));
	return (p+(r*t));
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t; cin >> t;
	while(t--){
		fr(i,0,3)scanf("%lf%lf", &in[i].x, &in[i].y);
		fr(i,0,3) aux[i] = in[i] + ((in[(i+1)%3] - in[i])/3.0);		
		fr(i,0,3) p[i] = inter(aux[i],(in[(i+2)%3] -aux[i]),aux[(i+1)%3],(in[(i+3)%3]-aux[(i+1)%3]));		
		pt a = p[0] - p[1];
		pt b = p[2] - p[1];
		printf("%.0lf\n", (fabs(a % b)/2.0));
	}
	return 0;
}

