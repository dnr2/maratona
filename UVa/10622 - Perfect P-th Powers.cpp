//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1563
//#tag math matematica

#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<cstring>
#include<map>
#include<vector>
#include<queue>

using namespace std;

#define ler(a), scanf("%d",&a)
#define ler2(a,b), scanf("%d%d",&a,&b)


int main(){
	
	long long val;
	bool parar;
	while(cin >> val){
		bool neg = val < 0;
		val = abs(val);
		if(val == 0) break;
		parar = false; 
		for(long long i = 2;i<100000 && !parar;i++){
			parar = false; 
			if(val%i == 0){
				long long temp = i;
				int j;
				for(j = 1; temp < val;j++){
					temp = temp*i;
				}
				if( (!neg && temp == val) || (neg && temp == val && j & 1)){
					printf("%d\n", j);
					parar = true;
				}
				
			}
		}
		if(parar) continue;
		printf("1\n");
	}
	return 0;
}
