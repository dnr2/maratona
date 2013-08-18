//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2121
//#tag math matematica
//#tag complex numbers complexos
//#sol da mesma forma que com outras bases, devemos dividir o número (a+b*i) por (i-1)
// contudo o resto da divisão deve ser ou 1 ou 0 ou seja ((a+b*i)-(0 ou 1))/(i-1) = quociente 
// que será usado no próxima divisão. assim devemos primeiramente dividir:
// a + b*i por i - i = ((b-a)-(a+b)*i)/2. como queremos que o divisor seja inteiro então
// a + b for par, o resto é 0, caso contrário o resto eh 1 e subtraimos 1 de a.
// vamos calculando os retos das divisões e imprimimos eles na resposta final


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first 
#define S second
#define MAP map<int,int>
#define FOR(i,j,k) for(int (i) = (j); (i) < (k); ++(i))
#define MAXN 1000000
#define MAXM 1000

using namespace std;

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t, x, y, n,a,b,caso=1;
	cin >> t;
	bool resp[MAXM];
	while(t--){
		n = 0;
		memset(resp,false,sizeof(resp));
		scanf("%d%d", &x,&y);
		while( x | y ){
			if( (x + y) % 2 == 0){
				resp[n++] = false;
				a = (-x + y)/2;
				b = (-x - y)/2;
				x = a; y = b;
			} else {
				resp[n++] = true;
				x--;
				a = (-x + y)/2;
				b = (-x - y)/2;
				x = a; y = b;
			}
			// printf("%d %d\n", x, y);
		}
		if(n==0) n++;
		printf("Case #%d: ", caso++);
		for( int i = n-1;i>=0;i--){
			if( resp[i]) printf("1");
			else printf("0");
		}
		puts("");
	}
	
	return 0;
}
