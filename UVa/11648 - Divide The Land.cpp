//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2695
//#tag: geometry geometria
//#tag: busca binaria 
//#sol: primeiro: fazermos uma busca binária para definir o angulo entre AB e AD
//segundo: fazermos uma busca binária para definir o a distância H entre as retas suportes de
//fazermos uma busca binária para definir o a distância H entre as retas suportes de AB e EF e a
//partir de H calcular se as terras foram igualmente definidas

#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int main(){

	// freopen("in.txt", "r" , stdin);
	// freopen("out.txt", "w" , stdout);
	double a ,b, c, d;
	int caso =1;
	int t;
	cin >> t;
	
	// cout << asin( 4.0/5.0) << endl << endl;
	while( t--){
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		double x = 0.0, y = acos(-1),x1,y1, num,h , e, f, a1, a2,g,d1,x2;
		double alfa;
		do{ 
			alfa = (x + y )/2;
			x1 = (cos(alfa) * c) + b;
			y1 = sin(alfa) * c;
			num = sqrt(pow((a - x1),2) + pow((y1),2)) ;
			// cout << fabs( num -d) << endl;
			// cout << alfa << endl;
			// cout << x1 << " " << y1 << endl;
			if( fabs( num -d) < 1e-10){
				break;
			} else if( num > d){
				y = (x + y) /2;
			} else {
				x = (x + y) /2;
			}
		} while( true);
		// cout << alfa << endl;
		x1 = (cos(alfa) * c);
		y1 = sin(alfa) * c;
		x = 0.0; y = y1;
		// cout << "x1 = " << x1 << " y1 = " << y1 << endl;
		// cout << "a & b = " 	<< b << " " << a << endl;
		int temp = 5000;
		do{
			
			h = (x + y )/2;
			
			if( alfa > acos(-1) /2 ) x2 = ((a + abs(x1)) - b);
			else if( a - x1 > b ) x2 = ((a -b) - x1);
			else  x2 = -1 * ( (fabs( x1) + b) - a);
			
			d1 = b + (x1 * ( y1 -h) / y1 ) + ((y1-h) * x2 / y1) ;
			// cout << "h = " << h << " -> " << d1 << endl;
			a1 = ((a + d1) * h )/ 2.0;
			a2 = ((b + d1) * ( y1 - h) ) / 2.0;
			if( fabs(a1 - a2) < 1e-10){
				// cout << "d1 = " << d1 << endl;
				// cout << "h = " << h << endl;
				// cout << "areas " << a1 << " " << a2 << endl;
				// cout << (a1 + a2) << endl;
				// cout << ((a+b)*y1)/2 << endl;
				// break;
			} else if( a1 > a2){
				y = (x + y) /2;
			} else {
				x = (x + y) /2;
			}
		} while( temp--);
		// cout << "e = " << e << " f = " << f <<  " g = " << g <<endl;
		double resp1 = sqrt(pow(h,2) + pow(fabs(x1) - fabs(x1 * ( y1 -h) / y1 ),2));
		double resp2 = sqrt(pow(h,2) + pow((fabs(x2) - fabs((y1-h) * x2 / y1) ),2));
		// double resp1 = 1.0;
		// double resp2 = 2.0;
		// cout << h << endl;
		printf("Land #%d: %.8lf %.8lf\n", caso++, resp1, resp2);
	}
	
	return 0;
}
