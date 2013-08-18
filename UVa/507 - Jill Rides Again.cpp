//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=448

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int i,j,k,a,b,c,d,n,m,t,caso = 1, begin, end;

int pd[20001], in[20001];

int main(){
	scanf("%d", &t);
	
	while(t--){
		memset(pd,0,sizeof(pd));
		scanf("%d", &n);
		m = 0;
		begin = end = d = 0; 
		c = 1;
		for(i=1;i<n;i++){
			scanf("%d", &a);
			if( pd[i-1] + a >= a){
				pd[i] = pd[i-1] + a;
				d = i + 1;
			} 
			else {
				pd[i] = a;
				c = i;
				d = i+1;
			}
			if( m < pd[i] || ( m == pd[i] &&  end - begin < d - c)){
				begin = c;
				end = d;
				m = pd[i];	
			}
  			//printf("%d %d %d %d %d %d\n", pd[i], m, c, d, begin, end);
		}
		if( m == 0){	
			printf("Route %d has no nice parts\n", caso++);
		} else {
			printf("The nicest part of route %d is between stops %d and %d\n", caso++, begin, end );
		}
	}
	return 0;
}

