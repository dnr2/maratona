//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2870
//#tag: max sum contiguous subsequence 
//#tag: Problem solving paradigm



#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>

#define FOR(i,s,n) for( (i) = (s); (i) < (n); (i)++)

using namespace std;

int  i, j, k, m, n, a, b, c, d;

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d" , &n) > 0 && n != 0){
		a = b = 0;
		scanf("%d", &b);
		a = b;
		n--;
		while(n--){
			scanf("%d", &c);
			b = max( b+c, c);
			a = max(a, b);						
		}
		printf("%d\n", a);
	}
		
	
	return 0;
}