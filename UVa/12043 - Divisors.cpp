//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3194

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

#define SIZE 101000
#define ll long long
#define MAP map<int,int>
#define MAPI map<int,int>::iterator\
#define pii pair<int,int>
#define pid pair<int,double>
#define F first
#define S second

using namespace std;


int crivo[110100];
ll d[110100];
ll phi[110100];
map<int,int> test;
ll soma;
pair<int,int> vec[20];
int len;

ll exp(ll x, ll y){
	ll resp = 1;
	for( ll i = 0; i< y; i++) resp *= x;
	return resp;
}

void rec(int it, ll sum){	
	if( it == len){
		soma += sum;
		// cout << "sum = " << sum << endl;
		return;
	}
	// cout << "rec "  << it << endl;
	for( ll i=0;i <= vec[it].S; i++){
		rec( (it+1), sum * exp( vec[it].F , i));
	}
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	d[1] = phi[1] = 1;
	memset(crivo, 0 ,sizeof(crivo));
	for(int i=2;i <= SIZE;i++){
		if( !crivo[i] ){
			for( int j= i; j <= SIZE; j += i) crivo[j] = i;
		}
		//cout << crivo[i] << endl;
	}
	crivo[1] = 1;
	for(int i=2;i < SIZE;i++){
		// cout << "num = " << i << endl;
		int cur = i;
		memset(vec,0,sizeof(vec));
		len = 0;
		while(crivo[cur]  != 1){
			int j;
			for( j=0;j<len;++j) {
				if( vec[j].F == crivo[cur]) {
					vec[j].S++;
					break;
				}
			}
			if( j >= len){
				vec[len++] = pair<int,int>( crivo[cur], 1);
			}
			cur /= crivo[cur];
		}
		soma = 1;
		for( int j =0;j < len; ++j){
			soma *= (vec[j].S + 1);
		}
		//cout << "soma = " << soma << endl;
		d[i] = soma;
		soma =0;
		rec( 0, 1);
		phi[i] = soma;
		// if( i < 20) cout << d[i] << " "  << phi[i] << endl;
	}
	
	int t,a,b,c;
	cin >> t;
	
	while(t--){
		scanf("%d%d%d", &a,&b,&c);
		ll resp1 = 0, resp2 = 0;
		for( int i=a; i<=b; i++){
			if( i % c == 0){
				resp1 += d[i];
				resp2 += phi[i];
			}
		}
		cout << resp1 << " " << resp2 << endl;
	}
	
	return 0;
}
	