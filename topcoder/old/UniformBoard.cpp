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

struct UniformBoard {
    int getBoard(vector <string> board, int K) {
		vector <string> b = board;
		
		int n = b.size(), m = b[0].size();
		int na=0, np=0, ne=0;
		REP(x,0,n) REP(y,0,m) {
			if( b[x][y]  == 'A') na++;
			else if( b[x][y]  == 'P') np++;
			else ne++;
		}
		int resp = 0;
		db( na );
		REP(x,0,n) REP(y,0,m) REP(z,x,n) REP(w,y,m){			
			int ia=0;
			bool ok = true;
			int tmp = 0;
			REP(i,x,z+1) REP(j,y,w+1) if( b[i][j] == 'A') ia++;
			REP(i,x,z+1){
				REP(j,y,w+1){
					if( b[i][j] == '.' ){
						if( na > ia ){
							tmp++; ia++;
						}
						else ok = false;
					}
					if( b[i][j]  == 'P'){
						if( ne > 0 && na > ia ){
							tmp+=2; ia++;
						} else {
							ok = false;
						}
					}					
					if( ok == false ) break;
				} 
				if( ok == false ) break; 				
			}
			if( (z-x+1) * (w-y+1) == 121 ) db( ia _ tmp);
			if( ok && tmp <= K){				
				resp = max( resp, (z-x+1) * (w-y+1));
			}
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
			string board[]            = {"AP",
 ".A"};
			int K                     = 0;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"AP",
 ".A"};
			int K                     = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"PPP",
 "APA",
 "A.P"};
			int K                     = 2;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"AAA",
 "PPP",
 "AAA"};
			int K                     = 10;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"."};
			int K                     = 1000;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"};
			int K                     = 10;
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			string board[]            = {	"AAAAAAAAAAA", 
											"AAAAAAAA.AA", 
											"AAAAAA..AAA", 
											"AAAAAA.AAAA", 
											"AA.AAAAAAAA", 
											"AAAAAAAAAAA", 
											"AAAAAAAAAAA", 
											"AAA.AAAAAAA", 
											"AA.AAAAAAAA", 
											"AA.AAAAAAAA", 
											"AAAAAAAAAAA"}
;
			int K                     = 30;
			int expected__            = 110;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
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

A rectangular section of the board is called uniform if each cell in the rectangle contains an apple. After you are done moving the fruit, you want to have a uniform rectangle that is as large as possible somewhere on the board.
Return the largest possible area of such a rectangle. If there are no apples, return 0.

DEFINITION
Class:UniformBoard
Method:getBoard
Parameters:vector <string>, int
Returns:int
Method signature:int getBoard(vector <string> board, int K)


CONSTRAINTS
-N will be between 1 and 20, inclusive.
-board will contain exactly N elements.
-Each element of board will contain exactly N characters.
-Each character in board will be '.', 'A', or 'P'.
-K will be between 0 and 1000, inclusive.


EXAMPLES

0)
{"AP",
 ".A"}
0

Returns: 1

You cannot move anything.
The largest uniform rectangle on the board is a 1x1 rectangle that consists of a single cell with an apple.

1)
{"AP",
 ".A"}
1

Returns: 2

You are allowed to make one move.
You can move one of the apples onto the currently empty cell, thus creating a 1x2 rectangle of apples.

2)
{"PPP",
 "APA",
 "A.P"}
2

Returns: 3

In three moves you can create a 1x3 rectangle of apples.

3)
{"AAA",
 "PPP",
 "AAA"}
10

Returns: 3

You are allowed to make at most 10 moves.
However, you cannot make any moves because there are no empty cells.

4)
{"."}
1000

Returns: 0



5)
{"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}
10

Returns: 15



**/
// END CUT HERE
