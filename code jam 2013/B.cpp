#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long
#define PI acos(-1)
#define EPS 1e-9

using namespace std;

struct pt{
	int x, y;
	pt( int x = 0, int y = 0) : x(x) , y(y) {}
};



int main(){
	
	int n; int caso = 1;
	int x, y;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d", &x, &y);
		printf("Case #%d: ", caso++);
		int cont = 1;
		fr(i,0,abs(y)){
			if( y > 0) printf("SN");
			else printf("NS");
		}
		fr(i,0,abs(x)){
			if( x > 0) printf("WE");
			else printf("EW");
		}
		puts("");
	}
	return 0;
}
