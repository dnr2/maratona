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

struct EasyConversionMachine {
    string isItPossible(string originalWord, string finalWord, int k) {
		int cont=0;
		REP(i,0,(int)originalWord.size()){
			if( originalWord[i] != finalWord[i]) cont++;
		}
		if( k < cont || ((cont - k) & 1) ) return "IMPOSSIBLE";
        return "POSSIBLE";
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
			string originalWord       = "aababba";
			string finalWord          = "bbbbbbb";
			int k                     = 2;
			string expected__         = "IMPOSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string originalWord       = "aabb";
			string finalWord          = "aabb";
			int k                     = 1;
			string expected__         = "IMPOSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string originalWord       = "aaaaabaa";
			string finalWord          = "bbbbbabb";
			int k                     = 8;
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string originalWord       = "aaa";
			string finalWord          = "bab";
			int k                     = 4;
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string originalWord       = "aababbabaa";
			string finalWord          = "abbbbaabab";
			int k                     = 9;
			string expected__         = "IMPOSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string originalWord       = ;
			string finalWord          = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string originalWord       = ;
			string finalWord          = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string originalWord       = ;
			string finalWord          = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
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
// We have a string originalWord. Each character of originalWord is either 'a' or 'b'. Timmy claims that he can convert it to finalWord using exactly k moves. In each move, he can either change a single 'a' to a 'b', or change a single 'b' to an 'a'.

You are given the strings originalWord and finalWord, and the int k. Determine whether Timmy may be telling the truth.
If there is a possible sequence of exactly k moves that will turn originalWord into finalWord, return "POSSIBLE" (quotes for clarity).
Otherwise, return "IMPOSSIBLE".

DEFINITION
Class:EasyConversionMachine
Method:isItPossible
Parameters:string, string, int
Returns:string
Method signature:string isItPossible(string originalWord, string finalWord, int k)


NOTES
-Timmy may change the same letter multiple times. Each time counts as a different move.


CONSTRAINTS
-originalWord will contain between 1 and 50 characters, inclusive.
-finalWord and originalWord will contain the same number of characters.
-Each character in originalWord and finalWord will be 'a' or 'b'.
-k will be between 1 and 100, inclusive.


EXAMPLES

0)
"aababba"
"bbbbbbb"
2

Returns: "IMPOSSIBLE"

It is not possible to reach finalWord in fewer than 4 moves.

1)
"aabb"
"aabb"
1

Returns: "IMPOSSIBLE"

The number of moves must be exactly k=1.

2)
"aaaaabaa"
"bbbbbabb"
8

Returns: "POSSIBLE"

Use each move to change each of the letters once.

3)
"aaa"
"bab"
4

Returns: "POSSIBLE"

The following sequence of 4 moves does the job:
aaa -> baa -> bab -> aab -> bab

4)
"aababbabaa"
"abbbbaabab"
9

Returns: "IMPOSSIBLE"



**/
// END CUT HERE
