//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=35&category=279&page=show_problem&problem=3835
//#tag geometry geometria + busca binária 
//#sol usar a busca binária para achar o angulo entre AB e AD, depois disso aplicar soma vetorial
// para achar os outros pontos. Detalhe na precisão que deve ser maior que 1e-10

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t, caso =1;
	double x, y,z,w,a,b,c,d,s,e,vx,vy,len,angle,x1,y1,dist,delta,rx1,ry1,rx2,ry2;
	cin >> t;
	while( t--){
		scanf("%lf%lf%lf%lf%lf%lf%lf", &x,&y,&z,&w,&b,&c,&d);
		s = 0; e = acos(-1);
		vx = z - x; vy = w - y;
		len = sqrt( pow(vx, 2) + pow(vy,2));
		vx /= len; vy /= len;
		// cout << len << endl;
		int cont = 5000;
		do{
			angle = (s + e) / 2;
			x1 = (cos( angle) * d )+ c;
			y1 = sin( angle) *d ;
			dist = sqrt( pow( len - x1, 2) + pow( y1,2));
			// cout << angle << " " << dist << endl;
			if( fabs(dist - b) < 1e-12){
				break;
			} else if( dist > b ){
				e = ( s+e) /2;
			} else {
				s = ( s+e) /2;
			}
			
		} while(cont--);
		delta = acos( vx / sqrt( pow( vx, 2) + pow( vy,2)) );
		// cout << "delta: " << delta << endl;
		if( vy > 0){
			angle += delta;
		} else {
			angle -= delta;
		}
		// cout << "angle: " << angle << endl;
		rx2 = x + cos(angle) * d;
		ry2 = y + sin(angle) * d;
		rx1 = rx2 + c * vx;
		ry1 = ry2 + c * vy;
		printf("Case %d:\n", caso++);
		printf("%.8lf %.8lf %.8lf %.8lf\n", rx1, ry1, rx2, ry2);
	}
	return 0;
}
