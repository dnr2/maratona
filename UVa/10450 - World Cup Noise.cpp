//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=193&page=show_problem&problem=1391
//#tag math matematica
//#tag pd dinamic programming


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
	ll calc[60], resp[60];
	memset(calc,0,sizeof(calc));
	ll pot = 4;
	calc[1] = 0;
	resp[1] = 2;
	for( int i=2;i<60;i++){
		calc[i] += calc[i-1] * 2 + ( (pot / 2) - calc[i-1] - ((pot/4) - calc[i-2]));
		resp[i] = pot- calc[i];
		pot *= 2;
	}
	int t =0,n,caso=1;
	cin >>t ;
	while(t--){
		scanf("%d", &n);
		printf("Scenario #%d:\n", caso++);
		cout << resp[n] << endl;
		puts("");
	}
	
	return 0;
}