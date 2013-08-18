//http://poj.org/problem?id=2027

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

int n, m, a, b, c, d, i, j, k, h, len, z, resp, t;
//char arr[100009][29], str[29];
//int nums[100009];
int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    cin >> t;
    while(t--){
        scanf("%d %d", &a, &b);
        if( a >= b)
            printf("MMM BRAINS\n");
        else
            printf("NO BRAINS\n");
    }    
    
    return 0;

}
