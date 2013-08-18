//http://www.spoj.pl/problems/HEPNUM/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, n, m, t, a, b, c;
char num[2][1000000];

bool maior, igual;

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int mi;
	
	while( scanf("%s %s", &num[0], &num[1]) > 0 && num[0][0] != '*') {
		
		a = strlen(num[0]);
		b = strlen(num[1]);
		
		for( n = 0; n < a  && num[0][n] == '0'; n++);
		for( m = 0; m < b  && num[1][m] == '0'; m++);
		igual = true;
		
		if( a - n < b - m){
			printf("<\n");
		} else if( a - n > b - m){
			printf(">\n");
		} else {		
			for( i = n, j = m; i < a && j < b; i++, j++){
				if( num[0][i] < num[1][j]){
					igual = false;
					printf("<\n");
					break;
				} else if( num[0][i] > num[1][j] ) {
					igual = false;
					printf(">\n");
					break;
				}
			}
			if( igual){
				printf("=\n");
			}
			
		}
		
	}
	
	return 0;
}

