//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=272&problem=71&mosmsg=Submission+received+with+ID+926624


#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>


#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
#define FORC(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));


using namespace std;

int n, m, b, c, d, i, j, k, h, len, z, resp;
char a[209][209], str[209];


int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );

    scanf("%d", &m);
    while( m != 0){
        
        
        
        memset( str, 0, sizeof(str));
            
        scanf("%s", &str);
        len = strlen(str);
        n = len / m;
        h = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                a[i][j] = str[h];
                //printf("%c", a[i][j]);
                h++;
            }
            //printf("\n");
        }
        bool stop = false;
        c = 0; d = 1;
        i = 0; j = 0;
        
        while(!stop){            
            printf("%c", a[i][j]);
            //P2INT(i,j);
            i++;
            j--;
            len--;
            if(j < 0 || i >= n) {
                j = d;
                i = c;
                if( d <=  m - 2){
                    d++;             
                } else{
                    c++;
                }   
            }
            if(!len) stop = true;
                                      
        }
        printf("\n");
        
        scanf("%d", &m);
    }
    
    return 0;

}


