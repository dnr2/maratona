//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=3122&mosmsg=Submission+received+with+ID+10587067

#include<cstdio>
#include<cstdlib>
#include<iostream>

#define ll long long

using namespace std;

ll poww( ll x, ll y){
	ll resp =1;
	for( ll i =0; i< y;i++){
		resp *= x;
	}
	return resp;
}

ll gcd(ll x, ll y){
	ll s;
	if( x <= 1) return 1;
	while( y > 0){
		s = x % y;
		x = y;
		y = s;
	}
	return x;
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t,caso=1;
	cin >>t;
	ll n ,m;
	while(t--){
		cin >> n >> m;
		printf("Case #%d: ", caso++);
		if( m == 1) {	
			puts("0/1");
			continue;
		}
		ll aux = poww(2,m);
		ll g = gcd( (aux - (m+1)), aux);
		// cout << g << " " << aux << endl;
		cout << (aux - (m+1)) / g << "/" << (aux /g) << endl;
	}
	return 0;
}