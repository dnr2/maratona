#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <iostream>


#define MAP map<int,int>
#define pii pair<int,int> 
#define F first
#define S second

using namespace std;

int i,j,k,a,b,c,d, n,m, aux;
int caso =1;
int resp = 0;

pii arr[1010];
int nums[11], cont;

int poww( int x, int y){
	int ret = 1;
	for( int i= 0; i<y; i++){
		ret *= x;
	}
	return ret;
}

void func(int pos, int act){
	
	if( pos == cont){
		int aux = act;
		while( aux != 0){
			if( nums[aux%10]) {
				resp++;
				// cout << "f: " << act << endl;
				return;
			}
			aux /= 10;
		}
		return;
	}
	for( int i =0;i <= arr[pos].S; i++){
		func( pos+1, act * poww( arr[pos].F , i));
	}
}


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	scanf("%d", &n);
	
	int root = (int) sqrt(n);
	cont =0, aux = n;
	
	while( aux != 0){
		nums[aux%10]++;
		aux /= 10;
	}
	for( i = 2; n != 1 && i <= root; i++){
		bool in = false;
		while( n % i == 0){
			n /= i;
			arr[cont].F = i;
			arr[cont].S++;
			in = true;
		}
		if( in) {
			// cout << arr[cont].F << " " << arr[cont].S << endl;
			cont++;
		}
	}
	// cout << n << endl;
	if( n != 1) {
		arr[cont].F = n;
		arr[cont++].S += 1;
	}
	
	func( 0, 1 );
	printf("%d\n", resp);
	return 0;
}