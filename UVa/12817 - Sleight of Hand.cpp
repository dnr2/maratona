//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=35&category=861&page=show_problem&problem=4682
//#tag math matematica
//#tag probability probabilidade
//#sol To calculate the probability you have to consider four cases. Assume that someone in the crowd (guesser) 
// predicts a color X (with the probability of making the right prediction equal to his RV) and the real color 
// of the coin is Y (with probability PY). So the guesser can be either right or wrong about the coin.
// case 1 - the guesser is right given that X == Y , probability P(Case1) = RV * PY
// case 2 - the guesser is wrong given that X == Y , probability P(Case2) = (1-RV) * PY
// case 3 - the guesser is right given that X != Y , probability P(Case3) = RV * (1-PY)
// case 4 - the guesser is wrong given that X != Y , probability P(Case4) = (1-RV) * (1-PY)
// So cases 2 and 3 are impossible, since the events have a contradiction. So you have to calculate the probability 
// considering only cases 1 and cases 4, so the total probability mass is P(Case1) + P(Case4), and the actual probability
// of the coin being Y is  P(Case1) / (P(Case1) + P(Case4)). Apply the same logic for more than one guesser.

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

const int MAXN = 100;

int main(){
	
	double r;
	while(scanf("%lf", &r) > 0){
		int n; scanf("%d", &n);
		double m1 = 1, m2 = 1, rv = 0;
		char tmp;
		REP(i,0,n){
			scanf(" %c%lf", &tmp, &rv);			
			if( tmp == 'P') rv = 1 - rv;
			m1 *= rv;
			m2 *= (1 - rv);
		}
		double red = r * m1 / ( r * m1 + (1-r) * m2);
		printf("%.6lf %.6lf\n" , red, (1-red) );
	}
	return 0;
}