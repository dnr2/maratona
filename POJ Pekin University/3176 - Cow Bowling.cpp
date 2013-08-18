//http://poj.org/problem?id=3176

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

int n, m, a, b, c, d, i, j, k, h, len, z, resp;
int arr[359][359];

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    scanf("%d", &n);
    FOR(i,n){
        FOR(j,i+1){
            scanf("%d", &arr[i][j]);            
            if( i > 0){
                if( j > 0){
                    arr[i][j] = arr[i][j] + max( arr[i-1][j], arr[i-1][j-1]);
                } else {
                    arr[i][j] = arr[i][j] + arr[i-1][j];
                }
                
            }        
        }              
    }
    m = 0;
    FOR(j, n){
        if( m < arr[n-1][j]) m = arr[n-1][j];
    }
    cout << m;
    return 0;

}
