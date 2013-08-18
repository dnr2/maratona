//11475 - Extend to Palindrome
//#tag kmp
//#sol usar o kmp e tentar dar o match com a string de entrada e sua inversa
//quando o kmp acabar, retorne o tamanho atual do match, que significa o maior sufixo que é palíndromo

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <sstream>
#include <climits>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

// #define umap unordered_map

using namespace std;

char in[101000], s[101000];

int len;
int f[101000];

int kmp(){
	f[0] = f[1] = 0;
	fr(i,2,len+1){
		int j = f[i-1];
		while(true){
			if( s[j] == s[i-1]) {
				f[i] = j+1; break;
			} else if( !j){ 
				f[i] = 0; break;
			} else  j = f[j];		
		}
	}
	int i = 0, j = 0;
	while(true) {
		if( i == len) return j;
		if( in[i] == s[j] ) i++, j++;		
		else if( j > 0) j = f[j];
		else i++;
	}
	return 0;
}
int main(){
	while(scanf("%s", in) >0){
		int b=0, e = len = strlen(in);
		s[e--] = 0;
		while(b <= e){
			s[b] = in[e];
			s[e] = in[b];
			b++; e--;
		}
		int size = kmp();
		printf("%s", in);
		printf("%s\n" , s+size);
		
	}
	return 0;
}