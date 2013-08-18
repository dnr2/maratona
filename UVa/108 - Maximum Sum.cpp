//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int i,j,k,a,b,c,d,n,m,t,caso = 1, begin, end;
int in[101][101], aux[101];

int main(){
	
	while(scanf("%d", &t) > 0){
		
		int resp = -10000;
		for( i = 0 ; i< t; i++){
		    for( j =0 ; j < t; j++){   
		        scanf("%d", &in[i][j]);
		        resp = max(resp, in[i][j]);
		    }
		}
		int big = 0;
		for( i = 0 ; i< t; i++){
		    memset(aux, 0 , sizeof(aux));
		    for( j =i; j < t; j++){  
		        for( k =0; k < t; k++){
		            aux[k] += in[j][k];
		        }
    		    int sum = 0;
		        for( k =0; k < t; k++){
                    sum = max( sum + aux[k], aux[k]);
                    big = max( sum, big);
		        }
		    }
		}
		if( big == 0){
		    printf("%d\n", resp);
		} else {
		    printf("%d\n", big);
		}
		
	}
	return 0;
}

