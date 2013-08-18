//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1620
//#tag KMP
//#sol KMP simple solution

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int a,b,c,d;
char S[100100];
char T[1100];

int fail[1100]; //TODO

void buildFail(char * p){
	int m = strlen(p);
	int j = fail[0] = - 1;
	for( int i =1;i <= m;i++){
		while( j >= 0 && p[j] != p[i-1]) j = fail[j];
		fail[i] = ++j;
	}
}

bool kmp(char * p, char * t){
	int m = strlen(p); 
	int n = strlen(t);
	buildFail(p);
	for( int i =0, k=0; i< n;i++){
		while( k >=0 && p[k] != t[i]){
			// cout << "a" << endl;
			k = fail[k];
		}
		if( ++k >= m){
			return true;
			k = fail[k];
		}
	}
	return false;
}


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	
	while(t--){
		scanf("%s", S);
		scanf("%d", &a);
		for( int i=0;i<a;i++){
			scanf("%s", T);
			memset(fail, 0, sizeof(fail));
			// cout << T << endl;
			printf("%c\n", kmp( T, S)? 'y' : 'n');
		}
	}


	return 0;
}

