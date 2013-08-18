//http://www.codeforces.com/problemset/problem/119/A

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

int gcd(int x, int y){
    
    for(int i = max(x,y); i >= 1; i--){
        if( x%i == 0 && y%i == 0){
            return i;
        }
    }
    return max(x,y);
}

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    scanf("%d %d %d", &a, &b, &n );
    as = false;
    while( n >= 0){
        if(!as){
            n -= gcd(a,n);
        } else{
            n -= gcd(b,n);
        }        
        as = !as;
    }
    
    printf("%d", as);
    
    
    return 0;

}


