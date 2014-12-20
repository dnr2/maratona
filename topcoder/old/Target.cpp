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

struct Target {
    vector <string> draw(int n) {
		vector<string> ret(n);
		REP(i,0,n){
			ret[i] = "";
			REP(j,0,n) ret[i] += " ";
			//db( i _ ret[i]);
		}
		for(int s = 0; s < n; s+=2){
			for(int i = s; i < n-s; i++){
				ret[i][s] = '#';
				ret[s][i] = '#';
				ret[i][n-s-1] = '#';
				ret[n-s-1][i] = '#';				
			}
		}
        return ret;
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
	template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) { 
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
			int n                     = 5;
			string expected__[]       = {"#####", "#   #", "# # #", "#   #", "#####" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Target().draw(n);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int n                     = 9;
			string expected__[]       = {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Target().draw(n);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int n                     = 13;
			string expected__[]       = {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Target().draw(n);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int n                     = 17;
			string expected__[]       = {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = Target().draw(n);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = Target().draw(n);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = Target().draw(n);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = Target().draw(n);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// Here at [topcoder], we call a contestant a "target" if their rating is 3000 or more.
In the arena, the targets have a red icon with a small target on it.
Do you want to become a target as well?
Sure you do.
But before you get there, let's start with something easier: drawing a target.



The target you need to draw consists of nested squares.
The innermost square is just a single '#' character.
The larger squares use alternatingly the character ' ' (space) and the character '#'.
Here is an example in which the side of the largest square is n = 5:




#####
#   #
# # #
#   #
#####



And here is an example for n = 9:



#########
#       #
# ##### #
# #   # #
# # # # #
# #   # #
# ##### #
#       #
#########




You will be given an int n.
Your method must return a vector <string> which contains a drawing of the target with side n.
More precisely, each element of the returned vector <string> must be one row of the drawing, in order.
Therefore, the returned vector <string> will consist of n elements, each with n characters.
(See the examples below for clarification.)



The value of n will be such that a target like the ones above can be drawn: 5, 9, 13, and so on.
Formally, n will be of the form 4k+1, where k is a positive integer.

DEFINITION
Class:Target
Method:draw
Parameters:int
Returns:vector <string>
Method signature:vector <string> draw(int n)


CONSTRAINTS
-n will be between 5 and 49, inclusive.
-n mod 4 will be 1.


EXAMPLES

0)
5

Returns: {"#####", "#   #", "# # #", "#   #", "#####" }



1)
9

Returns: {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" }



2)
13

Returns: {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" }



3)
17

Returns: {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" }



**/
// END CUT HERE
