

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, k, a, b, c, d, n ,m;
int e;
char str[1100];
int nums[10];

int main(){

	freopen("alphabet_soup.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d\n", &n);
	c = 1;
	while(n--){
		memset( str, 0 , sizeof(str));
		memset( nums, 0 , sizeof(nums));
        gets(str);
		for( j = 0 ; str[j]; j++){
				switch(str[j]){
					case 'H': nums[0]++; break;
					case 'A': nums[1]++; break;
					case 'C': nums[2]++; break;
					case 'K': nums[3]++; break;
					case 'E': nums[4]++; break;
					case 'R': nums[5]++; break;
					case 'U': nums[6]++; break;
					case 'P': nums[7]++; break;
				}
		}
		nums[2] /= 2;
		int menor = 1000000;
		// for( i = 0 ; i < 8; i++){
           // printf("%d ", nums[i]); 
        // }
		for( i = 0 ; i < 8; i++){
			menor = min( menor, nums[i]);
		}
		printf("Case #%d: %d\n", c++, menor);
	}
	
	return 0;
}
