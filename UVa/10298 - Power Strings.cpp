//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1239
//#tag kmp

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
	string p;
	while(cin >> p){
		
		if(p.size() == 1 && p[0] == '.') break;
		j = falha[0] = -1;
		for( int i=1;i<=p.size();i++){
			while( j >=0 && p[i-1] != p[j]) j = falha[j];
			falha[i] = ++j;
		}
		int len = p.size();
		printf("%d\n", len / (len -falha[len]));
	}
	return 0;
}
