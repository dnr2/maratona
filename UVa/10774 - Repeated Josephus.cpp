//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1715
//#tag math matematica
//#sol usar o padrão de que a sequencia eh 1, 1 3, 1 3 5 7 ..., ou seja a sequencia de ímpares até 
// i ^2, fazer precomputação das sequencias e depois usálas para achar a resposta

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

int pre[60100];
int mark[60100];

int main() {

	//freopen("a.txt","r", stdin);
	//freopen("out2.txt","w", stdout);
	int n, a, b, maior, menor, caso =1, aux;
	
	for( int i = 1, j = 1; j < 30100;i *= 2){
		int aux = 1;
		for( int k = 0; k < i && j < 30100; k++){
			pre[j++] = aux;
			//printf("%d\n", aux); 
			aux+=2;
		} 
	} 
	scanf("%d", &n);
	while(n--){
		scanf("%d", &a);
		int cont = 0;
		while( a != pre[a]){
			a = pre[a];
			cont++;
		}
		printf("Case %d: %d %d\n", caso++ ,  cont, a);
	}
	
	
	
	return 0;	
}

