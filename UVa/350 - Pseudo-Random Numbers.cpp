//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=100&problem=286&mosmsg=Submission+received+with+ID+10587083
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

int mark[101000];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	ll caso=1,z,i,m,l;
	
	while(cin >> z >> i >> m >> l){
		if( !( z ||i || m || l)) break;
		memset(mark,false,sizeof(mark));
		ll cur = l;
		int cont = 1;
		while(!mark[cur]){
			mark[cur] = cont++;
			cur = (z * cur + i);
			cur = cur % m;
		}
		printf("Case %d: " ,caso++);
		printf("%d\n", (cont - mark[cur]));
	}
	return 0;
}