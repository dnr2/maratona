//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1811
//#tag fast exponentiation / exponenciacão rápida
//#tag fast with matrix

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int i,j,k,a,b,c,d,n,m,t,caso = 1, begin, end;
int ai[20], fi[20], mat[20][20];

struct matriz{
    long long x[20][20];
    matriz() { memset(x, 0,sizeof(x));};
    matriz operator * ( const matriz & in) const{
        matriz aux;
        for( int i =0; i < d;i++){
            for( int j =0;j<d;j++){
                for( int k =0; k<d;k++){
                    aux.x[i][j] = (x[i][k] * in.x[k][j] + aux.x[i][j]) % m;
                }
            }
        }
        return aux;
    }
};

matriz fastexp(matriz x, int y){
        if( y==1){
            return x;
        }
      matriz resp ;

      resp = fastexp( x, y/2);
      resp = resp * resp;
      if( y %2) resp = resp * x;
      return resp;
}

int main(){
    while(scanf("%d %d%d", &d, &n ,&m) > 0 && d != 0){
        for( i =d-1;i>=0;i--){
            scanf("%d", ai + i);
        }
        for( i =0;i<d;i++){
            scanf("%d", fi + i);
        }
        if( n <=d) {
            printf("%d\n", fi[n-1]%m);
        }else {
            matriz aux;
            for( i=0;i<d-1;i++){
                aux.x[i][i+1] = 1;
            }
            for( i=0;i<d;i++){
                aux.x[d-1][i] = ai[i];
            }
            matriz ret;
            for( i =0;i<d;i++){
                ret.x[i][0] = fi[i];
            }
            ret = fastexp( aux, n-d) *  ret;
            printf("%lld\n", ret.x[d-1][0] % m);
        }
    }
    return 0;
}

