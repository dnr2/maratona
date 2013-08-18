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

char in[110];

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
		int resp = 0;
		fr(i,0,len){
			fr(j,i,len){
				int aux = 0;
				int cons = 0;
				fr(k,i,j+1){
					if( !isvowel(in[k]) ) cons++;
					else cons = 0;
					aux = max(aux,cons);
				}
				if( aux >= n) { resp++; }
			}
		}
		printf("Case #%d: %d\n", caso++, resp);
	}
	return 0;
}
