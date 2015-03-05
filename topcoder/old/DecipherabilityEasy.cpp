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

struct DecipherabilityEasy {
    string check(string s, string t) {
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
			string s                  = "sunuke";
			string t                  = "snuke";
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "snuke";
			string t                  = "skue";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "snuke";
			string t                  = "snuke";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "snukent";
			string t                  = "snuke";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "aaaaa";
			string t                  = "aaaa";
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string s                  = "aaaaa";
			string t                  = "aaa";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string s                  = "topcoder";
			string t                  = "tpcoder";
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string s                  = "singleroundmatch";
			string t                  = "singeroundmatc";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = DecipherabilityEasy().check(s, t);
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
// You had a non-empty string s but you lost it.
Cat Snuke found the string and removed one character from the string.
Later, Snuke gave you the string t.
Can this be the string created from your string s?

You are given the strings s and t.
Return "Possible" (quotes for clarity) if t can be obtained from s by erasing exactly one character.
Otherwise, return "Impossible".
Note that the return value is case-sensitive.

DEFINITION
Class:DecipherabilityEasy
Method:check
Parameters:string, string
Returns:string
Method signature:string check(string s, string t)


CONSTRAINTS
-The number of characters in s will be between 1 and 50, inclusive.
-Every character in s will be a lowercase letter ('a'-'z').
-The number of characters in t will be between 1 and 50, inclusive.
-Every character in t will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"sunuke"
"snuke"

Returns: "Possible"

If Cat Snuke erase the first 'u' from s, it will equal to t.

1)
"snuke"
"skue"

Returns: "Impossible"

Swapping characters is not allowed.

2)
"snuke"
"snuke"

Returns: "Impossible"

Erasing nothing is not allowed.

3)
"snukent"
"snuke"

Returns: "Impossible"

Cat Snuke can erase exactly one character.

4)
"aaaaa"
"aaaa"

Returns: "Possible"



5)
"aaaaa"
"aaa"

Returns: "Impossible"



6)
"topcoder"
"tpcoder"

Returns: "Possible"



7)
"singleroundmatch"
"singeroundmatc"

Returns: "Impossible"



**/
// END CUT HERE
