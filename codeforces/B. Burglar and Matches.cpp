//http://www.codeforces.com/problemset/problem/16/B

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, a, b, c, d, i, j, p, aux, x[15];
//char str[20];
bool y; 
 
struct cont{
    int ai;
    int bi;
};
 
cont con[25];
 
bool cmp( cont y, cont z){
    return y.bi > z.bi;
}
 
int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    aux = 0;
    scanf("%d %d", &n, &m);  
    for( i = 0; i < m; i++){        
        scanf("%d %d", &con[i].ai, &con[i].bi);              
    }
    sort( &con[0], &con[m], cmp);
    for( i = 0; i < m; i++){        
        for( j = 0; j < con[i].ai; j++){
            if( n > 0){
                aux += con[i].bi;
                n--;
            } else {
                break;
            }                
        }  
         
    }
    
    printf("%d", aux);
    
    /*
    if(y) {
        printf("OK");
    } else {
     printf("WRONG_ANSWER");
    }
    */
    	
    return 0;

}
