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

ll in[110];

struct st{
	ll a, b, c;
	st( ll a = 0, ll b =0, ll c= 0): a(a), b(b), c(c) {}
	const bool operator < ( const st arg) const{
		if( a == arg.a ) return c < arg.c;
		return a > arg.a;
	}
};

int main(){
	
	int cc; scanf("%d",&cc);
	int caso =1;
	while( cc--){
		int a, n;
		scanf("%d%d" , &a, &n);		
		fr(i,0,n){
			scanf("%lld", &in[i]);
		}
		sort(in,in+n);
		ll resp =0;
		if( a == 1) { printf("Case #%d: %d\n", caso++, n); continue; }		
		priority_queue<st> heap;
		heap.push( st(0,0,a));
		
		while(!heap.empty()){
			st act = heap.top(); heap.pop();	
			if( act.b >= n) {resp = act.a; break; }
			// db( act.a _ act.b _ act.c _ in[act.b]);
			if( act.c <= in[act.b]){
				heap.push( st(act.a + 1, act.b, (act.c * 2) - 1));
				heap.push( st(act.a + 1, act.b + 1, act.c));
			} else {
				heap.push( st(act.a , act.b + 1, act.c + in[act.b]));
			}
		}
		printf("Case #%d: ", caso++); printf("%lld\n", resp);
	}
	return 0;
}
