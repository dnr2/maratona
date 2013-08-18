//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=82
//# adhoc
//# next permutation
//sol use next_permutation function in order to permute the string

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

char str[100];

int main(){
	
	while(scanf("%s", str) > 0 && str[0] != '#'){
		bool fim = true;
		for( int i=1;str[i];i++){
			if( str[i-1] < str[i]) fim = false;
		}
		if( fim) puts("No Successor");
		else {
			int len = strlen(str);
			next_permutation(str, str + len);
			printf("%s\n", str);
		}
		
	}
	return 0;
}
