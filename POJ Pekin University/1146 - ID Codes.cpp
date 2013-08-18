//http://poj.org/problem?id=1146

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

int i, j, k, l , t;
int n , m;
int a, b , c, d, sum, resp;

char str[60];

int main(){
	
	//freopen( "in.txt", "r", stdin);
	//freopen( "out.txt", "w", stdout);
	
	while(scanf("%s", str) > 0 && str[0] != '#'){			
		l = strlen(str);		
		if( next_permutation( str, str + l)){
			printf("%s\n", str);
		} else {
			printf("No Successor\n");
		}
	}
	
	return 0;
}


