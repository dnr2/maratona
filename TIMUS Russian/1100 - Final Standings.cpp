//http://acm.timus.ru/problem.aspx?space=1&num=1100

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


struct team{
    int ID;
    int M;
};

int n, m, i, j, k, len, z, resp, t;
team arr[150000];


bool comp(team ta, team tb){
    return ta.M > tb.M;    
}

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    
    cin >> t;
    m = 0;
    while(t--){
        team aux;
        scanf("%d %d",  &aux.ID, &aux.M);
        arr[m] = aux;
        m++;
    }
    stable_sort( &arr[0], &arr[m], comp );
    
    FOR(i,m){
        printf("%d %d\n", arr[i].ID, arr[i].M);
    }
    return 0;

}
