//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=441&page=show_problem&problem=4025

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

int in[2010];

int main(){
	
	int t; cin >>t; int caso =1;
	while(t--){
		int n ;cin >> n;
		fr(i,0,n){
			scanf("%d",&in[i]);
		}
		int b, e;
		b = 0; e = n-10;
		printf("Case %d:", caso++);
		if( n < 11) {printf(" go home!\n"); continue; }
		fr(i,0,11){
			int m = 0;
			fr(j,b,e){
				if( m < in[j]){
					b = j + 1; m = in[j];
				}
			}
			printf(" %d", m); 
			e++;
		}
		puts("");
	}
	
	return 0;
}