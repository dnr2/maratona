//http://poj.org/problem?id=1979

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>


#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
#define FORC(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));


using namespace std;

int n, m, a, b, c, d, i, j, k, len, z, resp, t;
char arr[29][29], str[29];
//int nums[100009];

int walk(int y, int x){
    arr[y][x] = 'W';
    int ret = 0;
    if( y-1 >= 0 && arr[y-1][x] == '.'){    
        ret += walk(y-1, x);        
    }
    if( x-1 >= 0 && arr[y][x-1] == '.'){    
        ret += walk(y, x-1);        
    }
    if( arr[y+1][x] == '.'){    
        ret += walk(y+1, x);        
    }
    if( arr[y][x+1] == '.'){    
        ret += walk(y, x+1);        
    }    
    return ret + 1;
}

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    scanf("%d %d", &m, &n);
    while(m != 0 || n != 0){
        FOR(i,n){
            scanf("%s", &arr[i]);
            //cout << arr[i] << endl;
        }
        FOR(i,n){
            FOR(j,m){
                //cout << arr[i][j];  
                if(arr[i][j] == '@'){
                    printf("%d\n", walk(i,j));
                    break;
                }
            }
            //cout << endl;
        }
        memset( arr, 0, sizeof(arr));            
        scanf("%d %d", &m, &n);
    }    
    
    return 0;

}
