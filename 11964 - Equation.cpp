//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3115
//#tag math matematica

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>

#define FOR(i,j,k) for(int (i)=(j);(i) <(k);++(i))
#define MAXN 101000
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second
#define PI acos(-1)
#define db(x) cout << x << endl;

using namespace std;

ll pot[1<<20];

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	pot[0] = 1;
	for( ll i=1; i< 100000;i++){
		pot[i] = pot[i-1]+ pot[i/2];
		cout << pot[i] << endl;
	}
	// cint >>t;
	// while(t--){
		// scanf("
	// }
	return 0;
}