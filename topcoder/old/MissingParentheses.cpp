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

int dp[100][100];
string str;

int rec(int a, int b){
	if( dp[a][b] != -1) return dp[a][b];
	if( a == b) return 1;
	if( a + 1 == b){
		if( str[a] == '(' and str[b] == ')') return 0;
		else return 2;
	}
	int ret = INF;
	if( str[a] == '(' && str[b] == ')') ret = rec( a+ 1, b -1);
	REP(i,a,b){
		ret = min( ret, rec( a,i) + rec( i+1,b));
	}
	return dp[a][b] = ret;
}

struct MissingParentheses {
	
    int countCorrections(string par) {
		memset(dp, -1, sizeof(dp));
		str = par;
        return rec( 0, par.size()-1);
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
			string par                = "(()(()";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string par                = "()()(()";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string par                = "(())(()())";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string par                = "())(())((()))))()((())))()())())())()()()";
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string par                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string par                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string par                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MissingParentheses().countCorrections(par);
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
Given a string of parentheses, you must turn it into a well formed string by inserting as few parentheses as possible, at any position (you cannot delete or change any of the existing parentheses).

A well formed string of parentheses is defined by the following rules:

    The empty string is well formed.
    If s is a well formed string, (s) is a well formed string.
    If s and t are well formed strings, their concatenation st is a well formed string.

As examples, "(()())", "" and "(())()" are well formed strings and "())(", "()(" and ")" are malformed strings.

Given a string par of parentheses, return the minimum number of parentheses that need to be inserted to make it into a well formed string.


DEFINITION
Class:MissingParentheses
Method:countCorrections
Parameters:string
Returns:int
Method signature:int countCorrections(string par)


CONSTRAINTS
-par will contain between 1 and 50 characters, inclusive.
-Each character of par will be an opening or closing parenthesis, i.e., '(' or ')'.


EXAMPLES

0)
"(()(()"

Returns: 2

The string below is a possible well formed string you can get to by inserting the two closing parentheses marked.

(())(())
   ^   ^


1)
"()()(()"

Returns: 1

You can fix the string by inserting a single closing parenthesis at the end.

2)
"(())(()())"

Returns: 0

The input string is well formed, so no insertion is needed.

3)
"())(())((()))))()((())))()())())())()()()"

Returns: 7



**/
// END CUT HERE
