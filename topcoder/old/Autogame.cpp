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

struct Autogame {
    int wayscnt(vector <int> a, int K) {
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
			int a[]                   = {1,2,3};
			int K                     = 5;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = Autogame().wayscnt(vector <int>(a, a + (sizeof a / sizeof a[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {1,1,1};
			int K                     = 1;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = Autogame().wayscnt(vector <int>(a, a + (sizeof a / sizeof a[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {2,1} ;
			int K                     = 42;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = Autogame().wayscnt(vector <int>(a, a + (sizeof a / sizeof a[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {2,3,4,3};
			int K                     = 3;
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = Autogame().wayscnt(vector <int>(a, a + (sizeof a / sizeof a[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {4,4,3,2,1};
			int K                     = 3;
			int expected__            = 18;

			std::clock_t start__      = std::clock();
			int received__            = Autogame().wayscnt(vector <int>(a, a + (sizeof a / sizeof a[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Autogame().wayscnt(vector <int>(a, a + (sizeof a / sizeof a[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Autogame().wayscnt(vector <int>(a, a + (sizeof a / sizeof a[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Autogame().wayscnt(vector <int>(a, a + (sizeof a / sizeof a[0])), K);
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
// Hero is playing a game with tokens.
There are N places for tokens.
The places are numbered 1 through N.
There are also N arrows, each pointing from some place to some place.
No two arrows start at the same place.
It is possible that multiple arrows point to the same place.
Also, an arrow may start and end at the same place.

You are given the description of the game board: a vector <int> a with N elements.
For each i between 1 and N, inclusive, the arrow that starts at the place i points to the place a[i-1].

At the beginning of the game, Hero will take an arbitrary number of tokens between 0 and N, inclusive, and he will place them onto distinct places.
He will then play K rounds of the game.
In each round each token moves from its current place along the arrow to the new place.
After each round, Hero checks whether all tokens are still in distinct places.
If two or more tokens are in the same place, Hero loses the game.
Hero wins the game if he does not lose it during the K rounds he plays.

There may be multiple ways how Hero can win the game.
Two ways are different if there is some i such that at the beginning of the game place i did contain a token in one case but not in the other.
Count those ways and return their count modulo 1,000,000,007.


DEFINITION
Class:Autogame
Method:wayscnt
Parameters:vector <int>, int
Returns:int
Method signature:int wayscnt(vector <int> a, int K)


CONSTRAINTS
-a will contain exactly N elements.
-N will be between 1 and 50, inclusive.
-Each element in a will be between 1 and N, inclusive.
-K will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,3}
5

Returns: 8

There are 2^3 = 8 valid ways to place the tokens. In each round each token will stay in the same place. Hence, Hero will win the game for each initial placement of tokens.

1)
{1,1,1}
1

Returns: 4

If Hero starts the game with two or three tokens, after the first round there will be multiple tokens in the same place (place 1) and Hero will lose the game. He will only win the game if he starts with 0 tokens (1 possibility) or with 1 token (3 possibilities).

2)
{2,1}	
42

Returns: 4



3)
{2,3,4,3}
3

Returns: 9



4)
{4,4,3,2,1}
3

Returns: 18



**/
// END CUT HERE
