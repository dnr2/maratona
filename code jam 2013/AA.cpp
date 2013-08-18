#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include <ctype.h>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long
#define PI acos(-1)
#define EPS 1e-9

using namespace std;

char in[1000010];
int ini[1000010];
int fim[1000010];

bool isvowel( char a){
	return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' );
}


int main(){
	
	int ca=0, caso =1, n;
	scanf("%d",&ca);
	while( ca--){	
		cl(in);
		scanf("%s %d", in , &n);
		int len = strlen(in);
		fr(i,0,len+1) fim[i] = len;		
		ll resp =0;
		int cont = 0;
		int x = 0;
		fr(i,0,len){
			if( !isvowel(in[i])) cont++;
			else {				
				if( cont >= n ) fim[x-1] = i;
				cont = 0;
			}
			if( cont == n) ini[x++] = i;
		}
		if( x == 0) {
			printf("Case #%d: %d\n", caso++, 0); continue;
		}
		int a = 0;
		fr(i,0,len){
			if( a < x && i > (fim[a] - n) ) a++;
			if( a < x ) resp += len - max( ini[a] , i + n - 1);			
		}		
		printf("Case #%d: %lld\n", caso++, resp);
	}
	return 0;
}
