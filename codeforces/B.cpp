#include<bits/stdc++.h>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 110000;
const ll mod = 1000000009;

struct st{
	ll x, y, id;
	st( ll x = 0, ll y = 0, ll id = 0): x(x), y(y), id(id) {}
	bool operator < ( const st & arg ) const {
		return id < arg.id;
	}
};

st in[maxn];
map< PII, ll > cord;
set<st> cubes;
int n; 

int cont_dep(int id){
	int cont = 0;
	REP(j,0,3){
		PII tmp = MP( in[id].x + j - 1, in[id].y - 1);
		if( cord.count( tmp ) >0 ){
			cont++;
		}
	}
	return cont; //quantos eu dependo				
}


bool can_remove( int id){
	REP(j,0,3){
		PII tmp = MP( in[id].x + j - 1, in[id].y + 1);
		if( cord.count( tmp) > 0 && cont_dep(cord[tmp]) == 1 ){
			return false;
		}
	}		
	return true;
}


int main(){	
	
	cin >> n;
	cord.clear(); cubes.clear();
	
	REP(i,0,n){
		int x, y ;
		scanf("%d%d", &x,&y);
		in[i] = st( x, y , i);
		cord[ MP( x, y )] = i;
	}	
	
	REP(i,0,n){
		if( can_remove(i) ){
			cubes.insert( in[i] );
			// DB( in[i].id );
		}
		
	}
	vector<ll> vresp;
	
	REP(turn,0,n){
		st cur;		
		if( (turn&1) == 0 ){
			cur = *cubes.rbegin();
		} else {
			cur = *cubes.begin();			
		}		
		cubes.erase( cur );	
		cord.erase( MP( cur.x, cur.y ));
		vresp.PB( cur.id );	
		// DB( cur.id );
		
		// poderia sair mas nao pode mais
		REP(j,0,5){
			if( j - 2 == 0) continue;
			PII tmp = MP( in[cur.id].x + j - 2, in[cur.id].y);
			if( cord.count( tmp ) > 0 && cubes.count( in[cord[tmp]] ) > 0 
					&& !can_remove( cord[tmp] ) ){
				cubes.erase( in[cord[tmp]] );
			}
		}
		//nao podia mas agora pode
		REP(j,0,3){
			PII tmp = MP( in[cur.id].x + j - 1, in[cur.id].y - 1);
			if( cord.count( tmp ) > 0 && can_remove( cord[tmp] ) ){
				cubes.insert( in[cord[tmp]] );
			}
		}
	}
	
	ll resp = 0;	
	REP(i,0,n){
		resp *= n; resp %= mod;
		resp += vresp[i]; resp %= mod;
	}
	cout << resp << endl;	
	return 0;
}
