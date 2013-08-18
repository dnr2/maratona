//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1609
//tag math matematica
//tag geometria geometry
//tag busca binaria bynary search
//sol fazer uma busca binária no angulo do raio.

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
#define EPS 1e-9

using namespace std;

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	double L1, L2, n, C, aux, ini, fim , mid;
	while(scanf("%lf%lf%lf", &L1,&n, &C) >0){
		if( L1 < 0 ) break;
		L2 = ( 1.0 + n * C ) * L1;
		// cout << "L2= " << L2 << endl;
		ini = 0.0, fim = 2.0 * PI - EPS;
		int cont = 500;
		double x, r, arc;
		double resp = 0;
		while(cont--){
			mid = (ini + fim) / 2.0;
			r = L1/(2.0 * sin( (mid /2.0) ));
			arc =  r * mid;
			// cout << "->" <<  arc << endl;
			if( L2 < arc ){
				fim = (ini + fim) / 2.0;
			} else if( L2 > arc){
				ini = (ini + fim) / 2.0;
			} else {
				break;
			}
		}
		x = L1/(2.0 * tan((mid /2.0)));
		resp = r - x;
		printf("%.3lf\n", resp);
	}
	
	
	return 0;
}
