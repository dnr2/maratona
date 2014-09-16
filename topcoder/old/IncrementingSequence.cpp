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

struct IncrementingSequence {
    string canItBeDone(int k, vector <int> A) {
        return string(0);
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
			int k                     = 3;
			int A[]                   = {1,2,4,3};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int k                     = 5;
			int A[]                   = {2,2};
			string expected__         = "IMPOSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int k                     = 1;
			int A[]                   = {1,1,1,1,1,1,1,1};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int k                     = 2;
			int A[]                   = {5,3,3,2,1};
			string expected__         = "IMPOSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int k                     = 9;
			int A[]                   = {1,2,3,1,4,5,6,7,9,8};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int k                     = 2;
			int A[]                   = {1,1,1,1,1,1,2,2,2,2,2,2};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int k                     = 1;
			int A[]                   = {1};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int k                     = ;
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int k                     = ;
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int k                     = ;
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
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
// You have a vector <int> A with N elements.

Your goal is to change it into a vector <int> that contains each number from 1 to N exactly once. The change will consist of zero or more steps. In each step, you may pick an arbitrary element of A and increment its value by k. You may pick the same element multiple times. Note that you are not allowed to decrement the value of any element.

You are given the int k and the vector <int> A.
Return "POSSIBLE" if it is possible to achieve your goal. Return "IMPOSSIBLE" otherwise.

DEFINITION
Class:IncrementingSequence
Method:canItBeDone
Parameters:int, vector <int>
Returns:string
Method signature:string canItBeDone(int k, vector <int> A)


NOTES
-Return value is case-sensitive. For example, you can't return "Possible" or "possible" instead of "POSSIBLE".


CONSTRAINTS
-k will be between 1 and 10, inclusive.
-A will contain between 1 and 50 elements, inclusive.
-Each element of A will be between 1 and 50, inclusive.


EXAMPLES

0)
3
{1,2,4,3}

Returns: "POSSIBLE"

This sequence of length 4 already contains all numbers from 1 to 4 exactly once. Note that their order does not matter.

1)
5
{2,2}

Returns: "IMPOSSIBLE"



2)
1
{1,1,1,1,1,1,1,1}

Returns: "POSSIBLE"

There are many ways to achieve the goal. For example, it is possible to obtain the sequence {1,2,3,4,5,6,7,8}. To do this, just increment the element at each position one by one until it reaches the required value.

3)
2
{5,3,3,2,1}

Returns: "IMPOSSIBLE"

We want to have the values {1,2,3,4,5}, in any order. Currently, we are missing the 4. As k=2, the only way to produce a 4 is by incrementing a 2. But if we increment our only 2, we will have no way of producing another 2.

4)
9
{1,2,3,1,4,5,6,7,9,8}

Returns: "POSSIBLE"



5)
2
{1,1,1,1,1,1,2,2,2,2,2,2}

Returns: "POSSIBLE"



6)
1
{1}

Returns: "POSSIBLE"



**/
// END CUT HERE
