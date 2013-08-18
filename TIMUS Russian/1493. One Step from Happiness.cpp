//http://acm.timus.ru/problem.aspx?space=1&num=1493

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
	char str[2][10];
	char aux[2][10];
	memset(str, '0', sizeof(str));
	a = b = c = d = 0;
	sprintf( aux[0], "%d", n-1);
	sprintf( aux[1], "%d", n+1);
	int t = 0;
	for( i = 6 - strlen(aux[0]) ; i< 6; i++){
		str[0][i] = aux[0][t++];
	}
	t = 0;
	str[0][6] = str[1][6] = 0;
	for( i = 6 - strlen(aux[1]) ; i< 6; i++){
		str[1][i] = aux[1][t++];
	}
	// cout << str[0] << endl;
	// cout << str[1] << endl;
	
	for( int i =0 ; str[0][i]; i++){
		if( i < 3) {
			a += str[0][i] - '0';
			b += str[1][i] - '0';
		} else {
			c += str[0][i] - '0';
			d += str[1][i] - '0';
		}
	}
	// printf("%d %d %d %d\n", a, b,c,d);
	if( a == c || b == d) puts("Yes");
	else puts("No");
	return 0;
}