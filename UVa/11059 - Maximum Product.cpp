//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=233&page=show_problem&problem=2000

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int t, n, a, b, c, d, h , w, i ,j , k, l;
int nums[59];
int resp[1000];
long long aux, m;
int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	a = 1;
	
	while(scanf("%d", &n) > 0){
		memset(nums, 0, sizeof(nums));
		memset(resp, 0, sizeof(resp));
		for( i = 0; i < n; i++){
			cin >> nums[i];
		}
		m = 0;
		for(i = 0; i < n; i++){			
			for(j = 1; j <= n-i; j++){
				aux = 1;
				for( k = i; k < i + j; k++ ){
					aux *= nums[k];
					//cout << k;
				}				
				//cout << " " << aux << endl;
				if( aux > m) m = aux;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", a++, m);
	}
	return 0;
}
