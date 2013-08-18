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
#define ms(i,j) memset((i),(j),sizeof((i)))
#define MAXN 101000
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second
#define PI acos(-1)
#define db(x) cout << x << endl;

using namespace std;

ll fib[100];
ll resp[100] , cont;

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	ll s ,k , aux, i;
	cin >> s >> k ;
	ms(fib,0);
	fib[0] = 1;
	for( i = 1; i < 100; i++){
		for( ll j= max( 0, ((int)(i - k))); j < i;j++){
			fib[i] += fib[j];
		}
		if( fib[i] > s) break;
	}
	ll sum = s; cont = 0;
	while( i >= 0){
		if( fib[i] <= sum) {
			resp[cont++] = fib[i];
			sum -= fib[i];
		}
		i--;
	}
	cout << (cont + 1)<< endl;
	cout << "0";
	for( i =0; i< cont; i++){
		cout << " "  << resp[i] ;
	}
	return 0;
	
}