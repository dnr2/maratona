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

struct TopView {
    string findOrder(vector <string> grid) {
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
			string grid[]             = {"..AA..",
 ".CAAC.",
 ".CAAC."};
			string expected__         = "CA";

			std::clock_t start__      = std::clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"..47..",
 "..74.."}
;
			string expected__         = "ERROR!";

			std::clock_t start__      = std::clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"bbb666",
 ".655X5",
 "a65AA5",
 "a65AA5",
 "a65555"};
			string expected__         = "65AXab";

			std::clock_t start__      = std::clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"aabbaaaaaaaaaaaaaaaaaa",
 "aabbccccccccccccccaaaa",
 "aab11111ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ddddddddddaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aa.11111DDDDDDDDDDaaaa",
 "aaaaaaaaaaaaaaaaaaaaaa"};
			string expected__         = "ERROR!";

			std::clock_t start__      = std::clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string grid[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string grid[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string grid[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
// Ralph was once playing with a set of cards and a grid of cells.
Each card was a rectangle of a unique color.
Different cards may have had different dimensions.
Ralph took his cards one at a time, and placed each of them onto the grid.
When placing a card, Ralph aligned its sides with grid lines, so each card covered some rectangular block of cells.
Some cards may have overlapped other, previously placed cards partially or even completely.
Once all the cards were placed, on each cell only the topmost card was visible.

You are given a vector <string> grid that describes what Ralph could see after placing the cards. The j-th character of element i of grid is '.' if the cell at position (i,j) is empty (does not contain any card) or is an alphanumeric character that represents the only color Ralph could see when looking at the cell.

Ralph does not remember the order he used to place the cards. Write a program that finds the order in which the cards of each visible color were placed.  The return value should be a string, containing exactly once each of the alphanumeric characters that occur in grid.
The i-th character of the return value should be the color of the i-th card (0-based index) that Ralph placed.
In case there are multiple valid orders, return the lexicographically smallest one.
In case there is no valid order of colors, return "ERROR!" (quotes for clarity).

DEFINITION
Class:TopView
Method:findOrder
Parameters:vector <string>
Returns:string
Method signature:string findOrder(vector <string> grid)


NOTES
-The letters in grid are case-sensitive: 'a' and 'A' are distinct colors.
-The lexicographically smaller of two strings of equal length is the one that has the earlier character (using ASCII ordering) at the first position at which they differ.


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-All elements of grid will contain the same number of characters.
-Each character in each element of grid will be a period ('.'), an uppercase letter ('A'-'Z'), a lowercase letter ('a'-'z'), or a digit ('0'-'9').
-At least one character in grid will be different from '.'.


EXAMPLES

0)
{"..AA..",
 ".CAAC.",
 ".CAAC."}

Returns: "CA"

The card with color C is a rectangle of 2 rows and 4 columns. The card with color A, a rectangle of 3 rows and 2 columns, was placed on top of it.

1)
{"..47..",
 "..74.."}


Returns: "ERROR!"

Each card has a unique color, this top perspective view tells us about 2 cards. This setting is not possible without using multiple cards of color 4 or 7.

2)
{"bbb666",
 ".655X5",
 "a65AA5",
 "a65AA5",
 "a65555"}

Returns: "65AXab"



3)
{"aabbaaaaaaaaaaaaaaaaaa",
 "aabbccccccccccccccaaaa",
 "aab11111ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ddddddddddaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aa.11111DDDDDDDDDDaaaa",
 "aaaaaaaaaaaaaaaaaaaaaa"}

Returns: "ERROR!"



**/
// END CUT HERE
