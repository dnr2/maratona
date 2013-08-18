//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=484
//#tag math matematica
//#tag crivo sieve

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>

#define pii pair<int,int>
#define F first 
#define S second
#define MAP map<int,int>
#define FOR(i,j,k) for(int (i) = (j); (i) < (k); ++(i))
#define MAXN 1000000
using namespace std;

bool crivo[MAXN * 2]; int p[MAXN];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int len = 0;
	memset(crivo,false,sizeof(crivo));
	memset(p,0,sizeof(p));
	FOR(i,2,MAXN + 100){
		if( !crivo[i]){			
			p[len++] = i;
			for( int j=i+i;j < MAXN+50;j+=i) crivo[j] = true;
		}
	}
	int n;
	while(scanf("%d", &n ) > 0  && n){	
		int a = 0, b = 0;
		for(int i=0;i<len;i++){
			int j = lower_bound(p,p+len, n-p[i]) -p;			
			if( (p[i] + p[j]) == n ) {
				a = p[i], b = p[j];
				break;
			}
		}
		if( a || b )printf("%d = %d + %d\n", n, a, b);
		else puts("Goldbach's conjecture is wrong.");
	}
	return 0;
}
