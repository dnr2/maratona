//http://www.spoj.pl/problems/LMIS/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int in[1001000];
int pd[1001000];

int main(){
	int cont = 0, n, k,a;
	while( scanf("%d", &a) > 0){
		in[cont++] = a;
	}
	n = 0;
	for( int i =0; i< cont; i++){
		k = upper_bound(pd, pd + n, in[i]) - pd;
		if( n == k) n++;
		pd[k] = in[i];
		
	}
	printf("%d\n", cont - n);
	return 0;
}
