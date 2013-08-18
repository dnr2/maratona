//http://acm.timus.ru/print.aspx?space=1&num=1748
//#tag geometry geometria
//#tag segment intersection interseção de segmentos

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <climits>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <queue>

#define EPS 1e-9
#define pid pair<int,double>
#define F first
#define S second
#define mp make_pair
#define cl(x) memset( x, 0 ,sizeof(x))
#define fr(i,j,k) for(int i = j; i < k; i++)
#define ll long long
#define ms(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define _ << " " << 
using namespace std;

struct P{
	double x, y;
	P(double a =0, double b=0):x(a),y(b){}
	P operator - ( P & in){
		return P( x - in.x, y - in.y);
	}
	const P operator + ( const  P & in) const{
		return P( x +in.x, y +in.y);
	}
	double operator * ( P & in){
		return  (x * in.y) - (y * in.x);
	}
	P operator * ( double & in){
		return P ( x *in, y *in);
	}
	double dist (P & in){
		return hypot( x - in.x, y - in.y);
	}
};


bool inter(P a, P b, P c, P d ){
	// cout << a.x _ a.y _ b.x _ b.y _ c.x _ c.y _ d.x _ d.y << endl;
	// double A1 = b.y - a.y;
	// double B1 = a.x - b.x;
	// double C1 = A1 * a.x -  B1 * a.y;
	// double A2 = d.y - c.y;
	// double B2 = c.x - d.x;
	// double C2 = A2 * c.x -  B2 * c.y;
	// double det = A1 * B2 - A2*B1;
	P p = a; P q = c; P r = b - a; P s = d - c;
	double f = s * r;
	// cout << "f" _ f <<endl;
	if( fabs(f) < EPS) return false;
	else {
		// double x = ( B2*C1 - B1*C2) / det;
		// double y = ( A1*C2 - A2*C1) / det;
		double t = ((p-q)*s)/f;
		// cout << "t"  _ t << endl;
		P aux = p + (r*t);
		double x = aux.x; double y = aux.y;
		// cout << x << " " << y << endl;
		int cont = 0; 
		if( fabs(x-a.x) < EPS && fabs(y-a.y) < EPS) cont++;
		if( fabs(x-b.x) < EPS && fabs(y-b.y) < EPS) cont++;
		if( fabs(x-c.x) < EPS && fabs(y-c.y) < EPS) cont++;
		if( fabs(x-d.x) < EPS && fabs(y-d.y) < EPS) cont++;
		// cout << "cont = " << cont << endl;
		if( (min( a.x, b.x) - EPS) <= x && x <= (max( a.x, b.x) + EPS) &&
			(min( a.y, b.y) - EPS) <= y && y <= (max( a.y, b.y) + EPS) && 
			(min( c.x, d.x) - EPS) <= x && x <= (max( c.x, d.x) + EPS) &&
			(min( c.y, d.y) - EPS) <= y && y <= (max( c.y, d.y) + EPS) && cont <= 1) return true;
	}
	// cout <<"false" << endl;
	return false;
}

vector<pid> adj[10];
double dist[10];

struct cmp{
	const bool operator()( pid & x, pid & y) const {
		return x.S > y.S;
	}
};

void djk(){
	priority_queue<pid,vector<pid>, cmp> heap;
	cl(dist);
	heap.push( mp( 0, 0)); pid aux;
	while(!heap.empty()){
		aux = heap.top(); heap.pop();
		// cout << aux.F _ aux.S _ dist[aux.F] <<endl;
		if( dist[aux.F] > 0) continue;
		dist[aux.F] = aux.S;
		if( aux.F == 4) break;
		fr(i,0,adj[aux.F].size()){
			heap.push( mp( adj[aux.F][i].F, adj[aux.F][i].S + aux.S));
		}
	}
}

int main(){
	P in[6];
	int t; cin >> t;
	while(t--){
		cin >> in[0].x >> in[0].y >> in[4].x >> in[4].y >> in[1].x >> 
		in[1].y >> in[2].x >> in[2].y >> in[3].x >> in[3].y;
		fr(i,0,9) adj[i].clear();
		fr(i,1,5){
			bool ok = true;
			fr(j,1,3) if( inter( in[0], in[i], in[j], in[((j+1==4)? 1:j+1)]) ) {
				ok = false;
			}
			P lol1 = (in[1] - in[2]); lol1.x *= 0.001; lol1.y *= 0.001;
			P lol2 = (in[3] - in[2]); lol1.x *= 0.001; lol1.y *= 0.001;
			P aux1 = in[2] + lol1;
			P aux2 = in[2] + lol2;
			if( inter( in[0], in[i], aux1, aux2) ) ok = false;
			if( ok ){
				adj[0].pb( mp( i, in[0].dist(in[i]) ));
				// cout << in[0].x << " " << in [0].y << " " <<in[i].x << " " << in[i].y << endl;
				// cout << "0" << "->" << i << " " << in[0].dist(in[i]) << endl;
			}
		}
		fr(i,1,4){
			bool ok = true;
			fr(j,1,3) if( inter( in[i], in[4], in[j], in[((j+1==4)? 1:j+1)]) ) ok = false;
			P lol1 = (in[1] - in[2]); lol1.x *= 0.001; lol1.y *= 0.001;
			P lol2 = (in[3] - in[2]); lol1.x *= 0.001; lol1.y *= 0.001;
			P aux1 = in[2] + lol1;
			P aux2 = in[2] + lol2;
			if(  inter( in[i], in[4], aux1, aux2 ) ) ok = false;
			if( ok ){
				adj[i].pb(mp( 4, in[i].dist(in[4]) ));
				// cout << i << "->" << 4 << " " << in[i].dist(in[4]) << endl;
			}
		}
		fr(i,1,4){
			fr(j,1,4){
				if( i != j) {
					adj[i].pb(mp( j, in[i].dist(in[j]) ));
					// cout << i << "->" << j << " " << in[i].dist(in[j]) << endl;
				}
			}
		}
		djk();
		printf("%.6lf\n", dist[4]);
	}
	return 0;
}