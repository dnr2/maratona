//http://acm.timus.ru/problem.aspx?space=1&num=1820

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
	scanf("%d%d", &a, &b);
	int resp = (((a * 2) / b) + ((( a * 2) % b)? 1 : 0));
	if( resp == 1) resp = 2;
	printf("%d\n", resp )  ; 
	
	return 0;
}