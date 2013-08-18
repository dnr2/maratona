//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1333
// #tag: math, matemática
// #tag: crivo de eratóstenes

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

bool crivo[1001000];
int i, j , k , num, p[100100];
long long n;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    memset(crivo, true, sizeof(crivo));
    num = 0;
    crivo[0] = crivo[1] = false;
    for(i=2;i<=1000001;){
        for(j=i;j<=1000001;j+=i)
            crivo[j] =false;
        p[num++] = i++;
        while(!crivo[i]) i++;
    }

	while(scanf("%lld" , &n) > 0 && n >= 0){
        for(i=0;i<num;i++){
            while(n%p[i] == 0){
                printf("    %d\n", p[i]);
                n /= p[i];
            }
        }
        if(n != 1) printf("    %lld\n", n);
        printf("\n");
	}
	return 0;
}
