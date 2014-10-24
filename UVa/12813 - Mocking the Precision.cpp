//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4678
//#tag math matematica
//#sol

#include <bits/stdc++.h>
#include <new> 

#define fr(i,m,n) for(int i = (m); i < (n); ++i)

#define st first
#define nd second

#define clr(a, b) memset(a, b, sizeof a)

#define sd(x) scanf("%d", &x);
#define spii(x) scanf("%d %d", &x.st, &x.nd)
#define ss(x) scanf(" %s", x)

#define dbg(x) cout << x << endl
#define db2(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, pdd> pdv;

ll gcd(ll a, ll b) { 
	while(a){ 
		b %= a; 
		swap(a, b); 
	} 
	return b;
}

struct frac
{
	ll a, b;
	frac(){}
	frac(ll x) : a(x), b(1) {}
	frac(ll aa, ll bb)  {
		ll g = gcd( aa, bb );
		a = aa/g;
		b = bb/g;
	}
	void simplify()
	{
		ll x = gcd(a, b);
		a /= x;
		b /= x;
	}
};
frac operator + (frac a, frac b) { 
	ll lcm = a.b * (b.b / gcd(a.b, b.b));
	return frac( a.a * (lcm/a.b) + b.a * (lcm/b.b) , lcm );
	//return frac( a.a * b.b + b.a * a.b, b.b * a.b); 
}

char * str;

ll power[15];

int main()
{
	ll a, b, c;
	str = new char[1000];
	power[0] = 1;
	fr(i,1,15) power[i] = power[i-1] * 10;
	while(ss(str) == 1)
	{
		if(  str[0] == '-' ){
			printf("-");
			str = str + 1;
		}
		sscanf(str, "%lld", &a);
		char* p = strstr(str, ".");
		char* q = strstr(str, "(");
		char * pp = p + 1;
		char * qq = q + 1;
		ll nb = 0;
		ll nc = 0;
		
		if(p == NULL) b = -1; 
		else {
			sscanf(p + 1, "%lld", &b);
			for( ; *pp >= '0' && *pp <= '9' ; pp++) nb++;
		}	
		if(q == NULL) c = -1; 
		else {
			sscanf(q + 1, "%lld", &c);
			for( ; *qq >= '0' && *qq <= '9' ; qq++) nc++;
		}
		if(p + 1== q) b = -1;
		
		if(b == -1 && c == -1)
		{
			printf("%lld\n", a);
		}
		else
		{
			frac x = frac(0);
			
			
			if(b != -1)
			{
				frac oi = frac( b, power[nb]);
				oi.simplify();				
				x = x + oi;
			}else nb = 0;			
			x.simplify();
			if(c != -1)
			{
				frac oi = frac( c, ( power[nc] - 1) * power[nb]);
				oi.simplify();				
				x = x + oi;
			}				
			x.simplify();
			a += x.a/x.b;
			x.a %= x.b;
			if(a) printf("%lld%c", a, x.a?' ':'\n');
			if(x.a)printf("%lld/%lld\n", x.a, x.b);
		}
	}
	
	return 0;
}