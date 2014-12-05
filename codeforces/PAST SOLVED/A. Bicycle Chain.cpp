//http://www.codeforces.com/contest/215/problem/A

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pair<int,int> pii

using namespace std;

int i,j,k,a,b,c,d, n,m;
int caso =1;

// int crivo[500100];
int as[100];
int bs[100];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	// for( i= 0; i< 500001; i++){
		// crivo[i] = i;
	// }
	// i = 2;
	// while(i<500001){
		// printf("%d\n", i);
		// for( j=i+i;j<500001;j+=i){
			// crivo[j] = i;			
		// }
		// i++;
		// while( crivo[i] != i && i<500001){
			// i++;
		// }
	// }
	
	
	scanf("%d" , &n);
	for( i=0;i<n;i++){
		scanf("%d", &as[i]);
	}
	
	scanf("%d" , &m);
	for( i=0;i<m;i++){
		scanf("%d", &bs[i]);
	}
	int maior = 0;
	int resp =0;
	for( i=0;i<n;i++){
		for(j=0;j<m;j++){
			if( bs[j] % as[i] == 0){
				if( maior < bs[j] / as[i]) {
					maior = bs[j]/as[i];
					resp =1;
				} else if (maior == bs[j] / as[i]){
					resp++;
				}
			}
		}
	}
	printf("%d", resp);
	
	return 0;
}