//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615

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

int i, j, k, l ;
int n , m;
int a, b , c, d, sum;

int  arr[7490];
int coins[] = {1 , 5, 10, 25, 50};

int main(){
	
	//freopen( "in.txt", "r", stdin);
	//freopen( "out.txt", "w", stdout);
	
	memset(arr, 0, sizeof(arr));
	
	arr[0] = 1;
	for( i = 0; i < 5; i++){
		for( j = 0; j < 7490; j++){
			if( j + coins[i] < 7490){
				arr[j + coins[i]] += arr[j];
			}
		}		
	}
	// for( j = 0; j < 7490; j++){		
		// printf("%d\n", arr[j]);
	// }
	while(scanf("%d", &n) > 0){
	   printf("%d\n", arr[n]);
	}	
	return 0;
}


