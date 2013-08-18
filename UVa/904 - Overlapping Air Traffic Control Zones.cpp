//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=845
//#tag compresão de cordenadas, coordinate compression

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

struct p{
    int x, y, z;
    p( int a = 0,int b = 0, int c =0) : x(a) , y(b), z(c) {};
};


int i,j,k,a,b,c,d,n,m,t,caso = 1;
int cx[50], nx , x, cy[50], ny, y, cz[50], nz, z;
int arr[100][100][100];

p pontos[20][2];
int main(){
	
	while(scanf("%d", &n) > 0){
	    nx = 0;
	    memset( arr, 0, sizeof( arr));
	    nx = ny = nz = 0;
	    for( i=0;i<n;i++){
	        scanf("%d %d %d", &a, &b, &c); 
	        pontos[i][0] = p(a,b,c);
	        cx[nx++] = a;
            cy[ny++] = b;
            cz[nz++] = c;
	        scanf("%d %d %d", &a, &b, &c); 
	        pontos[i][1] = p(a,b,c);
            cx[nx++] = a;
            cy[ny++] = b;
            cz[nz++] = c;
	    }
	    
	    sort( cx, cx+ nx);
	    sort( cy, cy+ ny);
	    sort( cz, cz+ nz);
    	
    	nx = unique( cx, cx+nx) -cx;
    	ny = unique( cy, cy+ny) -cy;
    	nz = unique( cz, cz+nz) -cz;
    	/*for( i = 0; i < nx; i++){
    	    printf("%d %d\n", i, cx[i]);
    	}*/
    	int resp = 0;
    	for( i=0;i<n;i++){
            int xi = lower_bound(  cx, cx + nx, pontos[i][0].x) -cx;
            int xf = lower_bound(  cx, cx + nx, pontos[i][1].x) -cx;
            
            int yi = lower_bound(  cy, cy + ny, pontos[i][0].y) -cy;
            int yf = lower_bound(  cy, cy + ny, pontos[i][1].y) -cy;
            
            int zi = lower_bound(  cz, cz + nz, pontos[i][0].z) -cz;
            int zf = lower_bound(  cz, cz + nz, pontos[i][1].z) -cz;
            
            for( x = xi ; x < xf; x++){
                for( y = yi; y < yf; y++){
                    for( z = zi; z < zf; z++){
                        arr[x][y][z]++;
                        if( arr[x][y][z] == 2){
                            resp += (cx[x+1] - cx[x]) * (cy[y+1] - cy[y]) * (cz[z+1] - cz[z]);
                        }
                    }
                }
            }

            
    	}
    	printf("%d\n" , resp);
	    
	}
	return 0;
}

