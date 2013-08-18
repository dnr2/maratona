//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3893
//#tag math matematica
//#tag integral volume
//#tag busca binária
//#sol usar a formula S (pi * (f(x) ^2) ) para calcular o volume 
//após construir a fórmula do volume para um dado x, verificamos através da busca binária 
//qual a posição da marca que tem determinado volume

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long
#define PI acos(-1)
#define EPS 1e-9

using namespace std;

double cof[50];
double aux[50];
double xl, xh, inc;
int n;

double integral( double y ){
	double resp = 0.0;
	fr(i,0,n){
		// db( (1.0 / ( (double) (i+1))) * cof[i] * ( pow ( y , (double) (i+1) ) ) );
		resp += (1.0 / ( (double) (i+1))) * cof[i] * ( pow ( y , (double) (i+1) ) );
	}
	return resp;
}

double volume( double l, double h){
	return fabs( PI * (integral( l) - integral(h)) );
} 

int main(){
	int caso =1;
	while(scanf("%d", & n) > 0){
		fr(i,0,50) cof[i]= aux[i] = 0.0;
		n++;
		fr(i,0,n) scanf("%lf", &aux[i]); 
		scanf("%lf%lf%lf", &xl, &xh, &inc);
		fr(i,0,n) {
			fr(j,0,n){
				cof[i + j] += aux[i] * aux[j]; 
			}
		}
		n*= 2; bool prim = true;
		printf("Case %d: %.2lf\n", caso++, volume(xl, xh)) ;
		if(  volume(xl, xh) < inc ) printf("insufficient volume" );
		else {	
			double vol = inc;
			fr(k,0,8){
				double ini = 0, fim = 100000000.0, mid; 
				fr(i,0,100){
					mid = (ini+fim)/2;
					if( volume( xl, xl + mid) > vol )  fim = mid;
					else ini = mid;
				}
				if( volume( xl, xl + mid) > volume( xl, xh) + EPS ) break;
				if( !prim) printf(" ");
				else prim = false;
				printf("%.2lf", mid);
				vol += inc;
			}
		}
		puts("");
	}
	
	return 0;
}