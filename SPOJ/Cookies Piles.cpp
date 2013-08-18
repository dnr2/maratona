//http://www.spoj.pl/problems/AMR10F/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, A, D;



int main(){
    
    
    //freopen("in.txt", "r" , stdin);
    //freopen("out.txt", "w" , stdout);
    
    int result;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &N, &A, &D);
		result = 0;
		for( int cont = 0; cont < N; cont++){
			result += A + D * cont;
		}
		printf("%d\n", result);
	}
	   
    
    return 0;
}
