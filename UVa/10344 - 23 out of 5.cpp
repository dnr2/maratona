//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1285

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

int a, b , c, d, e, i, j, k, l , n , m, maxn;
int num;
int nums[5];

int main(){
	
	//freopen( "in.txt", "r", stdin);
	//freopen( "out.txt", "w", stdout);
		
	while(scanf("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4])  && nums[0] ){
		
		num = 0;
		bool fim = false;
		for( i = 0 ; i < 3 && !fim; i++){
			for( j = 0 ; j < 3 && !fim;j++){
				for( k = 0 ; k < 3 && !fim; k++){
					for( l = 0 ; l < 3 && !fim; l++){
						sort(nums, nums+5);						
						do{
							switch(i){
								case 0:
									num = nums[0] + nums[1];
								break;
								case 1:
									num = nums[0] - nums[1];
								break;
								default:
									num = nums[0] * nums[1];
							}
							switch(j){
								case 0 :
									num = num + nums[2];
								break;
								case 1 :
									num = num - nums[2];
								break;
								default:
									num = num * nums[2];
							}
							switch(k){
								case 0: 
									num = num + nums[3];
								break;
								case 1:
									num = num - nums[3];
								break;
								default:
									num = num * nums[3];
							}
							switch(l){
								case 0: 
									num = num + nums[4];
								break;
								case 1:
									num = num - nums[4];
								break;
								default:
									num = num * nums[4];
							}
							if( num == 23) {
								//printf("Possible -> %d %d %d %d %d - > ops: %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3], nums[4], i, j, k, l);
								printf("Possible\n");
								fim = true;
							}
						} while( next_permutation(nums, nums+5) && !fim);
					}
				}
			}
		}
		if( !fim ) printf("Impossible\n");
		
		
	}
	
	return 0;
}


