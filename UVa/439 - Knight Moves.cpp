//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, a, b, c, d ,m ;
int p, q, k , n, e;

char s1[10], s2[10];

int arr[8][8];


int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);	
	
	while(scanf("%s %s", s1, s2) > 0){	
		a = s1[0] - 'a';
		b = s1[1] - '1';
		c = s2[0] - 'a';
		d = s2[1] - '1';
		bool fim = false;
		memset( arr, 0, sizeof(arr));
		arr[a][b] = 1;
		for( i = 2; !fim; i++){
			fim = true;
			for( j = 0; j < 8; j++){
				for( k = 0; k < 8; k++){
					if(arr[j][k] == i-1){
						fim = false;
						if( j - 2 >= 0 && k - 1 >= 0 && !arr[j-2][k-1]  ){
							arr[j-2][k-1] = i;
						}
						if( j - 2 >= 0 && k + 1 < 8 && !arr[j-2][k+1]){
							arr[j-2][k+1] = i;
						}
						if( j - 1 >= 0 && k - 2 >= 0 && !arr[j-1][k-2]){
							arr[j-1][k-2] = i;
						}
						if( j - 1 >= 0 && k + 2 < 8 && !arr[j-1][k+2]) {
							arr[j-1][k+2] = i;
						}
						if( j + 1 < 8 && k - 2 >= 0 &&  !arr[j+1][k-2]){
							arr[j+1][k-2] = i;
						}
						if( j + 1 < 8 && k + 2 < 8 && !arr[j+1][k+2]){
							arr[j+1][k+2] = i;
						}
						if( j + 2 < 8 && k - 1 >= 0 && !arr[j+2][k-1]){
							arr[j+2][k-1] = i;
						}
						if( j + 2 < 8 && k + 1 < 8 && !arr[j+2][k+1]){
							arr[j+2][k+1] = i;
						}
					}
				}
			}
			if(arr[c][d]){
				fim = true;
				printf("To get from %s to %s takes %d knight moves.\n", s1, s2, arr[c][d]-1);
			}
		}
	
	}
	
	return 0;
}
