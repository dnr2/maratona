//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1705
//#tag math matematica
//#tag base numerica
//#tag guloso greed
//#sol tentar "encaixar" os valores no número de entrada, caso dois valores estejam na mesmo posição, 
// some-os

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define ll long long
using namespace std;

ll b,a;
ll arr[12][35];


string bt( ll val , ll pos){
	string ret = "", str;
	ll aux;
	ll i, j;
	
	for( i =0;i< 100; i++){
		if( abs(val) <= a * arr[b][i]) break;
	}
	for( j = 0; j<= 100; j++){
		if( abs(val) <= j * arr[b][i]) break;
	}
	if( i == pos ) {
		ret += '!';
		return ret;
	}
	if( val < 0) ret += "'";
	
	if( abs(val) <= a) {
		ret += ('0' + abs(val));
		return ret;
	}
	
	if( val < 0) aux = val + j * arr[b][i];
	else aux = val - j * arr[b][i];
	
	do{
		str = bt( aux , i);
		if( str[0] == '!'){
			j--;
			if( val < 0) aux = val + j * arr[b][i];
			else aux = val - j * arr[b][i];	
		} else break;
	} while( true );
	
	ret += ('0' + j);
	ll lenstr = 0;
	for( ll x = 0; x < str.size(); x++){
		if( str[x] >= '0' && str[x] <= '9') lenstr++;
	}
	while( i-- > lenstr ){
		ret += "0";
	}
	ret += str;
	return ret; 
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	for( long long i = 2; i <= 10; i++){
		long long x = 1;
		for( long long j = 0; j < 35; j++){
			arr[i][j] = x;
			x *= i;
			if( x < 0 ) break;
		}
	}
	ll num;
	string resp;
	while( (cin >> num >> b >> a)  && num || b || a){
		resp = bt(num,-1);
		
		cout << resp << endl;
	}

	return 0;
}