//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=898

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, a, b, c, d, n, m;
int arr[100100];
int sums[100100];
int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int y = 0;
	int p = 0;
	
	
	while(scanf("%d", &y) > 0){
		scanf("%d", &p);
		memset(arr, -1, sizeof(arr));
		memset(sums, 0, sizeof(sums));
		
		for( i = 0 ; i < p; i++){
			scanf("%d" , &arr[i] );		
		}
		
		for( i = 0; i < p; i++){
			b = 0;
			while( arr[i + b] >= 0 && arr[i + b] < arr[i] + y ){
				b++;
			}
			sums[i] = b;
			//printf("%d\n", sums[i]);
		}
		m = 0 ;
		//printf("\n");
		for( i = 0; i < p; i++){
			if( m < sums[i]) {
				m = sums[i];
				n = i;
				//printf("%d %d\n", sums[i], arr[i]);
			}
		}
		printf("%d %d %d\n", m, arr[n], arr[n+m-1]);
	}
	
	return 0;
}

