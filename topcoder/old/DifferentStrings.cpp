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

struct DifferentStrings {
    int minimize(string A, string B) {		
		int sa = A.size() , sb = B.size();
		int resp = 10000;
		REP(i,0,sb-sa+1){
			int cont = 0;
			REP(j,0,sa){
				if( A[j] != B[i+j]) cont++;
			}
			resp = min (resp ,cont);
		}
        return resp;
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
			string A                  = "koder";
			string B                  = "topcoder";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string A                  = "hello";
			string B                  = "xello";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string A                  = "abc";
			string B                  = "topabcoder";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string A                  = "adaabc";
			string B                  = "aababbc";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string A                  = "giorgi";
			string B                  = "igroig";
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
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
// If X and Y are two strings of equal length N, then the difference between them is defined as the number of indices i where the i-th character of X and the i-th character of Y are different.  For example, the difference between the words "ant" and "art" is 1.

You are given two strings, A and B, where the length of A is less than or equal to the length of B.  You can apply an arbitrary number of operations to A, where each operation is one of the following:


Choose a character c and add it to the beginning of A.
Choose a character c and add it to the end of A.


Apply the operations in such a way that A and B have the same length and the difference between them is as small as possible.  Return this minimum possible difference.

DEFINITION
Class:DifferentStrings
Method:minimize
Parameters:string, string
Returns:int
Method signature:int minimize(string A, string B)


CONSTRAINTS
-A and B will each contain between 1 and 50 characters, inclusive.
-A and B will both contain only lowercase letters ('a'-'z').
-The length of A will be less than or equal to the length of B.


EXAMPLES

0)
"koder"
"topcoder"

Returns: 1

You can prepend "top" to "koder" and you'll get "topkoder". The difference between "topkoder" and "topcoder" is 1.

1)
"hello"
"xello"

Returns: 1

A and B already have the same length so you cannot add any characters to A.

2)
"abc"
"topabcoder"

Returns: 0



3)
"adaabc"
"aababbc"

Returns: 2



4)
"giorgi"
"igroig"

Returns: 6



**/
// END CUT HERE
