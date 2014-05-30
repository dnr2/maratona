//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3695
//#tag Suffix Array , array de suffixo
//#tag Range Minimum Query, RMQ
//#tag Segment Tree, arvore de segmentos
//#sol first build a suffix array from the concatenation of the words in the dictionary. Then create a RMQ that stores a list,
//with the 10 best words for each range (considering the words pointed by the suffix array). for each query find the positions
//in the suffix array that corresponds to the suffix that are equal to the word in the query (find the all words 
//with substring). use RMQ to quickly get the top 10 words out of all the possible words with query as substring.

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
#include <set>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,y) memset(x,y,sizeof(x));
#define FOREACH(i,v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

#define NWORDS 30000

struct word{
	string str;
	int id;
	word( int id = 0) : id(id) { str = ""; }
	const bool operator < ( const word & in ) const {
		if( str.size() == in.str.size()){
			if( str == in.str) return id < in.id;
			return str < in.str;
		}		
		return str.size() < in.str.size();
	}
} words[NWORDS];

int pos[NWORDS];

#define POTS 500000

///segmenttree
int NSEG; // Number of fields (with indices $0,\dots,NSEG-1$)
list<int> field[POTS]; // WARNING: At least size $2\cdot2^k+10$ with $2^k>N$ and $k\in\mathbb Z^+$

bool cmp(int a, int b){
	return pos[a] < pos[b];
}

list<int> merge(list<int> a, list<int> b){
	a.merge(b,cmp);		
	a.unique();	
	list<int>::iterator it = a.begin();
	advance( it , min( ((int)a.size()), 10));
	list<int> ret( a.begin(), it );
	return ret;
}

// update(p,v) sets the value at p to v
void update(int p, int v, int i=0, int s=0, int e=NSEG) {
	if (p < s || p >= e)
		return;
	if (s+1 == e) {
		list<int> nel(1,v);
		field[i] = nel;
		return;
	}
	update(p, v, 2*i+1, s, (s+e)>>1);
	update(p, v, 2*i+2, (s+e)>>1, e);
	field[i] = merge(field[2*i+1], field[2*i+2]); // Change this if you want the minimum/sum/\dots
}

// query(a,b) returns the maximum/\dots\ of the values at $a,\dots,b-1$ (including a but excluding b!)
list<int> query(int a, int b, int i=0, int s=0, int e=NSEG) {
	if (b <= s || e <= a){
		list<int> ret;
		return ret; // Change this if you want the minimum/sum/\dots (should be a neutral element).
	} if (a <= s && e <= b)
		return field[i];
	return merge( // Change this if you want the minimum/sum/\dots
		query(a, b, 2*i+1, s, (s+e)>>1),
		query(a, b, 2*i+2, (s+e)>>1, e));
}


#define DOTS 500005

///suffixarray
int N;	// number of characters in a string
int RA[DOTS], SA[DOTS], tmpRA[DOTS], tmpSA[DOTS], cnt[DOTS]; // SA[i]: which suffix has rank i
char str[DOTS]; // the input string

void csort(int k){
	int cub = max(N, 300);	// take the maximum of the length of the strings and the number of unique chars
	FILL(cnt, 0);
	REP(i,0,N) cnt[i+k<N?RA[i+k]:0]++;
	REP(i,1,cub) cnt[i] += cnt[i-1];
	for(int i=cub-1;i>=1;i--) cnt[i] = cnt[i-1];
	cnt[0] = 0;
	REP(i,0,N) tmpSA[ cnt[SA[i]+k<N?RA[SA[i]+k]:0]++ ] = SA[i];
	REP(i,0,N) SA[i] = tmpSA[i];
}

void buildSA(){ // compute SA and RA
	REP(i,0,N){
		RA[i] = str[i];
		SA[i] = i;
	}
	int k = 1;
	while(k<N){
		csort(k); csort(0); 	// cannot reverse order
		int r = 0;
		tmpRA[SA[0]] = 0;
		REP(i,1,N){
			if(RA[SA[i]]!=RA[SA[i-1]] || RA[SA[i]+k]!=RA[SA[i-1]+k])
				r++;
			tmpRA[SA[i]] = r;
		}
		REP(i,0,N) RA[i] = tmpRA[i];
		if(RA[SA[N-1]]==N-1) break;
		k <<= 1;
	}
}

char buff[DOTS];
int owner[DOTS];

bool cmp2(int a, int b){	
	return str[a+b] < buff[b];
}

bool cmp3(int a, int b){	
	return str[a+b] > buff[a];
}

int main() {
	int n; cin >> n;
	N = 0;
	REP(i,0,n){
		scanf("%s", buff);
		words[i].str = string(buff);
		int len = words[i].str.size();
		words[i].id = i;
		buff[len++] = '$';
		buff[len] = 0;
		for(int j = 0; j < len; j++){
			str[N+j] = buff[j];
			owner[N+j] = i;
		}
		N+=len;
	}
	
	str[N] = 0;	
	NSEG = N;
	buildSA();
	
	sort( words, words + n);
	REP(i,0,n){
		pos[words[i].id] = i;		
	}
	
	REP(i,0,N){		
		update( i, owner[SA[i]] );
	}
	
	int q; cin >> q;
	REP(i,0,q){
		scanf("%s", buff);
		int sz = strlen( buff);
		int ini = 0, end = N;
		REP(i,0,sz){
			int a = lower_bound(SA+ini, SA+end, i, cmp2) - SA;
			int b = upper_bound(SA+ini, SA+end, i, cmp3) - SA;
			ini = a, end = b;			
			if( ini >= end) break;
		}
		list<int> tmp = query( ini, end );
		vector<int> resp(tmp.begin(), tmp.end());
		if( resp.size() == 0){
			puts("-1");
		} else {
			REP(j,0,((int)resp.size())){
				printf("%s%d", (j>0)?" ":"", resp[j]+1);
			}
			puts("");
		}
	}
	return 0;
}