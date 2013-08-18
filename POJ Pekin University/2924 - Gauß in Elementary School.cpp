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

int n, m, i, j, k, len, z, resp, t;


int main(){
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout );
    cin >> t;
    long long a = 100, b = 200 , c, d;
    FORC(i,1,t+1){
        cin >> a;
        cin >> b;  
        printf("Scenario #%d:\n", i);
        c = a + b;
        d = b - a + 1;
        c = (c * d) / 2 ;
        cout << c << endl << endl;
    }
    
    
    return 0;

}
