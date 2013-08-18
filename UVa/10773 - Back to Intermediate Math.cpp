//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1714
//tag math matematica
//tag vetores vectors
//tag fisica 
//sol solução straight forward, só calcular o tempo a partir das distância e do vetor velocidade, 
//considerando que o vetor velocidade do percurso de menor distância sofre influência do vetor 
//velocidade da mare

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

using namespace std;

vector<int> lista;

int main() {

	//freopen("a.txt","r", stdin);
	int n, maior, menor, caso =1;
	double a, b,c,d;
	scanf("%d", &n);
	while(n--){
		scanf("%lf %lf %lf", &a, &b, &c);
		if( c <= b || b == 0.0){
			printf("Case %d: can't determine\n",caso++);
		} else {
			d = sqrt( pow( c, 2) - pow( b,2));
			d = fabs((a / c) - (a / d));
			printf("Case %d: %.3lf\n",caso++, d);
		}
		
	}
	
	return 0;	
}

