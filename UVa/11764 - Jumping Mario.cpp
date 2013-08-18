//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2864
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int t, n, m , a, b, c, d, aux, h , w, i ,j , l;
int nums[59];

int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	cin >> t;
	a = 1;
	while(t--){
		cin >> n;
		for( i = 0; i < n; i++){
			cin >> nums[i];
		}
		c = 0; d = 0;
		for( i = 1; i < n; i++){
			if( nums[i] > nums[i-1]){
				c++;
			} else if(nums[i] < nums[i-1]) {
				d++;
			}
		}
		printf("Case %d: %d %d\n", a++, c ,d);
	}
	return 0;
}
