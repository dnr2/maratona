//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2885
//#tag -> area poligono
//#tag -> determinante
//#tag -> geometria

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int i,j,k,a,b,c,d,n,m;
char in[1000100];
// char in;
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while(scanf("%s", in) > 0 ){
		long long x=0, y=0, a = 0, n = 0,resp = 0;
		for(i =0 ;in[i];i++){
			a += x * (y + dy[in[i]-'0']);
			a -= y * (x + dx[in[i]-'0']);
			y = (y + dy[in[i]-'0']);
			x = (x + dx[in[i]-'0']);
		}
		a = abs(a);
		resp += a/2 + a %2;
		resp += i/2 + 1;
		printf("%lld\n", resp, a);
	}
	return 0;
}
