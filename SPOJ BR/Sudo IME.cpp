//http://br.spoj.pl/problems/SUDOIME/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int N, aux;
int s[9][9];

int main(){
    
    
    //freopen("in.txt", "r" , stdin);
    //freopen("out.txt", "w" , stdout);
    
    int test = 1;
	scanf("%d", &N);
	while(N--){
        bool ehSudok = true;
        		
		for( int i = 0; i < 9; i++){
            for( int j = 0; j < 9; j++){
			     scanf("%d", &aux);
			     s[i][j] = aux;
            }
		}
		bool lin[9];
		bool col[9];
		bool div[9];
		for(int num = 1; num <= 9; num++){
            
            for( int i = 0; i < 9; i++){
                lin[i] = col[i] = div[i] = false;
		    }
            int segX = 0, segY = 0;
            for(int i = 0; i < 9; i++){
                int auxX = segX, auxY = segY;
                for(int j = 0 ; j < 9 ; j++){
                    if( s[i][j] == num ){
                        lin[i] = true;
                    }
                    if( s[j][i] == num ){
                        col[i] = true;
                    }
                    
                    if( s[auxY][auxX] == num){
                        div[i] = true;    
                    }
                    auxX++;
                    if( auxX > segX + 2) auxX = segX;
                    if( auxX == segX) auxY++;
                    
                }
                segX = ( segX + 3) % 9;
                if( segX == 0) segY += 3;
                
                if( !div[i] || !lin[i] || !col[i] ){
                        //printf("num:%d -> %d , %d %d %d\n\n", num, i, div[i], lin[i], col[i]);
                        ehSudok = false;
                        break;
                }
            }
            if(!ehSudok) break;
            
        }   
        
        
		if(ehSudok)
		      printf("Instancia %d\nSIM\n\n", test);
	    else
		      printf("Instancia %d\nNAO\n\n", test);
		test++;
	}
	   
    
    return 0;
}
