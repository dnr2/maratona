//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2482

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

char str[300];

int i, j , k , n , m, resp;

int a, b , c, d;

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	
	
	while(scanf("%s", str)> 0 && str[0] != '*'){
		a = 0;
		resp = 0;
		for( i = 1; str[i]; i++){
			
			if( str[i] == '/'){
				if( a == 64){
					resp++;
				}
				a = 0;
			} else {
				switch(str[i]){
					case 'W':
						a += 64;
					break;
					case 'H':
						a += 32;
					break;
					case 'Q':
						a += 16;
					break;
					case 'E':
						a += 8;
					break;
					case 'S':
						a += 4;
					break;
					case 'T':
						a += 2;
					break;
					case 'X':
						a += 1;
					break;
					
				}
			}
		}		
		printf("%d\n", resp);
					
	}
	
	return 0;
}
