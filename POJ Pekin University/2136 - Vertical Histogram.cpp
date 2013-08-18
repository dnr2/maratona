//http://poj.org/problem?id=2136

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
char str[5][90], hist[400][30];
int cont[30], aux[30];


int main(){
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout );
    
    
    FOR(i,4){    
        gets(str[i]);
        for( j = 0; str[i][j]; j++){
  
            if( str[i][j] >= 'A' && str[i][j] <= 'Z'){
                cont[str[i][j] - 'A']++;
            }
        }
    }
    
  
    int h = 0;
    bool parar = false;
    FOR(i,400){
        parar = true;
        FOR(j,26){
            if( i < cont[j]){
                hist[i][j] = '*';
                parar = false;
            }
        }
        if(parar) break;
        h++;
    }
    for( i = h-1; i >= 0; i--){
        if(hist[i][0] == '*'){
            printf("*");   
        } else {
            printf(" ");
        }
        
        FORC(j,1,26){
            if(hist[i][j] == '*') a = j;
        }
        FORC(j,1,a+1){
            if(hist[i][j] == '*'){
                printf(" *");                           
            } else {
                printf("  ");
            }
        }
        printf("\n");   
    }
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    
    return 0;

}
//http://poj.org/problem?id=1979

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
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout );
    
    
    FOR(i,4){    
        gets(str[i]);
        for( j = 0; str[i][j]; j++){
            if( str[i][j] >= 'A' && str[i][j] <= 'Z'){
                cont[str[i][j] - 'A']++;
            }
        }
    }
    
    FOR(j,26){
        hist[0][j] = 'A' + j;
        FORC(i,1,cont[i]){
            hist[i][j] = '*';
        }        
    }    
    FOR(i,50){
        FOR(j,26){
            if(hist[i][j]) printf("%c ", hist[i][j]);
            else cout << '  ';
        }
        cout << endl;
    }
    
	
			m = 0;
		a = 0;
		memset(aux, -1 , sizeof(aux))
		for( i = 25; i >= 0; i--){
			if( cont[i] > m) m = i;            
		}
		
		for( i = 0; i < 26; i++){
			if( cont[i] >= m) {
				aux[a] = i;            
				a++;
			}
		}
		a = 0;    
		FOR(i,m){
			if(aux[a] != i) 
				printf(" ");
			else {
				printf("*");
				a++;
			}
		}
    
    
    
    return 0;

}
