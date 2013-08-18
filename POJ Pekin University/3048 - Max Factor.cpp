//http://poj.org/problem?id=3048

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

int n, m, i, j, k, len, z, resp, t;
int arr[5009];
bool crivo[30500];
int primes[30500];


int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    crivo[0] =false;
    memset(crivo, true, sizeof(crivo));
    primes[0] = 1;
    len = 1;
    FORC(i,2,30005){
        while( i < 30405 && !crivo[i]){
            i++;
        }
        primes[len] = i;
        len++;
        for(j = 2*i; j < 30405; j+= i){
            crivo[j] = false;
        }                
    }
    /*FOR(i,len -3){
        cout << primes[i]  << endl;
    }*/
    
    cin >> t;
    m = 0;
    FOR(i,t){
        scanf("%d", &arr[i]);
        for( j = len -4; j >= 0; j--){
            if( (arr[i] % primes[j]) == 0){
                if( m < primes[j] ){
                    m = primes[j];
                    resp = arr[i];
                }
                break;
            } 
        }
    }
    cout << resp;
    
    
    return 0;

}
