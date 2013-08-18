#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

#define fr(i,j,n) for(int (i)=(j); (i) < (n);(i)++)
#define EPS 1e-9
#define PI acos(-1);
#define pid pair<int,double>
#define pii pair<int,int>
#define F first
#define S second

using namespace std;

int caso =1;


int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double a, b ,v,A,s;
	while(scanf("%lf %lf %lf %lf %lf", &a, &b , &v, &A, &s) > 0){
		if( s < EPS) break;
		double vx, vy, sx, sy, r1, r2;
		vx = cos( A/360.0 * PI); 
		vy = sin( A/360.0 * PI);
		sx = vx * s / 2.0;
		sy = vy * s / 2.0;
		printf("%d %d\n", ((int)(sx/a)), ((int)(sy/b)));
	}
	return 0;
}
