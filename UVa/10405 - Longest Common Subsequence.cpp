//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346
//#tag lis longest increasing subsequence

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

char in1[2011], in2[2011];
int pd[2011][2011];

int main(){
	
	while( gets(in1) ){
		gets(in2);
		memset(pd, 0 , sizeof(pd));
		int n = strlen( in1);
		int m = strlen( in2);
		for( int i =1 ; i <= n; i++){
			for( int j =1; j <= m ; j++){
				if( in1[i-1] == in2[j-1]){
					pd[i][j] = pd[i-1][j-1] + 1;
				} else {
					pd[i][j] = max (pd[i-1][j], pd[i][j-1]);
				}
			}
		}
		printf("%d\n", pd[n][m] );
		
	}
	return 0;
}
