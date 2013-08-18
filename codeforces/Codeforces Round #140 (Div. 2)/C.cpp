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

#define fr(i,j,k) for(int (i)=(j);(i) <(k);++(i))
#define frd(i,j) for(int (i)=(j);(i) >= 0;(i)--)
#define ms(i,j) memset((i),(j),sizeof((i)))
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second
#define PI acos(-1)
#define db(x) cout << x << endl;
#define MAXN 101000

using namespace std;

ll mod;

ll fast( ll x, ll y){
	if( y == 0) return 1;
	ll ret = fast( x , y /2);
	ret = ret * ret;
	ret = ret % mod;
	if( y & 1) ret = (ret * x) % mod;
	return (ret % mod);
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ll in , a, b , resp;
	cin >> in >> mod;
	cout << ((fast( 3 , in) - 1 % mod) + mod ) % mod << endl;

	return 0;
}
