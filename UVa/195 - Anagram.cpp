//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=131

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <stack>
#include <list>

using namespace std;

int n, m, i, j, k, len, resp, t, K;

char str[1000];

char lower_case(char x) {
	if( x <= 'Z' ) return x + 'z' - 'Z';
	return x;
}

bool comp(const char & a, const char & b) {
	if( lower_case(a) == lower_case(b) ) return a < b;
	return lower_case(a) < lower_case(b);
}

int main(){

    //freopen("in.txt", "r", stdin );
	//freopen("out.txt", "w", stdout );    
    
	scanf("%d", &n);
	while( n--){
		scanf("%s", str);
		sort( str ,  str + (strlen(str)), comp );
		do{
			printf("%s\n", str);
		} while( next_permutation( str ,  str + (strlen(str)) , comp));		
	}

}
