//http://www.codeforces.com/contest/215/problem/B

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pair<int,int> pii

using namespace std;

int i,j,k,a,b,c,d, n,m;
int caso =1;

// int crivo[500100];
double xs, x;
double ys, y;
double zs, z;

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	x = y = 0;
	z = 10000.0;
	scanf("%d" , &n);
	for( i=0;i<n;i++){
		scanf("%lf", &xs);
		x = max( x, xs);
	}
	
	scanf("%d" , &m);
	for( i=0;i<m;i++){
		scanf("%lf", &ys);
		y = max( y, ys);
	}
	int h;
	double A, B, r2, C1, C2;
	scanf("%d" , &h);
	
	for( i=0;i<h;i++){
		scanf("%lf", &zs);
		z = min( z, zs);
	}
	scanf( "%lf %lf", &A, &B);
	double maior = 0;	
	// cout << x << " "  << y <<  " " <<  z << endl;
	C1 = (A * z) / (B * y);
	C1 += 1.0;
	C2 = pow(x,2);				
	r2 = sqrt( C2/C1);
	maior = max( maior, r2);
	
	printf("%.10lf", maior);
	
	return 0;
}