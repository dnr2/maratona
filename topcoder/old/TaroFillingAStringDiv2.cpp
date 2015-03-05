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

int pd[100][2];

struct TaroFillingAStringDiv2 {
    int getNumber(string S) {
		int resp = 0;
		int n = S.size();
		REP(i,0,n-1){
			if( S[i] != '?' && S[i] == S[i+1] ) resp++;
		}
		REP(i,0,n){
			if( S[i] == '?'){
				int b = i, e = i;
				while( e < n && S[e] == '?' ){
					e++;
				}
				i = e-1;
				if( b == 0 || e == n) continue;
				if( ((e - b) & 1) ){
					if( S[b-1] != S[e]){
						resp++;
					}
				} else {
					if( S[b-1] == S[e]){
						resp++;
					}
				}
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
			string S                  = "ABAA";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "??";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "A?A";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "A??B???AAB?A???A";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?";
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string S                  = "???";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			string S                  = "?A??";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
			string S                  = "A?ABAB??B";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
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
Cat Taro likes strings.
You are given a string S.
Each character of S is 'A', 'B', or '?'.




To Taro, the ugliness of a string is the number of pairs of equal consecutive characters.
For example, the ugliness of "ABABAABBB" is 3: there is one pair "AA" and two (overlapping) pairs "BB".




Taro now wants to change each question mark in S either to 'A' or to 'B'.
His goal is to minimize the ugliness of the resulting string.
Return the smallest ugliness that can be achieved.


DEFINITION
Class:TaroFillingAStringDiv2
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will consist only of characters 'A', 'B' and '?'.


EXAMPLES

0)
"ABAA"

Returns: 1

There is initially one pair of consecutive digits that are equal in this case. There is no characters that Taro has to replace, hence the answer is 1.

1)
"??"

Returns: 0



2)
"A?A"

Returns: 0



3)
"A??B???AAB?A???A"

Returns: 3



4)
"?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?"

Returns: 10



**/
// END CUT HERE
