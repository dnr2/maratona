#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>

#define fr(i,j,k) for(int (i)=(j);(i) <(k);++(i))
#define ms(i,j) memset((i),(j),sizeof((i)))
#define MAXN 101000
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second
#define PI acos(-1)
#define db(x) cout << x << endl;

using namespace std;

int f[100011];
int g[100011];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int a ,b,c,pos;
	ll x = 0, y = 0;
	a = b = c = pos = 0;
	cin >> a;
	for(int i=1;i<=a;i++){
		scanf("%d", f+i);
		g[f[i]] = i;
	}
	cin >> b;
	while(b--){
		scanf("%d", &c);
		
		x += (g[c]), y += 1 + (a - g[c]);
	}
	cout << x << " "  << y;
	return 0;
	
}