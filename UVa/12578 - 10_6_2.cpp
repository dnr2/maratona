//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4023

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
#define db(x) if(1) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long

using namespace std;

int main(){
	
	int t; cin >>t;
	while(t--){
		double l; cin >> l;
		double area = l * l * (6.0 / 10.0);
		double red = acos(-1) * pow( l * (1.0/5.0) , 2.0);
		double green = area - red;
		printf("%.2lf %.2lf\n", red, green);
	}
	
	return 0;
}