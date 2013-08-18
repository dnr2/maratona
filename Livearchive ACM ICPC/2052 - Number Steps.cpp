//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=53
//#tag
//#sol

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <sstream>
#include <climits>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

// #define umap unordered_map

using namespace std;

int i, j, k, a, b, c, d, n, m;
int arr[5300][5300];

int main(){
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	memset( arr, -1, sizeof(arr));
	
	bool troc = true;
	
	c = 1;
	d = 2;
	arr[0][0] = 0;
	for( i = 1; i <= 5010; i++){
		arr[i][i] = c;
		arr[i+1][i-1] = d;
		if(troc){ c += 3; d+= 1; troc = false;}
		else { c += 1; d+= 3; troc = true;}
	}
	
	
	cin >> n;
	while( n--){
		cin >> a >> b;
		if( arr[a][b] >= 0)
			cout << arr[a][b] << endl;
		else 
			cout << "No Number" << endl;
	}
	
	
	return 0;
}