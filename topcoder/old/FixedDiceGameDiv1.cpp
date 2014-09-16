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

struct FixedDiceGameDiv1 {
    double getExpectation(int a, int b, int c, int d) {
        return double(0);
    }
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int a                     = 1;
			int b                     = 2;
			int c                     = 1;
			int d                     = 5;
			double expected__         = 2.0;

			std::clock_t start__      = std::clock();
			double received__         = FixedDiceGameDiv1().getExpectation(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 3;
			int b                     = 1;
			int c                     = 1;
			int d                     = 3;
			double expected__         = 3.0;

			std::clock_t start__      = std::clock();
			double received__         = FixedDiceGameDiv1().getExpectation(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 1;
			int b                     = 5;
			int c                     = 1;
			int d                     = 1;
			double expected__         = 3.4999999999999996;

			std::clock_t start__      = std::clock();
			double received__         = FixedDiceGameDiv1().getExpectation(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 2;
			int b                     = 6;
			int c                     = 50;
			int d                     = 30;
			double expected__         = -1.0;

			std::clock_t start__      = std::clock();
			double received__         = FixedDiceGameDiv1().getExpectation(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a                     = 50;
			int b                     = 11;
			int c                     = 50;
			int d                     = 50;
			double expected__         = 369.8865999182022;

			std::clock_t start__      = std::clock();
			double received__         = FixedDiceGameDiv1().getExpectation(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = FixedDiceGameDiv1().getExpectation(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = FixedDiceGameDiv1().getExpectation(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = FixedDiceGameDiv1().getExpectation(a, b, c, d);
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
// 
Alice and Bob are playing a game.
Alice rolls a identical b-sided dice.
Bob rolls c identical d-sided dice.
The sides of an n-sided die have numbers 1 through n written on them.



A player's score is the sum of the numbers they rolled on their dice.
The player with a strictly higher score wins.
It is possible that neither player wins.



You are given the ints a, b, c, and d.
The players already rolled their dice.
If it's not possible for Alice to win, return -1.
Otherwise, assume that you don't know what numbers Alice and Bob rolled, but that you know that Alice won the game.
Return the expected value of Alice's score (given the above assumption).


DEFINITION
Class:FixedDiceGameDiv1
Method:getExpectation
Parameters:int, int, int, int
Returns:double
Method signature:double getExpectation(int a, int b, int c, int d)


NOTES
-Your return value must have an absolute or relative error smaller than 1e-3. 


CONSTRAINTS
-a, b, c, d will each be between 1 and 50, inclusive.


EXAMPLES

0)
1
2
1
5

Returns: 2.0

The only way Alice can win is if she rolls a 2. Thus, if we know Alice wins, we know she rolled a 2. 

1)
3
1
1
3

Returns: 3.0

Alice will always roll a 3. 

2)
1
5
1
1

Returns: 3.4999999999999996

Alice will not win if she rolls a 1. Thus, if we know she wins, her expected score is (2+3+4+5)/4=7/2.

3)
2
6
50
30

Returns: -1.0

No matter what Alice rolls, she will lose. 

4)
50
11
50
50

Returns: 369.8865999182022



**/
// END CUT HERE
