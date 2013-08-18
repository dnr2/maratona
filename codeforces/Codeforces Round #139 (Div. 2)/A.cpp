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
#define frd(i,j) for(int (i)=(j);(i) >= 0;(i)--)
#define ms(i,j) memset((i),(j),sizeof((i)))
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second
#define PI acos(-1)
#define db(x) cout << x << endl;
#define MAXN 101000

using namespace std;


int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int a, b, c, d;
	cin >> a;
	cin >>b; a--;
	cin >> c >> d;
	b = 7 - b;
	while(a--){
		cin >> c >> d;
		if( b == c || b == d || b == (7-c) || b == (7-d) ){
			puts("NO");
			return 0;
		}
		for(int i = 1; i<=6;i++){
			if( !( i == c || i == d || i == (7-c) || i == (7-d) || i == b)){
				b = (7-i); break;
			}
		}
	}
	puts("YES");
	
	return 0;
}
