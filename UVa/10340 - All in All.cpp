//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1281&mosmsg=Submission+received+with+ID+9231533


#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m, a, b, c, d, i, j, k, h, len, y[10], x[5][1000000], resp;
char ss[100000], st[100000], aux;

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    bool br;
    
    while( scanf("%s %s", &ss, &st) > 0){
        br = false;
        int sslen = strlen(ss); 
        int stlen = strlen(st);
        a = 0;       
        if(sslen <= stlen){
            aux = ss[a]; 
            for( i = 0; i < stlen; i++){
                if(aux == st[i]){
                    a++;
                    if( a == sslen) {
                        br = true;
                        break;
                    }
                    aux = ss[a];
                }
            }          
        }           
        if(br) printf("Yes\n");
        else printf("No\n");
        
    }
    return 0;

}


