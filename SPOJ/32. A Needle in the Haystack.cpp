//http://www.spoj.pl/problems/NHAY/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>

using namespace std;

int falha[1<<22];

int main(){
	
	int x,j;
	string p, t;
	bool prim = true;
	while(scanf("%d", &x) >0){
		cin >> p;
		cin >> t;
		j = falha[0] = -1;
		for( int i=1;i<=p.size();i++){
			while( j >=0 && p[i-1] != p[j]) j = falha[j];
			falha[i] = ++j;
		}
		j = 0;
		int m = p.size();
		for( int i=0;i<t.size();i++){
			while( j >= 0 && p[j] != t[i]) j = falha[j];
			if( ++j >= p.size()) {	
				printf("%d\n", (i - m + 1));	
				j = falha[j];
			}
		}
		if( prim) prim = false;
		else puts("");
		
	}
	return 0;
}
