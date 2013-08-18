#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>

#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define pb push_back

using namespace std;

ll gdc(ll a, ll b){
	return (!b)? a : gdc( b, a%b);
}

ll o, c, m;

bool three_square(ll x){
	while (!(x&3)) x>>=2;
	return (x+1)&7; // 0 == nao eh formado por 3 quadrados perfeitos
}

bool twosquare(ll x){
	for(ll i = 2; i*i <= x; ++i){
		ll tot = 1;
		while(x%i == 0){
			tot *= i;
			x /= i;
		}
		if(!((tot+1)&3)) return false;
	}
	return (x+1)&3;
}

int main(){
	
	
	while( cin >> o  >> c){
		vector<ll> v; 
		for(ll i = 1;i*i<=o;i++){
			if( o % i ==0){
				if( i <= c) v.pb(o/i);
				if( o/i <= c && i != o/i) v.pb(i);
			}
		}
		ll x = 0;
		fr(i,0,v.size()){
			if( three_square(v[i]) ) {
				x++;
			}
		}
		ll g = gdc(x, c+1);
		//cout << "x = " << x << endl;
		printf("%lld/", x/g); printf("%lld\n", (c+1)/g);
	}
	return 0;
}
