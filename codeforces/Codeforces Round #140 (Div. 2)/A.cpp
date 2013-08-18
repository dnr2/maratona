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
	
	double a, b, c, d,e,f;
	
	cin >> a >> b >> c >> d >> e >> f;
	double x = (c-a), y = (d-b), z = (e - c), w = (f-d); 
	if(( ( x * z + y * w) / ( hypot(x,y) * hypot(z,w))) >= (1.0 - 1e-9)){
		puts("TOWARDS");
	} else {
		if( x * w - z * y > 0){
			puts("LEFT");
		} else {
			puts("RIGHT");	
		}
	}
	return 0;
}
