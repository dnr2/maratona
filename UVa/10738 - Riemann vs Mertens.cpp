//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3136
//#tag math matematica 
//#tag crivo eratotenes
//#tag primes primo
//#sol gerar crivo de primos, após isso verificar para cada número se algum de seus divisores 
//se repetem

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pair<int,int> pii

using namespace std;

int i,j,k,a,b,c,d, n,m;
int caso =1;

int crivo[1<<20];
int mu[1<<20];
int quant[1<<20];
int M[1<<20];
map<int,int> mapa;
int prims[30];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	mu[1] = M[1] = 1;
	// memset(crivo, 0, sizeof(crivo));
	crivo[0] = crivo[1] = 1;
	
	for( i =2;i<1010000; ){
		for( j= i; j<1010000;j += i){
			crivo[j] = i;
		}
		i++;
		while(crivo[i] != 0) i++;
	}
	int x, y, num;
	bool sf;
	
	for( i=2;i<1010000;i++){
		sf = true;
		num = y = 0;
		x = i;
		// memset(prims, 0, sizeof(prims));
		while( x != 1 && sf){
			// for( j =0;j <y;j++){
				// if( prims[j] == crivo[x]) sf = false;
			// }
			if( x % (crivo[x] * crivo[x]) == 0) sf = false;
			prims[y++] = crivo[x];
			x = x / crivo[x];
			num++;
		}
		if( sf){
			if( num &1) { mu[i] = -1; M[i]= M[i-1] -1; }
			else { mu[i] = 1; M[i]= M[i-1] + 1; }
		} else {
			mu[i] = 0; M[i]= M[i-1];
		}
		// if( i <= 20) printf("%d %d %d %d\n", i, num, mu[i], M[i]);
	}
	
	
	while(scanf("%d", &n)>0 && n){
		printf("%8d%8d%8d\n", n, mu[n], M[n]);
	}
	
	return 0;
}