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
double p, q, k , n, e;


int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    
	while( 	( cin >> n ) > 0){	
		bool achou = false;
		for( k = floor(log10(n)) + 1; !achou ;k++){
			p = (log10(n) + k) / log10(2);
			q = (log10(n+1) + k) / log10(2);
			for( e = 1; e < (log10(n + 1) + k )/ log10(2); e++){
				if( e >= (log10(n) + k )/ log10(2) ){
					achou = true;
					cout << e << endl;
				}
			}
		}
	}
	
	return 0;
}
