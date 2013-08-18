//http://acm.timus.ru/problem.aspx?space=1&num=1785

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
	cin >> n;
	
	if( n <= 4){
		puts("few");
	} else if( n <= 9) {
		puts("several");
	} else if( n <= 19) {
		puts("pack");
	} else if( n <= 49) {
		puts("lots");
	} else if( n <= 99) {
		puts("horde");
	} else if( n <= 249) {
		puts("throng");
	} else if( n <= 499) {
		puts("swarm");
	} else if( n <= 999) {
		puts("zounds");
	} else {
		puts("legion");
	}
	
	return 0;
}