//http://acm.timus.ru/problem.aspx?space=1&num=1877

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
	bool ok= true;
	scanf("%d%d" ,&n,&m);
	for( int i =0; i<= 9999; i++){
		if( ok && i == n || !ok && i == m) {
			puts("yes");
			return 0;
		} 
		ok = !ok;
	}
	puts("no");
	return 0;
}