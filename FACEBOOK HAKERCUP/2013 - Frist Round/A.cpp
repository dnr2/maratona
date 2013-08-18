
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
#include <sstream>
#include <climits>

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
#define EPS 1e-9
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

ll in[10000];

class Binomial
{
public:
    Binomial(int Max = 10000)
    {
        max = Max+1;
        table = new ll * [max]();
        for (int i=0; i < max; i++)
        {
            table[i] = new ll[max]();

            for (int j = 0; j < max; j++)
            {
                table[i][j] = 0;
            }
        }
    }

    ~Binomial()
    {
        for (int i =0; i < max; i++)
        {
            delete table[i];
        }
        delete table;
    }

    ll Choose(ll n, ll k);

private:
    bool Contains(ll n, ll k);

    int max;
    ll **table;
};

ll Binomial::Choose(ll n, ll k)
{
    if (n < k) return 0;
    if (k == 0 || n==1 ) return 1;
    if (n==2 && k==1) return 2;
    if (n==2 && k==2) return 1;
    if (n==k) return 1;


    if (Contains(n,k))
    {
        return table[n][k];
    }
    table[n][k] = Choose(n-1,k) + Choose(n-1,k-1);
    return table[n][k] % 1000000007;
}

bool Binomial::Contains(ll n, ll k)
{
    if (table[n][k] == 0) 
    {
        return false;
    }
    return true;
}


int main(){
	
	int t; cin >> t; int n , k, caso = 1;
	Binomial bin;
	// db ( bin.Choose( 10000, 5000) );
	// db ( bin.Choose( 9999, 5000) );
	// db ( bin.Choose( 9998, 5000) );
	// db ( bin.Choose( 9997, 5000) );
	
	// db ( bin.Choose( 4, 3) );
	// db ( bin.Choose( 4, 3) );
	while(t--){
		scanf("%d%d", &n, &k );
		fr(i,0,n) scanf("%lld", in+i);
		sort( in, in+n , greater<int>());
		ll resp = 0;
		
		fr(i,0,n){
			if( n - i -1 < k -1 ) break;
			resp += bin.Choose( n - i - 1, k-1) * in[i] ; 
			// db( i _ bin.Choose( n - i - 1, k-1) * in[i] ) 
			resp = resp % 1000000007;
		}
		resp = resp % 1000000007;
		printf("Case #%d: ", caso++);
		cout << resp << endl;
	}
	return 0;
}