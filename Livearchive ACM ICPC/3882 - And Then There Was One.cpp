//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1883
//#tag josephus problem problema de joseph
//#tag math


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

#define ll long long

using namespace std;

ll pilha[50000]; 

ll josephus(ll n, ll k) { 
	ll res = 0; 
	if( n == 1 ) return 0; 
	if( k == 1 ) return n-1; 
	if( k > n ) return ( josephus(n-1, k) + k )%n; 
	res = josephus(n-n/k, k) - n%k; 
	if( res < 0 ) res += n; 
	else res += res/(k-1); 
	return res; 
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n,k,m;
	while( scanf("%d%d%d", &n,&k,&m)>0 && (n || k || m)){
		memset(pilha,0,sizeof(pilha));
		ll resp = josephus(n,k);
		cout << ((((resp + (m - k)) % n) + n ) % n) + 1 << endl;
	}
	return 0;
}