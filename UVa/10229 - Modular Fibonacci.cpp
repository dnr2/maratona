//http://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1170
//#tag fast exponentiation
//#tag potenciacao de matriz / matrix

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;


int i, j , k, n , m,a,b,c,d, t,top;

struct mat{
	long long matrix[2][2];
	mat() { memset(matrix, 0, sizeof(matrix));}
	mat operator * ( const mat & in) const{
		mat ret;
		for(int x=0;x<2;x++){
			for( int y=0;y<2;y++){
				for( int z = 0;z<2;z++){
					ret.matrix[x][y] = (ret.matrix[x][y] + ( matrix[x][z] * in.matrix[z][y]) % top ) % top;
				}
				
			}
		}
		// printf("%d %d %d %d\n", ret.matrix[0][0], ret.matrix[0][1] , ret.matrix[1][0], ret.matrix[1][1]); 
		return ret;
	}
	
};


mat fastexp(mat in, int y){
	if( y == 1){
		return in;
	}
	mat ret, aux;
	aux = fastexp( in, y/2);
	ret = aux * aux;
	if( y %2 == 1) ret = ret * in;
	return ret;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d%d", &n, &m) > 0){
		top = 1 << m;
		// printf("%d\n", top);
		mat ma;
		ma.matrix[0][0] = 0;
		ma.matrix[0][1] = 1;
		ma.matrix[1][0] = 1;
		ma.matrix[1][1] = 1;
		int resp;
		if( n <= 1){
			if( n == 0) resp = 0;
			else resp = 1 % top;
			printf("%d\n", resp);
		} else {
			ma = fastexp( ma, n - 1);
			cout <<  (ma.matrix[1][1] % top) << endl;

		}
	}
	return 0;
}
