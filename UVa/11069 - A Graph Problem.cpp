//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2010
//#tag: math matematica matemática

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long a,b,c,d;
long long resp[100];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	resp[1] = 1; resp[2] = 2; resp[3] = 2;
	for( int i=4;i <= 76; i++){
		resp[i] = resp[i-3] + resp[i-2];
		// cout << resp[i] << endl;
	}
	
	
	while(cin >> a){
		cout << resp[a] << endl;
	}
	
	return 0;
}
