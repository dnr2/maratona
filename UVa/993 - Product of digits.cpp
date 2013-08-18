//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=934

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, a, b, c, n, m, t;
int nums[10];
int primes[] = {2, 3,5 ,7}; 

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanf("%d", &t);
	while(t--){
		memset(nums, 0, sizeof(nums));
		scanf("%d", &n);
		if( n <= 1){
			printf("%d\n", n);
		} else {
			for(i = 0; i < 4; i++){
				while( n % primes[i] == 0){
					//cout << n << " " << primes[i] << endl;
					n /= primes[i];
					nums[primes[i]]++;
				}
			}
			
			
			if( n > 1){
				printf("-1\n");		
			} else {
				a = nums[2] % 3;
				b = nums[3] % 2;
				nums[8] += nums[2] / 3;
				nums[2] = a;
				nums[9] += nums[3] / 2;
				nums[3] = b;
				if( a == 2 && b == 0){
					nums[2] = 0;
					nums[4] = 1;
				} else if( a == 1 && b == 1){
					nums[2] = 0;
					nums[3] = 0;
					nums[6] = 1;
				} else if( a == 2 && b == 1){
					nums[2] = 1;
					nums[3] = 0;
					nums[6] = 1;
				}
				for( i = 0; i < 10; i++){
					for( j = 0; j < nums[i]; j++){
						printf("%d", i);
					}
				}
				printf("\n");
			}
		}
		
		
		
		
	}
	
	return 0;
}

