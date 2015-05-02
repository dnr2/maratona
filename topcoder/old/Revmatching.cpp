#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define PII pair<int,int>
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

struct Revmatching {
    int smallest(vector <string> A) {
        return int(0);
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
			string A[]                = {"1"};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string A[]                = {"0"};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string A[]                = {"44","44"};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string A[]                = {"861","870","245"};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string A[]                = {"01000","30200","11102","10001","11001"};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string A[]                = {"0111101100","0001101001","1001001000","1000100001","0110011111","0011110100","1000001100","0001100000","1000100001","0101110010"};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string A[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string A[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string A[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Revmatching().smallest(vector <string>(A, A + (sizeof A / sizeof A[0])));
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
// You have a weighted bipartite graph.
Each partition contains n vertices numbered 0 through n-1.
You are given the weights of all edges encoded into a vector <string> A with n elements, each containing n characters.
For each i and j, A[i][j] is '0' if there is no edge between vertex i in the first partition and vertex j in the second partition.
Otherwise, A[i][j] is between '1' and '9', inclusive, and the digit represents the weight of the corresponding edge.

A perfect matching is a permutation p of 0 through n-1 such that for each i there is an edge (of any positive weight) between vertex i in the first partition and vertex p[i] in the second partition.

Your goal is to have a graph that does not contain any perfect matching.
You are allowed to delete edges from your current graph.
You do not care about the number of edges you delete, only about their weights.
More precisely, you want to reach your goal by deleting a subset of edges with the smallest possible total weight.
Compute and return the total weight of deleted edges in an optimal solution.

DEFINITION
Class:Revmatching
Method:smallest
Parameters:vector <string>
Returns:int
Method signature:int smallest(vector <string> A)


CONSTRAINTS
-A will contain exactly n elements.
-Each element in A will be n characters long.
-n will be between 1 and 20, inclusive.
-Each character in A will be between '0' and '9', inclusive.


EXAMPLES

0)
{"1"}

Returns: 1

There is a single edge. You have to delete it.

1)
{"0"}

Returns: 0

There are no edges and therefore there is no perfect matching.

2)
{"44","44"}

Returns: 8



3)
{"861","870","245"}

Returns: 6



4)
{"01000","30200","11102","10001","11001"}

Returns: 0



5)
{"0111101100","0001101001","1001001000","1000100001","0110011111","0011110100","1000001100","0001100000","1000100001","0101110010"}

Returns: 1



**/
// END CUT HERE
