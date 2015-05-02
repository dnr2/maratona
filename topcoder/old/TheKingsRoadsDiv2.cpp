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
#define PB push_back 


#define FT first 
#define SD second 
#define PII pair<int,int> 
#define MP make_pair 

const int maxn = 4000; 
int dep[maxn];

struct TheKingsRoadsDiv2 {
    string getAnswer(int h, vector <int> a, vector <int> b) {
        int n = a.size(); 
		REP(rm,0,n){
			REP(root,0,n){
				queue<PII> fila;
				memset( dep, 0, sizeof( dep ));
				dep[root] = 1;
				while( !fila.empty()){
					int v = fila.front().FT, int pai = fila.front().SD;
					REP(i,0,n){
						
					}
				}
				
			}
		}
		return "Incorrect";
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
			int h                     = 3;
			int a[]                   = {1, 2, 3, 7, 1, 5, 4};
			int b[]                   = {6, 7, 4, 3, 3, 1, 7};
			string expected__         = "Correct";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int h                     = 2;
			int a[]                   = {1, 2, 3};
			int b[]                   = {2, 1, 3};
			string expected__         = "Incorrect";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int h                     = 3;
			int a[]                   = {7, 1, 1, 2, 2, 3, 1};
			int b[]                   = {7, 1, 7, 4, 5, 2, 6};
			string expected__         = "Incorrect";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int h                     = 2;
			int a[]                   = {1, 3, 3};
			int b[]                   = {2, 1, 2};
			string expected__         = "Correct";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int h                     = 3;
			int a[]                   = {6, 5, 3, 3, 5, 5, 6};
			int b[]                   = {1, 5, 5, 6, 4, 7, 2};
			string expected__         = "Correct";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int h                     = 3;
			int a[]                   = {4, 7, 7, 1, 1, 1, 4};
			int b[]                   = {6, 5, 1, 7, 4, 3, 2};
			string expected__         = "Incorrect";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int h                     = 3 ;
			int a[]                   = {1, 1, 1, 1, 1, 1, 6};
			int b[]                   = {2, 3, 4, 5, 6, 7, 7};
			string expected__         = "Incorrect";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int h                     = ;
			int a[]                   = ;
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
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
You live in the Kingdom of Byteland.
The kingdom has a very interesting history.
It has already existed for h years.
During the first year of its existence the inhabitants built the first city.
During each of the next h-1 years the following procces occurred:
For each city built in the previous year, two additional cities were built and the older city was connected to each the two new cities by a bidirecional road.
Now, after h full years, the kingdom contains exactly (2^h)-1 cities and (2^h)-2 roads.




Recently the King did two changes to the kingdom.
First, he numbered the cities from 1 to (2^h)-1 in an arbitrary way.
Then, he added exactly one new road to the kingdom.
(The road could have connected two cities that were already connected by a different road.
Also, it is possible that the new road connected some city to itself.)




You are given the int h and two vector <int>s a and b with (2^h)-1 elements each.
For each valid i, there is a road between the cities a[i] and b[i].




Return "Correct" if it is possible that the given list of roads is the current road network in the Kingdom of Byteland.
Otherwise, return "Incorrect".


DEFINITION
Class:TheKingsRoadsDiv2
Method:getAnswer
Parameters:int, vector <int>, vector <int>
Returns:string
Method signature:string getAnswer(int h, vector <int> a, vector <int> b)


CONSTRAINTS
-h will be between 2 and 10, inclusive.
-a and b will contain exactly (2^h)-1 elements each.
-Each element of a and b will be between 1 and (2^h)-1, inclusive.


EXAMPLES

0)
3
{1, 2, 3, 7, 1, 5, 4}
{6, 7, 4, 3, 3, 1, 7}

Returns: "Correct"

City 3 was built during the first year, cities 1 and 7 during the second year, and the other four cities during the third year.
Then the King added the road 3-4.

1)
2
{1, 2, 3}
{2, 1, 3}

Returns: "Incorrect"



2)
3
{7, 1, 1, 2, 2, 3, 1}
{7, 1, 7, 4, 5, 2, 6}

Returns: "Incorrect"



3)
2
{1, 3, 3}
{2, 1, 2}

Returns: "Correct"



4)
3
{6, 5, 3, 3, 5, 5, 6}
{1, 5, 5, 6, 4, 7, 2}

Returns: "Correct"

Here the road added by the King is obviously the self-loop from city 5 to itself.

**/
// END CUT HERE
