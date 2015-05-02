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

struct ValueOfString {
    int findValue(string s) {
		int ret = 0;
		REP(i,0,(int)s.size()){
			int aux = 0;
			REP(j,0,(int)s.size()){
				if( s[j] <= s[i] ) aux++;
			}
			ret += aux * (s[i] - 'a' + 1);
			
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
			string s                  = "babca";
			int expected__            = 35;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "zz";
			int expected__            = 104;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "y";
			int expected__            = 25;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "aaabbc";
			int expected__            = 47;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "topcoder";
			int expected__            = 558;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string s                  = "thequickbrownfoxjumpsoverthelazydog";
			int expected__            = 11187;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string s                  = "zyxwvutsrqponmlkjihgfedcba";
			int expected__            = 6201;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ValueOfString().findValue(s);
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
You are given a string s consisting of lower case letters.
We assign the letters 'a' to 'z' values of 1 to 26, respectively.
We will denote the value assigned to the letter X by val[X].
For example, val['a'] = 1 and val['e'] = 5.



We define the value of the string s as follows.
For each letter s[i], let k[i] be the number of letters in s that are less than or equal to s[i], including s[i] itself.
Then, the value of s is defined to be the sum of k[i] * val[s[i]] for all valid i.



Given the string, compute and return the value of the string.


DEFINITION
Class:ValueOfString
Method:findValue
Parameters:string
Returns:int
Method signature:int findValue(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-s will consist of lowercase letters ('a'-'z').


EXAMPLES

0)
"babca"

Returns: 35


The value of this string is 2*4 + 1*2 + 2*4 + 3*5 + 1*2 = 35.



We can get the value as follows. The first character is a 'b' which has value 2, and has 4 characters that are less than or equal to it in the string (i.e. the first, second, third and fifth character of the string). Thus, this first character contributes 2*4 to the sum. We can derive a similar expression for each of the other characters. 


1)
"zz"

Returns: 104



2)
"y"

Returns: 25



3)
"aaabbc"

Returns: 47



4)
"topcoder"

Returns: 558



5)
"thequickbrownfoxjumpsoverthelazydog"

Returns: 11187



6)
"zyxwvutsrqponmlkjihgfedcba"

Returns: 6201



**/
// END CUT HERE
