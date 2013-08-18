//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1133
// #tag LCS
// #tag PD

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

char str1[110], str2[111];
int pd[110][110];
int i,j,k,a,b,c,d,n,m;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    gets(str1);
    c = 1;
	while(!(str1[0] == '#' && strlen(str1) == 1)){
        gets(str2);
        n = strlen(str1);
        m = strlen(str2);
        memset(pd,0,sizeof(pd));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1]){
                    pd[i][j] = pd[i-1][j-1] + 1;
                } else {
                    pd[i][j] = max (pd[i][j-1], pd[i-1][j] ) ;
                }
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", c++, pd[n][m]);
        gets(str1);
	}
	return 0;
}
