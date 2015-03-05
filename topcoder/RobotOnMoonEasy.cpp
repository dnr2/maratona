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

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

struct RobotOnMoonEasy {
    string isSafeCommand(vector <string> board, string S) {
		int n = board.size(), m = board[0].size();
		int sz = S.size();
		int y, x;
		REP(i,0,n){
			REP(j,0,m){
				if( board[i][j] == 'S' ){
					y = i, x = j; goto next_s;
				}
			}
		}		
		next_s :
		REP(i,0,sz){
			int dir = 0;
			if( S[i] == 'U') dir = 0;
			if( S[i] == 'D') dir = 2;
			if( S[i] == 'L') dir = 3;
			if( S[i] == 'R') dir = 1;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if( ny < 0 || ny >= n || nx < 0 || nx >= m) return "Dead";
			if( board[ny][nx] == '.')
				y = ny, x = nx;	
		}
		return "Alive";
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
			string board[]            = {".....",
 ".###.",
 "..S#.",
 "...#."};
			string S                  = "URURURURUR";
			string expected__         = "Alive";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".....",
 ".###.",
 "..S..",
 "...#."};
			string S                  = "URURURURUR";
			string expected__         = "Dead";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {".....",
 ".###.",
 "..S..",
 "...#."};
			string S                  = "URURU";
			string expected__         = "Alive";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"};
			string S                  = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
			string expected__         = "Alive";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"};
			string S                  = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
			string expected__         = "Dead";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"S"};
			string S                  = "R";
			string expected__         = "Dead";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			string S                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			string S                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			string S                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
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
// There is a robot on the moon.
You are given a vector <string> board containing the map of a rectangular area.
The robot is currently located somewhere in that area.
In the map, the character '.' (period) represents an empty square, 'S' represents an empty square that currently contains the robot, and '#' represents an obstacle.


You are also given a string S.
This string represents a sequence of commands we are going to send to the robot.
Each character in S is one of 'U', 'D', 'L', and 'R', representing a step up, down, left, and right, respectively.


Whenever the robot receives a command, one of three things will happen:

If the requested move leads to an empty square, the robot performs the move.
If the requested move leads to a square with an obstacle, the robot ignores the command and remains in place.
If the requested move leads out of the mapped area, the robot leaves the mapped area and dies immediately.



Given the map and the sequence of commands, compute whether the robot will survive.
Return "Alive" (quotes for clarity) if the robot is still somewhere on the map after the last command.
Otherwise, return "Dead".
Note that the return value is case-sensitive.

DEFINITION
Class:RobotOnMoonEasy
Method:isSafeCommand
Parameters:vector <string>, string
Returns:string
Method signature:string isSafeCommand(vector <string> board, string S)


NOTES
-The direction 'U' corresponds to moving from board[i][j] to board[i-1][j]. The direction 'L' corresponds to moving from board[i][j] to board[i][j-1].


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters.
-Each element of board will contain the same number of characters.
-The characters in board will be '.', '#' or 'S'.
-There will be exactly one 'S' in board.
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be one of 'U', 'D', 'L', 'R'.


EXAMPLES

0)
{".....",
 ".###.",
 "..S#.",
 "...#."}
"URURURURUR"

Returns: "Alive"

The robot will never move from its starting location: commands 'U' and 'R' are sending it into obstacles, so the robot ignores them.

1)
{".....",
 ".###.",
 "..S..",
 "...#."}
"URURURURUR"

Returns: "Dead"

This time there is no obstacle on the robot's right side. Its execution of commands will look as follows:

'U' leads into an obstacle. The robot ignores it.
'R' leads into an empty square. The robot makes a step to the right.
'U' leads into an obstacle. The robot ignores it.
'R' leads into an empty square. The robot makes a step to the right.
The next 'U' now leads into an empty square. The robot makes a step up. After this step, the robot is in row 1, column 4. (Both indices are 0-based.)
'R' leads out of the map. The robot steps out of the map and dies. The remaining four commands never get executed - the robot is already dead.


2)
{".....",
 ".###.",
 "..S..",
 "...#."}
"URURU"

Returns: "Alive"



3)
{"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}
"DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"

Returns: "Alive"

There are obstacles all around the map. Regardless of how the robot moves, it is safe - the obstacles will prevent it from leaving the map.

4)
{"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"}
"DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"

Returns: "Dead"

After some steps the robot will leave the map from the only empty square in the bottom row of the map.

5)
{"S"}
"R"

Returns: "Dead"



**/
// END CUT HERE

