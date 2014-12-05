//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2811

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, n, m, t, a, b;
char str[10000], c, d;
bool ok;

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	gets(str);
	
	while(str[0] != '*') {
		c = str[0];
		if( c < 92){
			d = c - 'A' + 'a';
		} else {
			d = c - 'a' + 'A';
		}
		ok = true;
		for( i = 0 ; str[i]; i++){
			if( str[i] == ' ' && str[i+1] > 0){
				if( str[i+1] == c ||  str[i+1] == d){
					ok = true;
				} else {
					ok = false;
					break;
				}
			}
		}
		if( ok ){
			printf("Y\n");
		} else {
			printf("N\n");
		}
		gets(str);
	}
	
	return 0;
}

