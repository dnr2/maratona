//http://acm.timus.ru/problem.aspx?space=1&num=1083

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

#define pii pair<int,int> 
#define F first
#define S second

using namespace std;

int i,j,k,a,b,c,d, n,m;
int caso =1;


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	string num;
	
	cin >> n ;
	cin >> num;
	m = num.size();
	
	int resp = 1;
	int i =0;
	while( i < n ){
		resp *= (n - i);
		i += m;
	}
	cout << resp << endl;
	return 0;
}