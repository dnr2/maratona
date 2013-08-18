//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2938
//#tag: ad-hoc

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <utility>
#include <string>

using namespace std;

long long i,j,k,a,b,c,d,t,n,m, caso =1, e = 0, p;
long long in[10], resp[10];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while( scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &in[0],
		&in[1], &in[2], &in[3], &in[4], &in[5], &in[6], &p) > 0){
		m = 0;
		for( int i= 0; i < 7;i++){
			m += in[i];
		}
		long long s, sum = 0;;
		for( int i= 0; i < 7;i++){
			resp[i] = (p * in[i]) / m;
			sum += resp[i];
		}
		s = p - sum;
		for( int i= 0; i < 7;i++){
			if( s <= 0) break;
			if( resp[i] == 0){
				resp[i] += 1;
				s--;
			}
		}
		
		if( s > 0) resp[4] += s;
		bool prim = true;
		
		for( int i= 0; i < 7;i++){
			if( !prim){
				printf(" ");
			}
			
			printf("%lld", resp[i]);
			// s -= resp[i];
			prim = false;
		}
		puts("");
	}

	return 0;
}
