//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2870
//#tag: longest increasing subsequence
//#tag: Problem solving paradigm

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

int  i, j, k, m, n, a, b, c, d;
int pd[100100];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while( scanf("%d" , &n) > 0 ){
		b = 0;
		for(i=0;i<n;i++){
			scanf("%d", &a);
			if(b==0) {
				pd[0] = a;
				b++;
			} else {
				if(pd[b-1] < a){
					pd[b++] = a;
				} else{
					c = 0; d = b-1;
					while( c < d ){
						m = c + ( d - c)/2;
						if( pd[m] < a){
							c = m + 1;
						} else {
							d = m;
						}
					}
					pd[c] = a;
					// cout << " M -> " << m << endl << endl;
				}				
			}
			// for(j=0;j<b;j++){
				// printf("\t%d", pd[j]);
			// }
			// puts("");
		}
		printf("%d\n", b);
		for(i=0;i<=n;i++){
			pd[i] = 0;
		}		
	}
		
	
	return 0;
}
