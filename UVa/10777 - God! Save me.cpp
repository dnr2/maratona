//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1718
//#tag combinatories combinatória
//#tag math matematica
//#sol fazer a média ponderada dos valores de tempo associados com suas probabilidades e depois
//dividir pela soma das probabilidades das portas que levam você para fora da sala

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
struct Objeto{
	double tempo, p;
	Objeto(){}
	Objeto(double a, double b):tempo(a),p(b){}
};
Objeto objetos[1001];
bool marcados[1001];

int main() {
	
	//freopen("a.txt","r",stdin);
	int qtd, caso = 1, n;
	double a, b;
	scanf("%d",&qtd);
	while(qtd--){
		memset(marcados,false,sizeof(marcados));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&a,&b);
			if(a>0){
				marcados[i] = true;
			}else{
				marcados[i] = false;
				a *= -1;
			}
			objetos[i].tempo = a;
			objetos[i].p = b;
		}
		double soma = 0 ;
		for(int i =1;i<=n;i++){
			soma += objetos[i].tempo*objetos[i].p;
		}
		double div = 0;
		int cont = 0;
		for(int i =1;i<=n;i++){
			if(marcados[i]){
				div += objetos[i].p;
				cont++;
			}
		}
		if(cont == 0){
			printf("Case %d: God! Save me\n",caso++);
		}else
			printf("Case %d: %.2lf\n",caso++, soma/div );
	}
	return 0;	
}

