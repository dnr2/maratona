//http://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=23&problem=2126&mosmsg=Submission+received+with+ID+10587120
//#tag math matematica

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
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ll num;
	char resp[100];
	int pos;
	while(cin>>num && num >= 0){
		pos= 0;
		memset(resp,0,sizeof(resp));
		if( num ==0) resp[pos++] = '0';
		else {	
			while(num > 0){
				resp[pos++] = '0' + num % 3;
				num /= 3;
			}
		}
		for( int i= pos-1; i>=0;i--){
			printf("%c", resp[i]);
		}
		puts("");
	}
	
	return 0;
}