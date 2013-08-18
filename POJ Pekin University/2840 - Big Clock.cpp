//http://poj.org/problem?id=2840

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
char str[5][90], hist[30][400];
int cont[30], aux[30];


int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    cin >> t;
    while(t--){
        scanf("%d%*c%d", &a , &b);
        if( b == 0){
            if( a < 13) printf("%d\n", (a + 12) );
            else printf("%d\n", (a + 12)%25 + 1 );                
        } else {
            cout << "0" << endl;
        }
        
    }
    
    
    return 0;

}
