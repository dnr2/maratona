//http://livearchive.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1640

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
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

int n, m, c, d, i, j, k, len, z, resp, t;
long long b, a;

bool crivo[10320];
int primes[10320];



char num1[10], num2[10];

vector<int> gp[10000];
int pai[10000];

void bfs(int u){
    
    queue<int> q;
    q.push( u );
    while( !q.empty()){
        u = q.front();
        //printf("\n");
        q.pop();        
        for( vector<int>::iterator it = gp[u].begin(); it < gp[u].end(); it++){
            if( pai[*it] == 0){
                //printf("%d -> %d\n", u, *it);
                pai[*it] = u;
                q.push(*it);
            }        
        }
    }    
    
}


int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out2.txt", "w", stdout );    
    
    FORC(i,2,10020){
        crivo[i] = true;
    }
    
    
    len = 0;  
    FORC(i,2,10020){
        while( !crivo[i] && i < 10020){
            i++;
        }
        if(i > 1000) {
            primes[len++] = i;
        }
        for(j = 2*i; j < 10120; j+= i){
            crivo[j] = false;
        }                
    }
    len -= 3;
    
    FOR(i,len){    
        FOR(j,len){
            if(primes[i] != primes[j]){
                c = 0;
                a = 1;
                for( k = 0; k < 4; k++){                    
                    if( ( primes[i] /a) %10 == (primes[j] / a) % 10 ) {
                        c++;                        
                    }
                    a *= 10;
                }
                if( c == 3 ){
                    gp[primes[i]].push_back(primes[j]);
                    //printf("%d -> %d\n", primes[i], gp[primes[i]].back());
                }
            }
        }
        //printf("\n");
    }
    
        

    scanf("%d", &t);
    while(t--){
        memset(pai, 0, sizeof(pai));        
        scanf("%d %d", &n, &k);
        pai[n] = -1;
        bfs(n);
        if(pai[k] == 0){
            cout << "Impossible" << endl;
        } else{
            int paps = pai[k];
            resp = 0;
            while( paps != -1){
                resp++;
                paps = pai[paps];
            }
            printf("%d\n", resp);
            
        }
        
        
    }

    return 0;

}
