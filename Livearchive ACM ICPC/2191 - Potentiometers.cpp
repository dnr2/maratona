//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=192
//#tag seg tree / arvore de segmentos

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int val[1<<25];

void at( int p , int x, int r, int i, int j){
    if( i == j) val[r] = x;
    else {
        int m = (i + j) /2;
        if( p <= m) at( p, x, 2 * r, i , m);
        else at(p, x, (2 * r)  + 1, m+1, j);
        val[r] = val[2 * r] + val[ (2*r)  +1];
    }
}

int query( int ini, int fim, int n, int i, int j ){
    if( ini > j || fim < i) return 0;
    if( ini <= i && j <= fim) return val[n];
    int m = (i+j) /2;
    return query( ini, fim, 2*n, i , m) + query(ini, fim , 2*n + 1, m +1 , j);
}

int i,j,k,a,b,c,d,n,m,t,caso = 1, begin, end;
char str[10];

int main(){
    bool start = true;
	while(scanf("%d", &t) > 0 && t != 0){
	    
		memset( val ,0 , sizeof(val));
		for( i =1 ; i <= t; i++){    
		    scanf("%d", &a);
		    at( i, a, 1, 1, t << 2);
		}
		
		if( !start) puts("");
		else start = false;
		printf("Case %d:", caso++); puts("");
		while(scanf("%s", str) > 0){
		    if(str[0] == 'M'){
		       scanf("%d%d", &a, &b);
		       printf("%d", query( a, b, 1, 1, t << 2)); puts("");
		    } else if( str[0] == 'S'){
		       scanf("%d%d", &a, &b);
		       at( a, b, 1, 1, t << 2);
		    } else {
		        break;
		    }
		}  
	}
	return 0;
}

