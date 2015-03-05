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

struct FoxConnection4 {
    int howManyWays(vector <string> board, int k) {
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
			string board[]            = {"....."}
;
			int k                     = 3;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".#.#",
 "#.#.",
 ".#.#",
 "#.#."}
;
			int k                     = 2;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"##.",
 "...",
 ".##"}
;
			int k                     = 3;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"....",
 "....",
 "....",
 "...."};
			int k                     = 4;
			int expected__            = 113;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {".....#....",
 ".#........",
 "....#.##..",
 "#......#..",
 "....#.....",
 "..........",
 ".##....#..",
 "..##......",
 "........##",
 "......#.#."}
;
			int k                     = 8;
			int expected__            = 22369;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
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
// The cities in Gridland form a rectangular grid.
Some of the cities can be inhabited by foxes.
We will call those cities available.
You are given the map of Gridland in a vector <string> board.
The character '.' (period) represents an available city, the character '#' a city that is not available.
Two cities are considered adjacent if they lie next to each other in the same row or in the same column.


You are also given an int k, meaning that k foxes would like to move into Gridland.
Each fox must choose a different available city.
Additionally, the set of cities they choose must be connected.
(Formally, for each pair of cities that will be inhabited by our foxes there must be a way of reaching one from the other if you can only travel between adjacent cities and you can only travel via cities inhabited by our foxes.)


Let X be the number of ways in which the foxes can choose their k cities.
Return the value (X modulo 1,000,000,009).


Two ways of choosing the cities are different if a city is chosen in one of them but not in the other.
(In other words, the foxes are indistinguishable.)

DEFINITION
Class:FoxConnection4
Method:howManyWays
Parameters:vector <string>, int
Returns:int
Method signature:int howManyWays(vector <string> board, int k)


CONSTRAINTS
-board will contain between 1 and 10 elements, inclusive.
-Every element in board will contain same number of characters.
-Each element in board will contain between 1 and 10 characters, inclusive.
-Each character in board will be '.' or '#'.
-k will be between 1 and 8, inclusive.


EXAMPLES

0)
{"....."}

3

Returns: 3

There are 3 ways: "xxx..", ".xxx.", "..xxx".

1)
{".#.#",
 "#.#.",
 ".#.#",
 "#.#."}

2

Returns: 0

There are two foxes, but no two available cities are adjacent. Thus, there is no valid way to select the cities for the foxes.

2)
{"##.",
 "...",
 ".##"}

3

Returns: 3



3)
{"....",
 "....",
 "....",
 "...."}
4

Returns: 113



4)
{".....#....",
 ".#........",
 "....#.##..",
 "#......#..",
 "....#.....",
 "..........",
 ".##....#..",
 "..##......",
 "........##",
 "......#.#."}

8

Returns: 22369



**/
// END CUT HERE
