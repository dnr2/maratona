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
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))

const int maxn = 210;
int pd[maxn];
int n;
vector<int> arr;

int rec( int pos ){	
	if( pos >= n ) return 1;
	if( pd[pos] != -1) return pd[pos];
	
	int ret = 0;
	REP(i,1,n+1){
		bool ok = true;
		if( pos + i > n) break;
		REP(j,pos,pos+i){
			if( arr[j] != i && arr[j] != 0 ) ok = false;
		}		
		if( ok ) {
			int r = rec( pos + i );
			ret += r;
		}
	}
	return pd[pos] = min( ret, 2);
}

struct CountryGroupHard {
    string solve(vector <int> a) {
		n = a.size();
		FILL(pd, -1);
		arr = a;
        return (rec( 0 ) ==  1)?"Sufficient": "Insufficient";
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
			int a[]                   = {0,2,3,0,0};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {0,2,0};
			string expected__         = "Insufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {0,3,0,0,3,0};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {0,0,3,3,0,0};
			string expected__         = "Insufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {2,2,0,2,2};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int a[]                   = {0,0,0};
			string expected__         = "Insufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int a[]                   = {0};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int a[]                   = {0,3,0};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 8: {
			int a[]                   = {
										0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										};
			string expected__         = "Insufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 9: {
			int a[]                   = {
										0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,100,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										,0,0,0,0,0,0,0,0,0,0
										};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		
		case 10: {
			int a[]                   = {10, 0, 0, 0, 10, 10, 0, 0, 10, 10, 10, 0, 10, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 10, 0, 0, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 10, 0, 10, 0, 10, 0, 0, 0, 10, 10, 10, 0, 10, 10, 10, 0, 0, 10, 10, 0, 10, 0, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 10, 10, 0, 10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 10, 10, 0, 10, 10, 10, 0, 10, 10, 0};
			string expected__         = "Insufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
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
Some people are sitting in a row.
Each person came here from some country.
People from the same country are all sitting together.



A reporter has already approached some of the people and asked each of them the same question:
"How many people from your country (including you) are here?"
All the people who were asked the question gave her correct answers.



You are given a vector <int> a.
The elements of a correspond to the people in the row, in order.
For each i, element i of a is either 0 if the corresponding person was not asked the question, or a positive integer: the answer given by that person.



The reporter just realized that she might be able to reconstruct all the missing answers from the answers she already knows.
Return "Sufficient" if she can do that, or "Insufficient" if she cannot.


DEFINITION
Class:CountryGroupHard
Method:solve
Parameters:vector <int>
Returns:string
Method signature:string solve(vector <int> a)


CONSTRAINTS
-The number of elements in a will be between 1 and 100, inclusive.
-All numbers of a will be between 0 and 100, inclusive.
-There exist valid country assignment of people for input.


EXAMPLES

0)
{0,2,3,0,0}

Returns: "Sufficient"

The first two people must be from the same country. The last three people must also be from the same country. Thus, the only possible sequence of answers is {2,2,3,3,3}.

1)
{0,2,0}

Returns: "Insufficient"

There are still two different sequences of answers that are consistent with the reporter's information: the answers can be either {1,2,2} or {2,2,1}.

2)
{0,3,0,0,3,0}

Returns: "Sufficient"



3)
{0,0,3,3,0,0}

Returns: "Insufficient"



4)
{2,2,0,2,2}

Returns: "Sufficient"



**/
// END CUT HERE
