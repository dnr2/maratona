//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
//#tag data structure map
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int t, n, m , a, b, c, d, aux, h , w, i ,j , l;

int pai[30009];
int nums[30009];
bool tempai[30009];

int find(int num){
	int bla;
	if( pai[num] == num) return num;
	bla = find(pai[num]);
	pai[num] = bla;
	return bla;
}

int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int p = 0;
	scanf("%d", &t);
	while( t--){
		memset(pai, 0, sizeof(pai));
		memset(nums, 0, sizeof(nums));
		scanf("%d %d", &n, &m);
		
		for( i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			if( pai[a] == 0 && pai[b] == 0){
				pai[a] = pai[b] = a;
				nums[a] += 2;
			} else if ( pai[a] != 0 && pai[b] == 0 ){
				p = pai[b] = find(a);
				nums[p] += 1;
			} else if ( pai[a] == 0 && pai[b] != 0 ){
				p = pai[a] = find(b);
				nums[p] += 1;
			} else {
				p = find(a);
				h = find(b);
				pai[h] = p;
				if( p != h){
					nums[p] += nums[h];
					nums[h] = 0;
				}				
			}
		}
		m = 0;
		for( i = 1; i <= n; i++){
			if( m < nums[i]) m = nums[i];
		}
		printf("%d\n", m);
	}
	return 0;
}
