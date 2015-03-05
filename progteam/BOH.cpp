#include<bits/stdc++.h>

// #include <unordered_map>

#define REP(i,j,k) for(int (i) = (j); (i) < (k); (i)++)
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define INF 0x3f3f3f3f
#define FT first 
#define SD second
#define PI acos(-1)
#define EPS 1e-9
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ll long long
#define ull unsigned long long
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << " " <<

using namespace std;

struct st{
    int FT, SD, index;
    st(int FT = 0, int SD = 0, int index = 0) : FT(FT) , SD(SD), index(index) {}
};

const int maxn = 200000;
st in[2][maxn];
int sz[2];


bool cmp(st a, st b){    
    return a.FT < b.FT;
}

bool cmp2(st a, st b){
    return a.SD > b.SD;
}

int resp[maxn];

int main(){  
   
   ll n, z; 
   while( cin >> n >> z){
	   REP(i,0,n){
		  int a, b; scanf("%d %d", &a, &b);
		  int j = a >= b;
		  in[j][sz[j]++] = st( a, b, i+1 );
	   }
	   sort( in[0], in[0] + sz[0] , cmp);
	   sort( in[1], in[1] + sz[1] , cmp2);
	   ll rsz = 0;
	   bool ok = true;
	   REP(kk,0,2){
			if( ok ){
				 REP(i,0,sz[kk]){
					if( z <= in[kk][i].FT) {
						ok = false; break;
					} else {
						z += in[kk][i].SD - in[kk][i].FT;
						resp[rsz++] = in[kk][i].index;
					}
					
				 }
			}
	   } 
	   if( !ok) {
			cout<< "NIE" << endl;
	   } else {
			cout<< "TAK" << endl;
			REP(i,0,rsz){
				if( i > 0) printf(" ");
				printf("%d", resp[i] );
			}
			puts("");
	   }
   }
   return 0;
}