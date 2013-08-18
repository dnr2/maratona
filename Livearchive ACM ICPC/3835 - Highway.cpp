//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1836
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>


using namespace std;

int i, j , k, n , m, l , d, a, b;

struct ponto{
	double x, y;
	ponto( double x1 = 0, double y1 = 0) : x(x1), y(y1) {};
	bool operator < ( const ponto & p) const {
		return x < p.x;
	}
};

ponto p[100000];

double distance( double a, double b, double c, double d) {
	return sqrt( pow((a-c), 2) + pow(b-d, 2) );
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while( scanf("%d", &l ) > 0){
		scanf("%d %d", &d , &n) ;
		int resp = 0;
		for( i = 0; i< n; i++){
			scanf("%d%d", &a, &b);
			p[i].x = (double) a;
			p[i].y = (double) b;
		}
		sort( p, p + n);
		double rad = -1;
		double dist = (double) d;
		for( i =0 ; i < n ; i++){
			// cout << distance( p[i].x , p[i].y, rad, 0) << endl;
			if( rad == -1 || ( distance( p[i].x , p[i].y, rad, 0) > dist && p[i].x > rad ) ){				
				rad = p[i].x + sqrt( dist * dist - p[i].y * p[i].y);
				// printf("%d placed at -> %lf\n", i, rad);
				resp++;
			} else if( distance( p[i].x , p[i].y, rad, 0) > dist ){
				rad = p[i].x + sqrt( dist * dist - p[i].y * p[i].y);
				// printf("%d was at %lf and was recalculated to -> %lf\n", i,  distance( p[i].x , p[i].y, rad, 0), rad);
			} 
		}
		printf("%d", resp); puts("");
	}
	return 0;
	
}
