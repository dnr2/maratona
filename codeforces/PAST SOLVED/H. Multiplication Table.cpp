//http://www.codeforces.com/problemset/problem/39/H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORC(i,j,n) for((i)=(j);(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)

using namespace std;

int n, m, a, b, c, d, i, j, h, len, xi[10005], resp;
bool as;

int convert(int base, int x){
    resp = 0;
    a = 1;
    while( x > 0){
        resp += x%base * a; 
        x = x/base;
        a = a * 10;
    }
    return resp;
}

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    scanf("%d", &n );
    
    for(i = 1; i < n; i++){
        for(j = 1; j < n; j++){
            printf("%d ", convert(n, i*j));
        }
        printf("\n");        
    }        
    
    return 0;

}


