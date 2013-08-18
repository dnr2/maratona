//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=441&page=show_problem&problem=4019

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

ll in[5010];

int main(){
	
	int t; cin >>t;
	while(t--){
		int n ;cin >> n;
		fr(i,0,n) scanf("%lld", &in[i]);
		ll resp =1; ll sum = 0;
		fr( i,0, n){
			resp *= (in[i] + 1);
			resp %= 1000000007;
			sum += in[i];
			sum %= 1000000007;
		}
		resp -= 1; resp -= sum;
		resp %= 1000000007;
		resp += 1000000007;
		resp %= 1000000007;
		printf("%lld\n", resp );
	}
	
	return 0;
}