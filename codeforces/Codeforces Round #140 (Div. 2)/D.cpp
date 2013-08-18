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


ll in[100002];
ll a, b , c, n , m;

ll rec( ll x , ll y){
	if( x * y - y + 1 > n) return in[x];
	ll ret;
	for( ll  i = 1 - y ; i <= 1 ;i++){
		ret += rec( y * x + i , y);
	}
	return in[x] + ret;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	cin >> n ;
	memset(in,0,sizeof(in));
	for(ll i=0;i<n;i++){
		scanf("%lld", in+i);
	}
	sort( in, in + n);
	cin >> m ;
	for( ll i = 0; i< m;i++){
		scanf("%lld", a);
		cout << rec( 1, a ) << endl;
	}
	return 0;
}
