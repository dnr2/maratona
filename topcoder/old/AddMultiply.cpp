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

struct AddMultiply {
    vector <int> makeExpression(int y) {
        return vector <int>(0);
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int y                     = 6;
			int expected__[]          = {2, 2, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int y                     = 11;
			int expected__[]          = {2, 3, 5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int y                     = 0;
			int expected__[]          = {7, 10, -70 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int y                     = 500;
			int expected__[]          = {-400, -3, -700 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int y                     = 2;
			int expected__[]          = {2, 2, -2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int y                     = 5;
			int expected__[]          = {5, 2, -5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int y                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int y                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int y                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = AddMultiply().makeExpression(y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// You are given an int y.
We are looking for any vector <int> x that satisfies the following constraints:

x has exactly three elements
( x[0] * x[1] ) + x[2] = y
Each x[i] must be between -1000 and 1000, inclusive.
No x[i] can be equal to 0 or 1.

Find and return one such x.

If there are multiple valid solutions, you may return any of them.
You may assume that for our constraints on y (specified below) at least one valid x always exists.

DEFINITION
Class:AddMultiply
Method:makeExpression
Parameters:int
Returns:vector <int>
Method signature:vector <int> makeExpression(int y)


CONSTRAINTS
-y will be between 0 and 500, inclusive.


EXAMPLES

0)
6

Returns: {2, 2, 2 }

2*2 + 2 = 6

Note that this is one of many possible solutions. Another solution is:

3*3 + (-3) = 6


1)
11

Returns: {2, 3, 5 }



2)
0

Returns: {7, 10, -70 }

Note that 0 and 1 are not allowed, thus a result like 0 * 0 + 0 would be incorrect.

3)
500

Returns: {-400, -3, -700 }

Some or all of the returned numbers may be negative.

4)
2

Returns: {2, 2, -2 }



5)
5

Returns: {5, 2, -5 }



**/
// END CUT HERE
