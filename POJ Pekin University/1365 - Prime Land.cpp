//poj.org/problem?id=1365

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

int i, j, k, p , e;
int n , m;
int a, b , c, d, sum, resp;
int crivo[33000];

char str[1000];

int diginum(int x){
	int y = 0;
	while( x > 0){
		x /= 10;
		y++;
	}	
	return y;
}

int main(){

	//freopen( "in.txt", "r", stdin);
	//freopen( "out.txt", "w", stdout);	
	
	memset( crivo, 1, sizeof(crivo));
	crivo[0] = crivo[1] = 0;
	
	for( i =  2; i <= 32767;  i = i){
		for( j = i + i; j <=  32767; j += i){
			crivo[j] = 0;
		}
		i++;
		while( crivo[i] == 0){
			i++;
		}
	}
	
	gets(str);
	while(str[0] != '0'){
		sum = 0;
		int off = 0;
		sum = 1;		
		while( sscanf(str + off, "%d %d", &p, &e) == 2){
			a = 1;
			for( i = 0; i < e; i++){
				a *= p;
			}
			sum *= a;
			//printf("%d off: %d ", a , off);
			off += diginum(p) + diginum(e) + 2;
		}
		//printf("\n%d\n", sum);
		sum--;
		bool primeiro = true;
		for( i = sum; i > 0; i--){
			if( crivo[i] && sum % i == 0){
				b = 0;
				while( sum % i == 0 ){
					b++;
					sum /= i;
				}
				if( !primeiro) printf(" ");
				else primeiro = false;
				printf("%d %d", i, b);
			}
		}
		printf("\n");
		memset(str, 0, sizeof(str));
		gets(str);
		
	}
	
	return 0;
}


