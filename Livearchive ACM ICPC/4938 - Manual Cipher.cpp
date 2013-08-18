//http://livearchive.onlinejudge.org/external/49/4938.html
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

int i,j,k,a,b,c,d,t,n,m, caso =1;
char cript[200], num[90], in[200], out[200], aux[200];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	scanf("%s\n", aux);
	bool ok = true;
	for(i=0;aux[i];i++){
		if( aux[i] == ':'){
			ok = false;			
			i++;
			d = i;
		}
		if( ok) cript[i] = aux[i];
		else num[i - d] = aux[i];
	}
	// cout << cript << " -> " << num << endl;
	m = strlen(cript);
	while(gets(in) > 0 ){
		a = 0;
		c = num[a] - '0';
		for(i=0;in[i];i++){
			a += (--c < 0)? 1 :0 ;
			a = a%m;
			if( c < 0) c = num[a] - '0' - 1;
			b = ((( ((in[i] - 'A' >= 0)? in[i] : 'A' + 26) - cript[a]) % (27)) + 27) % 27;
			// cout << (in[i] - 'A') << endl;
			// cout << a << " " <<  b << " "  << c << " "  << m << endl;
			if( b < 26 ) {
				out[i] = 'a' + b ;
			} else {
				out[i] = ' ';
			}			
		}
		printf("%s\n", out);
		
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
	}
	return 0;
}
