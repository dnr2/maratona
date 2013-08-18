//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3876
//#tag hash map
//#tag bfs busca em largura de dois niveis
//#sol 

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

using namespace std;
ll prime = 4200187, prime2 = 3214567;

int hash(ll in){
	int ret = (int) (in % prime);
	return ret;
}

template<class K, class V> struct HashMap {
    vector<pair<K, V> > tab;
    vector<char> used;
    HashMap(int maxsize) : tab(maxsize), used(maxsize, 0) {}
    V *lookup(const K &key, bool insert) {
        for (int i = hash(key) % tab.size();;) {
            if (used[i]) {
                if (tab[i].first == key) return &tab[i].second;
            } else {
                if (!insert) return NULL;
                used[i] = 1;
                tab[i].first = key;
                return &tab[i].second;
            }
            if (++i == tab.size()) i = 0;
        }
    }
    V &operator[](const K &key) { return *lookup(key, true); }
    bool contains(const K &key) { return lookup(key, false) != NULL; }
};

HashMap<ll, pii> mapa(4200187);
// map<ll, pii> mapa;
// unordered_map<ll, pii> mapa;
int passo=0,n,m,t;
ll target = 0; 
ll pot[13];
bool seq;
ll mov[] = { 2,3,4,5,6,12,7,8,9,10,11,1,
			 12,1,2,3,4,5,7,8,9,10,11,6,
			 1,2,3,4,5,7,8,9,10,11,12,6,
			 1,2,3,4,5,12,6,7,8,9,10,11,
			 2,3,4,5,6,7,8,9,10,11,12,1,
			 12,1,2,3,4,5,6,7,8,9,10,11 };

int state = -1;
			 
int bfs(ll init){
	queue< pair<ll,int> > fila;
	fila.push( pair<ll,int>(init,0) );
	pair<ll,int> x; 
	int ret = -1;
	while(!fila.empty()){
		x = fila.front(); fila.pop();		
		if( x.F == target && !seq){
			ret = x.S; break;
		}
		if( mapa[x.F].F == passo ) continue;
		else if( seq &&  mapa[x.F].F == (passo-1)) {
			ret = (x.S + mapa[x.F].S); break;
		}
		mapa[x.F] = pii(passo,x.S);

		if( x.S < 9){ 
			fr(i,0,6){
				ll aux = x.F, next = 15;
				fr(j,0,12){
					next += (aux % (1<<4)) * mov[(i*12)+j];
					aux >>= 4;
				}
				fila.push( mp(next, (x.S + 1)));
			}

		}
	}
	return ret;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	cin >> t;
	ll cur,a,b; pot[0] =1;
	fr(i,1,12) pot[i] = pot[i-1] << 4; 
	for(int i=11; i>=0;i--)	{
		fr(j,0,6){
			mov[(j*12)+i] = pot[mov[(j*12)+i]-1];
		}
		target += (i+1) * pot[i];
	}
	while(t--){
		passo++; cur = 0; seq = false;
		fr(i,0,12){
			cin >> a;
			cur += a * pot[i];
		}
		// cout << cur << " <<>> " << target << endl;
		ll aux = cur;
		int ret = bfs(cur);
		if( ret == -1) {
			passo++;
			seq = true;
			ret = bfs(target);
		}
		if( ret == -1) ret = 19;
		printf("%d\n", ret);
	}
	return 0;
}