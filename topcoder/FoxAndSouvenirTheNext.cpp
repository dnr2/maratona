#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;

#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define EPS 1e-9
#define INF 1e9
#define FILL(x,v) memset( (x), (v), sizeof( (x)))
const int maxn = 60;
int dp[maxn][maxn][maxn*maxn];
int sum[maxn];
vector <int> val;
int n;

bool rec( int p1, int p2, int s1){
	int s2 = 0;
	if( p1 + p2 > 0 ) s2 = sum[p1+p2-1] - s1;
	if( p1 + p2 >= n) return s1 == s2 && p1 == p2;
	if( dp[p1][p2][s1] != -1) return  dp[p1][p2][s1];
	bool ret = false;
	
	ret = ret || rec( p1 + 1, p2, s1 + val[p1+p2] );
	ret = ret || rec( p1, p2 + 1, s1 );
	return (dp[p1][p2][s1] = ret);
}


struct FoxAndSouvenirTheNext {
    string ableToSplit(vector <int> value) {
		val = value;
		memset(dp,-1,sizeof(dp));
		memset(sum,0,sizeof(sum));		
		n = value.size();
		// db( n);
		sum[0] = val[0];
		REP(i,1,n){
			sum[i] = val[i] + sum[i-1];			
		}
		
		if( rec( 0, 0 , 0 )){
			return "Possible";
		} else {
			return "Impossible";
		}
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int value[]               = {1,2,3,4};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int value[]               = {1,1,1,3};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int value[]               = {1,1,2,3,5,8};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int value[]               = {2,3,5,7,11,13};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int value[]               = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int value[]               = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int value[]               = {2,2};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int value[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int value[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE

// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel just returned home from her trip to New Fox City.
She has brought a bunch of souvenirs.
You are given their values in a vector <int> value.


Now she wants to give each souvenir either to her mother or to her father.
She would like to divide the souvenirs in a fair way.
More precisely:

The total number of souvenirs given to her mother must be the same as the total number of souvenirs given to her father.
At the same time, the total value of souvenirs given to her mother must be the same as the total value of souvenirs given to her father.



Return "Possible" if she can reach her goal, and "Impossible" otherwise.

DEFINITION
Class:FoxAndSouvenirTheNext
Method:ableToSplit
Parameters:vector <int>
Returns:string
Method signature:string ableToSplit(vector <int> value)


CONSTRAINTS
-value will contain between 1 and 50 elements, inclusive.
-Each element in value will be between 1 and 50, inclusive.


EXAMPLES

0)
{1,2,3,4}

Returns: "Possible"

One valid solution is to give the souvenirs with values 1 and 4 to her mother and the other two to her father. Each parent receives two souvenirs, and as 1+4 = 2+3, the total value is also the same for both parents.

1)
{1,1,1,3}

Returns: "Impossible"

There is no valid solution. Note that {1,1,1} and {3} is not a valid way to split the souvenirs: even though the total value is the same, the number of souvenirs is not.

2)
{1,1,2,3,5,8}

Returns: "Possible"

We have 1+1+8 = 2+3+5.

3)
{2,3,5,7,11,13}

Returns: "Impossible"

The sum of values is an odd number, so it is impossible.

4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}

Returns: "Possible"



5)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}

Returns: "Impossible"



**/
// END CUT HERE
