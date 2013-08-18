//http://br.spoj.pl/problems/GUARDCOS/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

int main(){
	// freopen("in.txt" , "r" , stdin);
	// freopen("out.txt" , "w" , stdout);
	double a,b,c,d;
	while(scanf("%lf%lf%lf", &a,&b,&c)>0){
		d = sqrt( pow(12.0 , 2.0) + pow(a, 2.0));
		// cout << (12.0/b) << " "  << (d / c) << endl;
		if( (12.0/b) >= (d / c) ) puts("S");
		else puts("N");
	}

}