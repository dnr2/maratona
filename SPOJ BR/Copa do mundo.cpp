//http://br.spoj.pl/problems/COPA/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char sAux[30];
int K, N, M, X, Y;
int P, aux; // pontos

bool read(){
    scanf("%d", &K);
    if (K == 0) return false;
    scanf("%d %d", &N, &M);
    
    return true;
        
}

int main(){
    //freopen("in.txt", "r" , stdin);
    //freopen("out.txt", "w" , stdout);
    while(read()){
        
        for(int c = 0; c < K; c++){
            scanf("%d %d", &X, &Y );
            if( X == N || Y == M ){
                printf("divisa\n");
            } else if( X < N && Y > M ) {
                printf("NO\n");
            } else if( X > N && Y > M ) {
                printf("NE\n");
            } else if( X < N && Y < M ) {
                printf("SO\n");
            } else if( X > N && Y < M ) {
                printf("SE\n");
            } 
        }
        
    }
    
    return 0;
}
