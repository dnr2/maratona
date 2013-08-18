//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=997
//#tag probability probabilidade
//#tag math matematica
//#sol calcule a probabilidade considerando os segintes casos: ( soma deles )
// 1 - todos até I perdem e I ganha ( primeira rodada) = (1 -p) ^ (i-1)
// 2 - todos os N perdem depois todos até I perdem e I ganha ( segunda rodada) = (1 -p)^ n *(1 -p) ^ (i-1)
// 3 - todos os N perdem duas vezes depois todos até I perdem e I ganha ( terceira rodada) = ((1 -p)^ (2*n)) *(1 -p) ^ (i-1)
// etc, esse somatório iria até o infinito, mas como a questão pede com pouca precisão, precisamos
// iterar pucas vezes no número de rodadas


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>

#define pii pair<int,int>
#define F first 
#define S second
#define MAP map<int,int>
#define FOR(i,j,k) for(int (i) = (j); (i) < (k); ++(i))
#define MAXN 1000000

using namespace std;

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	double p,resp,aux;
	int n, i,t,m;
	cin >> t;
	while(t--){
		cin >> n >> p >> i;
		// cout << n << " " << p << " " << i << endl;
		aux = 0;
		for( int j = 0 ; j< 200; j++){
			aux += pow( (1.0 -p), (double) n * j);
		}
		aux *= pow( 1.0-p, ((double) i-1.0 ));
		aux *= p;
		printf("%.4lf\n", aux);
	}
	return 0;
}
