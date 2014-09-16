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

struct ApplesAndPears {
    int getArea(vector <string> board, int K) {
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
			string board[]            = {".A",
 "P."};
			int K                     = 0;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndPears().getArea(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".A",
 "P."};
			int K                     = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndPears().getArea(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {".PP", 
 "PPA", 
 "PAP"};
			int K                     = 3;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndPears().getArea(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."};
			int K                     = 10;
			int expected__            = 21;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndPears().getArea(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndPears().getArea(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndPears().getArea(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ApplesAndPears().getArea(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
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
// A square board is divided into N rows by N columns of unit square cells.
Some cells of the board are empty.
Each of the other cells contains either an apple or a pear.
You are given the current state of the board as a vector <string> board.
In board, the character '.' denotes an empty cell, 'A' denotes an apple, and 'P' denotes a pear.

You are allowed to perform at most K moves.
In each move, you can pick up one fruit (an apple or a pear) and place it onto any empty cell.
(The new cell doesn't have to be adjacent to the old one.)
Note that you cannot remove fruit from the board, you are only allowed to move it onto different cells.

A rectangular section of the board is called uniform if all cells in the rectangle are the same:
that is, either all those cells contain apples, or they all contain pears, or all of them are empty.
After you are done moving the fruit, you want to have a uniform rectangle that is as large as possible somewhere on the board.
Return the largest possible area of such a rectangle.

DEFINITION
Class:ApplesAndPears
Method:getArea
Parameters:vector <string>, int
Returns:int
Method signature:int getArea(vector <string> board, int K)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-board will contain exactly N elements.
-Each element of board will contain exactly N characters.
-Each character in board will be '.', 'A', or 'P'.
-K will be between 0 and 1000, inclusive.


EXAMPLES

0)
{".A",
 "P."}
0

Returns: 1

As K=0, you are not allowed to make any moves.
Currently, the largest uniform rectangle is just a single cell.

1)
{".A",
 "P."}
1

Returns: 2

Move any piece of fruit onto any of the two currently empty cells.
After the move, there will be two adjacent empty cells.
These form a 2x1 uniform rectangle.

2)
{".PP", 
 "PPA", 
 "PAP"}
3

Returns: 6

In three moves, you can create a 3x2 rectangle of cells that contain pears.

3)
{"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."}
10

Returns: 21



**/
// END CUT HERE
