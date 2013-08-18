//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1607
//#tag adhoc 
//#tag math matematica 
//#sol se associarmos o problema como sendo uma árvore, onde os vértices são os times, e as arestas 
// ligam o time que tem o confronto direto, ou seja, os que podem ser comparáveis. 
// veremos que o número de optimistic classification é ("o número de pais do nó" + 1) e o
// pessimistic classification é (2^N - "filhos do no")
// para calcular "número de pais do nó" podemos somar o número de 1s que a parecem no número
// para calcular "número de filhos do nó" contamos x = o número de 0s a esquerda do número X e dizemos
// que o número de filhos é 2^x - 1

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

#define ll long long
#define ull unsigned long long
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

using namespace std;

ll pot[40];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ll x =1;
	fr(i,0,40) pot[i] = x, x = x<<1;
	ll a, b,c,d,e,filhos,pais;
	int t; 
	cin >> t;
	while(t--){
		cin >> a >> b;
		c = (1<<a) | b;
		filhos = 0, pais= 0;
		while( (c & 1) == 0){
			filhos++;
			c = c >> 1;
		}
		filhos = pot[filhos] - 1;
		while( b >0){
			if( b&1) pais++;
			b = b >> 1;
		}
		cout << (pais + 1) << " "  << ( pot[a] - filhos) << endl;
	}
	return 0;
}