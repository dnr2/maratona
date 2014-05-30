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

bool cmp( string a, string b){
	return (a.size() < b.size());
}

struct TwoWaysSorting {
    string sortingMethod(vector <string> stringList) {
		vector<string> lex( stringList.begin(), stringList.end());
		vector<string> len( stringList.begin(), stringList.end());
		sort( lex.begin(), lex.end());
		sort( len.begin(), len.end(), cmp);
		if( lex == stringList && len == stringList) return "both";
		if( lex == stringList ) return "lexicographically";
		if( len == stringList) return "lengths";
        return "none";
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
			string stringList[]       = {"a", "aa", "bbb"};
			string expected__         = "both";

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string stringList[]       = {"c", "bb", "aaa"};
			string expected__         = "lengths";

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string stringList[]       = {"etdfgfh", "aio"};
			string expected__         = "none";

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string stringList[]       = {"aaa", "z"};
			string expected__         = "lexicographically";

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string stringList[]       = {"z"};
			string expected__         = "both";

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string stringList[]       = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"};
			string expected__         = "lexicographically";

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string stringList[]       = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string stringList[]       = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string stringList[]       = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TwoWaysSorting().sortingMethod(vector <string>(stringList, stringList + (sizeof stringList / sizeof stringList[0])));
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
	Sasha has a vector <string> stringList. No two elements of stringList have the same length.



	So far, Sasha has learned two ways of sorting strings:


	
		He can sort strings lexicographically. For example, "car" < "carriage" < "cats" < "doggies". (See Notes for a definition of the lexicographic order.)
	
	
		He can also sort strings according to their lengths in ascending order. For example, "car" < "cats" < "doggies" < "carriage".
	


	Sasha now wonders whether stringList is sorted in either of these two ways. Return "lexicographically" (quotes for clarity) if stringList is sorted lexicographically but not according to the string lengths. Return "lengths" if stringList is sorted according to the string lengths but not lexicographically. Return "both" if it is sorted in both ways. Otherwise, return "none".



DEFINITION
Class:TwoWaysSorting
Method:sortingMethod
Parameters:vector <string>
Returns:string
Method signature:string sortingMethod(vector <string> stringList)


NOTES
-String A is lexicographically smaller than string B if A contains a character with a smaller ASCII value in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.


CONSTRAINTS
-stringList will contain between 1 and 50 elements, inclusive.
-Each element of stringList will contain between 1 and 50 characters, inclusive.
-Each character of each element of stringList will be a lowercase English letter ('a'-'z').
-Every two elements of stringList will have different lengths.


EXAMPLES

0)
{"a", "aa", "bbb"}

Returns: "both"

These strings are sorted both lexicographically and according to their lengths.

1)
{"c", "bb", "aaa"}

Returns: "lengths"

The lengths of these strings are in ascending order. However, they are not sorted lexicographically as, for instance, "aaa" is lexicographically smaller than "c".

2)
{"etdfgfh", "aio"}

Returns: "none"

Here the first string is longer than the second one, so they are not sorted according to length. (Note that we require the lengths to be in ascending order.) Similarly, they are not sorted lexicographically: "aio" should come before "etdfgfh".

3)
{"aaa", "z"}

Returns: "lexicographically"

The input strings are sorted lexicographically only.

4)
{"z"}

Returns: "both"



5)
{"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}

Returns: "lexicographically"



**/
// END CUT HERE
