//http://acm.timus.ru/problem.aspx?space=1&num=1001

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

double in[1000000]; 

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	double x;
	int cont = 0;
	while(scanf("%lf", &x) >0){
		in[cont++] = x;
	}
	while(cont--){
		printf("%.4lf\n" , sqrt(in[cont]));
	}
	return 0;
}