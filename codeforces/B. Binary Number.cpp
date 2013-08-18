//http://codeforces.com/problemset/problem/92/B

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, a, b, c, d, i, j, p, aux;
char str[10000005];
bool y; 
 
int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    
    
    aux = 0;
    scanf("%s", &str);     
    p = strlen(str);
    p--;
    aux = 0;
    
    if( p == 0 && str[0] == '1'){
        printf("0");
    } else {
        while( p > 0 ){
            if( str[p] == '0'){
                p--;                               
                aux++;
                //printf("%d\n", aux);
            } else {
                y = false;
                aux++;                
                for( i = 0; i <= p; i++){
                    if( str[i] == '0'){                        
                        y = true;
                        break;
                    }
                }
                if(y){
                    a = p;                    
                    while( str[a] == '1' ){
                       aux++;
                       a--; 
                    }
                    str[a] = '1';
                    p = a;
                } else {
                    aux += p + 1;                    
                    p = -1;
                }                
            }

        }
        printf("%d", aux);
    }
    
    
    	
    return 0;

}
