//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2113
//#tag ad hoc
//#sol fazer uma comparação simples e imprimir o resultado

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;

#define fr(i,j,k) for(int (i)=(j);(i)<(k);(i)++)
#define ms(i,k) memset(i,k,sizeof(i))
#define PI acos(-1)

int main(){
    int n = 0; cin >> n;
    while(n--){        
        long long a,b;
        cin >> a >> b;
        if( a < b){
            puts("<");
        } else if( a > b){
            puts(">");
        } else {
            puts("=");
        }        
    }
    return 0;
}