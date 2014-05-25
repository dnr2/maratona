//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2071
//#tag matemática math
//#tag geometry geometria
//#sol primeiro decompomos o vetor velocidade em x e em y, depois usando a fórmula s = t * (v0 + vf)/2 
// de MRUV teremos o espaço percorrido nas componemtes x e y, depois disso é só ver quantas vezes
// a bolinha bateu nos cantos, dividindo s pelo comprimento/altura da mesa. devemos lembrar também 
// que a bolinha começa na metade da mesa!


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
#define PI acos(-1)
#define pid pair<int,double>
#define pii pair<int,int>
#define F first
#define S second

using namespace std;

int main(){

	double a, b ,v,A,s;
	while(scanf("%lf %lf %lf %lf %lf", &a, &b , &v, &A, &s) > 0){
		if( s < EPS) break;
		double vx, vy, sx, sy, r1, r2;
		vx = cos( A/180.0 * PI) * v; 
		vy = sin( A/180.0 * PI) * v;
		sx = (vx * s / 2.0) + 0.5 * a;
		sy = (vy * s / 2.0) + 0.5 * b;
		printf("%d %d\n", ((int)(sx/a)), ((int)(sy/b)));
	}
	return 0;
}
