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

map<int,ll> dp;
vector<string> rs;
vector<string> cs;
int off[] = {1,3,3*3,3*3*50,3*3*50*50,3*3*50*50*50};

ll rec( int y, int x, int r, vector<int> c){
	if( y > 2){
		bool ok = true;
		REP(i,0,3) if( (int)cs[i].size() > c[i]) ok = false;
		if( ok == true) return 1;
		else return 0;
	}
	if( x > 2 ){
		if( r >= (int)rs[y].size() ) return rec( y+1, 0 , 0, c);
		else return 0;
	}
	int idx = y*off[0] + x*off[1] + r*off[2] + c[0]*off[3] + c[1]*off[4] + c[2]*off[5];
	if( dp[idx] > 0) return dp[idx]-1;			
	ll ret = rec( y, x+1, r, c);
	while( r < (int)rs[y].size() && c[x] < (int)cs[x].size() && rs[y][r] == cs[x][c[x]]){
		r++; c[x]++;
		ret += rec( y, x + 1, r, c);
	}
	dp[idx] = ret +1;
	return ret;
}

struct MagicalSquare {
	
    long long getCount(vector <string> rowStrings, vector <string> columnStrings) {
		rs = rowStrings; cs = columnStrings;
		dp.clear();
		vector<int> c; REP(i,0,3) c.push_back(0);
        return rec( 0, 0, 0 , c);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			string rowStrings[]       = {"f", "o", "x"}
;
			string columnStrings[]    = {"f", "o", "x"}
;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string rowStrings[]       = {"x", "x", "x"};
			string columnStrings[]    = {"x", "", "xx"};
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string rowStrings[]       = {"cd", "cd", "cd"};
			string columnStrings[]    = {"dvd", "dvd", "dvd"};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string rowStrings[]       = {"abab", "ab", "abab"};
			string columnStrings[]    = {"abab", "ab", "abab"};
			long long expected__      = 11;

			std::clock_t start__      = std::clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string rowStrings[]       = {"qwer", "asdf", "zxcv"};
			string columnStrings[]    = {"qaz", "wsx", "erdfcv"};
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

		case 5: {
			string rowStrings[]       = {"xx", "xx", "xx"};
			string columnStrings[]    = {"xx", "xx", "xxx"};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string rowStrings[]       = ;
			string columnStrings[]    = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string rowStrings[]       = ;
			string columnStrings[]    = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
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
// You are going to fill 9 strings into the cells of a 3x3 square. Rows of the square are numbered 0 to 2 from top to bottom, and columns of the square are numbered 0 to 2 from left to right. Let S[i][j] be the string you'll enter into the cell in row i, column j. The strings S[i][j] do not have to be distinct. It is also allowed to use empty strings.

You are given two vector <string>s rowStrings and columnStrings. For each i, the concatenation of strings in row i must be equal to rowStrings[i]. The same must hold for columns and columnStrings. Formally, the strings in the cells must satisfy the following conditions:

For all 0<=i<=2, S[i][0]+S[i][1]+S[i][2] = rowStrings[i].
For all 0<=j<=2, S[0][j]+S[1][j]+S[2][j] = columnStrings[j].

Here, '+' represents a string concatenation.

Return the number of ways in which the strings S[i][j] can be chosen so that all conditions are satisfied.

DEFINITION
Class:MagicalSquare
Method:getCount
Parameters:vector <string>, vector <string>
Returns:long long
Method signature:long long getCount(vector <string> rowStrings, vector <string> columnStrings)


CONSTRAINTS
-rowStrings and columnStrings will each contain exactly 3 elements.
-Each element of rowStrings will contain between 0 and 50 characters, inclusive.
-Each element of columnStrings will contain between 0 and 50 characters, inclusive.
-rowStrings and columnStrings will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
{"f", "o", "x"}

{"f", "o", "x"}


Returns: 1

The only valid way to choose the strings:

 --- --- ---
| f |   |   |
 --- --- ---
|   | o |   |
 --- --- ---
|   |   | x |
 --- --- ---

That is, S[0][0]="f", S[1][1]="o", S[2][2]="x", and all other S[i][j] are empty.

1)
{"x", "x", "x"}
{"x", "", "xx"}

Returns: 3

These are the three valid possibilities:

 --- --- ---    --- --- ---    --- --- ---
| x |   |   |  |   |   | x |  |   |   | x |
 --- --- ---    --- --- ---    --- --- ---
|   |   | x |  | x |   |   |  |   |   | x |
 --- --- ---    --- --- ---    --- --- ---
|   |   | x |  |   |   | x |  | x |   |   |
 --- --- ---    --- --- ---    --- --- ---


2)
{"cd", "cd", "cd"}
{"dvd", "dvd", "dvd"}

Returns: 0

In this case there is no way to satisfy all conditions.

3)
{"abab", "ab", "abab"}
{"abab", "ab", "abab"}

Returns: 11



4)
{"qwer", "asdf", "zxcv"}
{"qaz", "wsx", "erdfcv"}

Returns: 1



**/
// END CUT HERE
