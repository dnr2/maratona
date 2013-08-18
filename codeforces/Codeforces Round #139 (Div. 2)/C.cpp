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

struct st{
	int x,y,z;
	s(int x =0, int y=0, int z=0) : x(x), y(y) , z(z) {}
}

char f[100010];
int g[100010];
s resp[100010];

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int o1,o2,q;
	bool init;
	scanf("%s" , f);
	int n = strlen(f);
	fr(i,0,n) {
		if( !init && f[i] =='[') init = true;
		if(init){
			if( f[i] == '(') 
			if( f[i] == ')') 
			if( f[i] == '[') 
			if( f[i] == ']') 
		}
	}

	return 0;
}
