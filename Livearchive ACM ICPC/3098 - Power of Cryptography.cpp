//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1099

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, a, b, c, d ,m ;
double p, q, k , n;


int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
    
	while( 	( cin >> n >> p ) > 0){		
		k = pow(10,(log10(p) / n));
		printf("%.0lf\n", k );		
	}
	
	return 0;
}
