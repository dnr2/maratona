//http://codeforces.com/contest/140/problem/A

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

#define PI 3.14159265

using namespace std;

double n, R, r;

int main(){
    freopen( "in.txt", "r", stdin);
    freopen( "out.txt", "w", stdout);		
	
    cin >> n >> R >> r;
    
    if( r > R ) puts("NO");
    else if( r <= R && n == 1) puts("YES");
	else puts( ( n * asin(r / (R-r)) <= PI + 1e-8 ) ? "YES" : "NO" );
	printf( "%lf <= %lf ?", ( n * asin(r / (R-r))), PI + 2e3 );
	return 0;
}
