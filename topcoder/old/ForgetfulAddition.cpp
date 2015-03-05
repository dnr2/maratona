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

struct ForgetfulAddition {
    int minNumber(string expression) {
		int sz = expression.size();
		int resp = INF;
		if( sz == 2) return (expression[0] - '0') + (expression[1] - '0');
		REP(i,0,sz-1){
			int a = 0, b =0;
			REP(j,0,i+1){
				a *= 10;
				a += expression[j] - '0';
			}
			REP(j,i+1,sz){
				b *= 10;
				b += expression[j] - '0';
			}
			resp= min( resp, a + b);
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
			string expression         = "22";
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = ForgetfulAddition().minNumber(expression);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string expression         = "123";
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = ForgetfulAddition().minNumber(expression);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string expression         = "1289";
			int expected__            = 101;

			std::clock_t start__      = std::clock();
			int received__            = ForgetfulAddition().minNumber(expression);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string expression         = "31415926";
			int expected__            = 9067;

			std::clock_t start__      = std::clock();
			int received__            = ForgetfulAddition().minNumber(expression);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string expression         = "98765";
			int expected__            = 863;

			std::clock_t start__      = std::clock();
			int received__            = ForgetfulAddition().minNumber(expression);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string expression         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ForgetfulAddition().minNumber(expression);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string expression         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ForgetfulAddition().minNumber(expression);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string expression         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ForgetfulAddition().minNumber(expression);
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
Alice had two positive integers, a and b.
She typed the expression "a+b" into her computer, but the '+' key malfunctioned.
For example, instead of "128+9" the computer's screen now shows "1289".



Later, Bob saw the string on the screen.
He knows that the '+' sign is missing but he does not know where it belongs.
He now wonders what is the smallest possible result of Alice's original expression.



For example, if Bob sees the string "1289", Alice's expression is either "128+9" or "12+89" or "1+289".
These expressions evaluate to 137, 101, and 290.
The smallest of those three results is 101.



You are given a string expression that contains the expression on Alice's screen.
Compute and return the smallest possible result after inserting the missing plus sign


DEFINITION
Class:ForgetfulAddition
Method:minNumber
Parameters:string
Returns:int
Method signature:int minNumber(string expression)


CONSTRAINTS
-expression will contain between 2 and 8 characters, inclusive.
-Each character of expression will be between '1' and '9'.


EXAMPLES

0)
"22"

Returns: 4

The only possible expression Alice could have typed is "2+2". Thus, Bob knows this evaluates to 4.

1)
"123"

Returns: 15

The expression Alice has typed could have been "1+23" or "12+3". Of these two, the second is smaller, thus Bob will get the answer 15. 

2)
"1289"

Returns: 101

This is the example from the problem statement.

3)
"31415926"

Returns: 9067



4)
"98765"

Returns: 863



**/
// END CUT HERE
