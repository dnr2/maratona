//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=441&page=show_problem&problem=4016

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

int in[501];

int main(){
	
	int t; cin >>t;
	while(t--){
		int n,q,a; cin >> n >> q;
		cl(in); 
		fr(i,0,n) {
			scanf("%d", &a);
			a = a & ((1 << 8) -1);
			in[a] = 1;
		}
		fr(i,0,q) {
			int resp =0, temp;
			scanf("%d", &temp);
			fr(i,0,500){
				if( in[i]) resp = max( temp & i , resp);
			}
			printf("%d\n", resp );
		}
	}
	
	return 0;
}