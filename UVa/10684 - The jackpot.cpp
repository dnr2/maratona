//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1625

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

int a, b , c, d, i, j, k, n , m, maxn;
int arr[10100], pd[10100];
int main(){
	
	freopen( "in.txt", "r", stdin);
	freopen( "out.txt", "w", stdout);
	
	while( scanf("%d", &n) > 0 && n){		
		for( i = 0; i < n ; i ++){
			scanf("%d", &arr[i]);			
		}
		memset(pd, 0, sizeof(pd));
		maxn = 0;
		
		if( arr[0] > 0 ) pd[0] = arr[0];
		for( i = 1; i < n ; i ++){
			if( pd[i - 1] + arr[i] > 0) {
				pd[i] = pd[i - 1] + arr[i];
				if( pd[i] > maxn ) maxn = pd[i];
			}
		}
		if( maxn > 0) printf("The maximum winning streak is %d.\n", maxn);
		else printf("Losing streak.\n");
		
	}
	
	return 0;
}


