//http://acm.timus.ru/problem.aspx?space=1&num=1068

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pii pair<int,int> 
#define F first
#define S second

using namespace std;

int i,j,k,a,b,c,d, n,m;
int caso =1;


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	scanf("%d", &n );
	long long sum = 0;
	if( n < 1){
		for( long long i =1; i >= n; i--){
			sum += i;
		}
	} else {
		for( long long i =1; i <= n; i++){
			sum += i;
		}
	}
	cout << sum;
	return 0;
}