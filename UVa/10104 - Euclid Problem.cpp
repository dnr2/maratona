//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
//#tag math matematica
//#tag algoritmo de euclides extendido 

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>

#define pii pair<int,int>
#define F first
#define S second

using namespace std;

int gdc(int a, int b){
	int aux;
	while(b>0){
		aux = a % b;
		a = b;
		b = aux;
	}
	return a;
}

pii mdc(int a, int b){
	if( b== 0) return pii(1,0);
	pii u = mdc(b,a%b);
	return pii ( u.S, u.F - (a/b) * u.S);
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int a, b;
	while( scanf("%d%d", &a,&b) >0 ){
		pii aux = mdc(a,b);
		printf("%d %d %d\n", aux.F, aux.S, gdc(a,b));
	}
	return 0;
}