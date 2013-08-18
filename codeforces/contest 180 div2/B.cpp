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
#define MAXN 100100

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char in[MAXN];
int pos[MAXN];

int main(){
	
	int t,sx,sy,ex,ey;
	
	while(scanf("%d%d%d%d%d",&t,&sx,&sy,&ex,&ey) > 0){
		scanf("%s", &in);		
		for(int i =0; i<t;i++){
			if( in[i]=='N') pos[i]=0;
			if( in[i]=='E') pos[i]=1;
			if( in[i]=='S') pos[i]=2;
			if( in[i]=='W') pos[i]=3;			
		}
		// db( in _ t _ ey);
		int hx = ex- sx;
		int hy = ey- sy;		
		int i;
		db( hx _ hy);
		for( i =0;i<t;i++){		
			if( abs(hx) > abs(hx - dx[pos[i]]) || abs(hy) > abs(hy - dy[pos[i]]) ){
				hx -= dx[pos[i]];
				hy -= dy[pos[i]];
			}
			db( hx _ hy _ pos[i]);
			if( hx == 0 && hy == 0) break;
		}
		if( hx == 0 && hy == 0) printf("%d\n", i+1);
		else printf("-1\n");
	}
	return 0;
}
