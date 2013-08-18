//http://www.spoj.pl/problems/QUEST5/
//#tag ad hoc 
//#tag pilha stack
//#tag sort
//#sol: vá percorrendo os valores de intervalos do menor para o maior, perceba que quando você
// chegar em um valor que é o fim de um intervalo, significa que você TEM que usar tirar uma foto para
// aquele intervalo ou antes, então todos que apareceram com valores de início de intervalo devem
// ser excluídos.

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

struct p{
	int x, id, d;
	p( int a=0, int b=0, int c=0): x(a), id(b), d(c) {}
	bool operator < ( const p & in) const {
		if( x == in.x) return d < in.d;
		return x < in.x;
	}
};

p arr[30110];
stack<p> pilha;
bool mark[30110];

int i,j,k,n,m,a,b,c,d;

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		scanf("%d", &n);
		while(!pilha.empty()){
			pilha.pop();
		}
		for(i=0;i<n;i++){
			scanf("%d%d", &a, &b);
			p aux1( a, i, 1);
			p aux2( b, i, 2);
			arr[(2*i)] = aux1;
			arr[(2*i) + 1] = aux2;
		}
		sort( arr, arr + (2 * n));
		n *= 2;
		int resp =0;
		for( i=0;i<n;i++){
			// printf("%d %d %d\n", arr[i].x, arr[i].id, arr[i].d);
			if( !mark[arr[i].id]){
				if( arr[i].d  == 1){
					pilha.push(arr[i]);
				} else {
					while(!pilha.empty()){
						mark[pilha.top().id] = true;
						pilha.pop();
					}
					resp++;
				}
			}
		}
		printf("%d\n", resp);
		for(i=0;i<n;i++){
			mark[i] = false;
		}
	}
	return 0;
}


