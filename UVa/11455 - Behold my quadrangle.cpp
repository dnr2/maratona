//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2450
//#tag math
//#tag geometry


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

int i, j , k, n , m,a,b,c,d, t,top;
int arr[4];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	cin >> t;

	while(t--){
		// cout << "aui" <<endl;
		scanf("%d%d%d%d", arr, arr+1, arr+2, arr+3);
		sort(arr, arr + 4);
		bool p = false, ok;
		ok = true;
		for( i =1 ; i < 4;i++){
			if( arr[i] != arr[i-1]) ok = false;
			if( i == 3 && ok) {
				printf("square\n");
				p = true;
			}
		}
		if( !p ){
			ok = ( arr[0] == arr[1] && arr[1] != arr[2] && arr[2] == arr[3]);
			if( ok) {
				printf("rectangle\n");
				p = true;
			} 
		}
		long long soma = 0;
		if( !p){
			for( i =0 ; i < 4;i++){
				if( i == 3){
					if( soma >= arr[3]){
						printf("quadrangle\n");
						p = true;
					} 
				} else {
					soma += arr[i];
				}
			}
		}			
		if( !p) printf("banana\n");
		
	}
	return 0;
}
