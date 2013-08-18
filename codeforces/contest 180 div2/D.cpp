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
#define maxn 100100
using namespace std;


int a[maxn], b[maxn];

int main(){
	
	int n,m,k,temp;
	scanf("%d%d%d",&n,&m,&k);
	
	fr(i,0,n) { scanf("%d", &a[i] ); }
	fr(i,0,m) { scanf("%d", &b[i] ); }
	sort(a,a+n);
	sort(b,b+m);
	int i = n-1,j = m-1;
	bool resp = false;
	while( i >= 0 && j >= 0){
		if( a[i] > b[j]){
			resp = true; break;
		} else {
			i--; j--;
		}
		if( j < 0 && i >= 0) resp = true;
	}
	if( resp) printf("YES\n");
	else printf("NO\n");
	return 0;
}
