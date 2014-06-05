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

struct CorrectMultiplicationTwo {
    int getMinimum(int a, int b, int c) {
        return int(0);
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			int a                     = 19;
			int b                     = 28;
			int c                     = 522;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 10;
			int b                     = 30;
			int c                     = 500;
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 111;
			int b                     = 111;
			int c                     = 12321;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 1000;
			int b                     = 100;
			int c                     = 10;
			int expected__            = 1089;

			std::clock_t start__      = std::clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a                     = 399;
			int b                     = 522;
			int c                     = 199999;
			int expected__            = 24;

			std::clock_t start__      = std::clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
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
// Krolik found a sheet of paper with an equation containing three positive integers: 
"a * b = c". 
This equation might be wrong, 
so Krolik is trying to make it correct by adjusting the numbers a, b, and c. 

You are given three ints a, b, and c. 
Return a int containing the minimum value of |A - a| + |B - b| + |C - c|, 
where A, B, and C are positive integers satisfying A * B = C. 


DEFINITION
Class:CorrectMultiplicationTwo
Method:getMinimum
Parameters:int, int, int
Returns:int
Method signature:int getMinimum(int a, int b, int c)


NOTES
-|x| is the absolute value of x (which is x for non-negative x and (-x) for negative x). 


CONSTRAINTS
-a, b, and c will each be between 1 and 1,000,000, inclusive. 


EXAMPLES

0)
19
28
522

Returns: 2

By assigning A = 18, B = 29, and C = 522 the value of |A - a| + |B - b| + |C - c| is minimized. 


1)
10
30
500

Returns: 11

2)
111
111
12321

Returns: 0

3)
1000
100
10

Returns: 1089

Note that A, B, and C must be positive integers. 


4)
399
522
199999

Returns: 24

**/
// END CUT HERE
