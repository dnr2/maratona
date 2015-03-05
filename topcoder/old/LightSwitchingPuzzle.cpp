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

struct LightSwitchingPuzzle {
    int minFlips(string state) {
		map<int,bool> m;
		int sz = state.size();		
		REP(i,0,sz){
			int cont = 0;
			REP(j,1,i+1){
				if( (i+1) % j == 0 && m.count(j) ){
					cont++;
				}
			}
			if( ((state[i] == 'Y') && (cont & 1) == 0) ||
				((state[i] == 'N') && (cont & 1) == 1)	){
				m[i+1] = true;
			}
		}
        return (int) m.size();
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
			string state              = "YYYYYY";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = LightSwitchingPuzzle().minFlips(state);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string state              = "YNYNYNYNY";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = LightSwitchingPuzzle().minFlips(state);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string state              = "NNNNNNNNNN";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = LightSwitchingPuzzle().minFlips(state);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string state              = "YYYNYYYNYYYNYYNYYYYN";
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = LightSwitchingPuzzle().minFlips(state);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string state              = "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY";
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = LightSwitchingPuzzle().minFlips(state);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string state              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LightSwitchingPuzzle().minFlips(state);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string state              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LightSwitchingPuzzle().minFlips(state);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string state              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LightSwitchingPuzzle().minFlips(state);
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
Leo has N lights in a row.
The lights are numbered 1 through N.
Each light is either on or off.



Leo wants to turn all the lights off.
He has N switches he may use.
The switches are also numbered 1 through N.
For each i, switch number i toggles the state of all lights whose numbers are multiples of i.
(For example, switch 3 will toggle the state of light 3, light 6, light 9, and so on.)



You are given the current state of all lights as a string state with N characters.
For each valid i, state[i] is either 'Y' (meaning that light i+1 is currently on) or 'N' (meaning that the light is off).
Determine the smallest number of switches Leo needs to press in order to turn off all the lights.
If there is no way to turn off all the lights, return -1 instead.


DEFINITION
Class:LightSwitchingPuzzle
Method:minFlips
Parameters:string
Returns:int
Method signature:int minFlips(string state)


CONSTRAINTS
-state will contain between 1 and 1000 characters, inclusive.
-Each character of state will be either 'Y' or 'N'.


EXAMPLES

0)
"YYYYYY"

Returns: 1

We can turn off all the lights by pressing switch 1.

1)
"YNYNYNYNY"

Returns: 2


We cannot turn these lights off in a single step.
It can be done in two steps.
One possible solution looks as follows:
First, press the second switch.
This will toggle lights with numbers 2, 4, 6, and 8.
The state of the lights after this change will be "YYYYYYYYY".
Next, press the first switch to toggle all lightbulbs.


2)
"NNNNNNNNNN"

Returns: 0

All the lights are already off. 

3)
"YYYNYYYNYYYNYYNYYYYN"

Returns: 4



4)
"NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY"

Returns: 12



**/
// END CUT HERE
