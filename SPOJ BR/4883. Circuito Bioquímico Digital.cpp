//http://br.spoj.pl/problems/CIRCUITO/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, a, b, c, d, n, m, resp;
int arr[1010][1010];
int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int y = 0;
	int p = 0;
	
	
	while(scanf("%d %d %d", &p, &n, &c ) > 0 && c != 0 || p != 0 || n != 0 ){
		
		resp = 0;
		for( i = 0; i < n; i++){
			for( j = 0 ; j < p; j++){
				scanf("%d", &arr[i][j]);
			}
		}
		a = 0;
		for( j = 0 ; j < p; j++){
			for( i = 0; i < n; i++){			
				if(arr[i][j] ){
					a++;
				} else {
					if( a >= c ){
						resp++;
					}
					a = 0;
				}
			}
			if( a >= c ){
				resp++;
			}
			a = 0;			
		}
		printf("%d\n", resp);		
		
	}
	
	return 0;
}

