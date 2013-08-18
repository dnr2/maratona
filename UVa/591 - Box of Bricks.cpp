//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=99&page=show_problem&problem=532
//#tag math matematica
//#tag ad hoc


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>

#define FOR(i,j,k) for(int (i) = (j); (i) < (k); (i)++)
#define ll long long

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n,m,in[60],sum =0,resp,caso=1;
	while( scanf("%d", &n)>0 && n){
		memset(in,0,sizeof(in));
		sum = resp = 0;
		FOR(i,0,n){
			scanf("%d", in+i);
			sum+= in[i];
		}
		m = sum / n;
		FOR(i,0,n){
			if( in[i]> m) resp += in[i] - m;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",caso++, resp);
	}
	
	return 0;
}