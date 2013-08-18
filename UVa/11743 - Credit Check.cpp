
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2843

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, n, m, t, a, b, c;
int num[20];
char nums[50];

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanf("%d\n", &n);
	while(n--) {
		a = b = 0;
		gets(nums);
		j = 0;
		for( i = 0; i < 19; i++){
			if( nums[j] != ' '){
				num[i] = nums[j] - '0';
			} else {
				i--;
			}
			j++;
		}
		/*for( i = 0; i < 16; i++){		
			printf("%d ", num[i]);
		}*/
		for( i = 0; i < 16; i += 2){
			a += (num[i] < 5)? num[i] * 2:  ((num[i] * 2) % 10) + (num[i] * 2 / 10);
			b += num[i+1];	
		}
		if( (a+b) % 10 != 0){
			printf("Invalid\n");
		} else {
			printf("Valid\n" );
		}
	}
	
	return 0;
}

