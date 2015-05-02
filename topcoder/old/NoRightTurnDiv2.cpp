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
#define VI vector<int>
#define co double

struct pu {
	co x,y;
	pu(co a=0, co b=0) {x=a;y=b;}
};
pu operator-(const pu &a, const pu &b) {
	return pu(a.x-b.x,a.y-b.y);
}
// Not always necessary!
bool operator==(const pu &a, const pu &b) {
	return a.x == b.x && a.y == b.y;
}
pu operator*(co a, const pu &b) {
	return pu(a*b.x, a*b.y);
}
///orientation
co kr(const pu &a, const pu &b) { // z component of the cross product $a\times b$
	return a.x*b.y-b.x*a.y;
}
co kr(const pu &a, const pu &b, const pu &c) { // z component of the cross product $(b-a)\times (c-a)$
	return kr(b-a,c-a);
}
// Intersection of the (infinite) lines $a_1a_2$ and $b_1b_2$ (if they aren't parallel).
// You obviously have to use floating point numbers, here!
pu inter(const pu &a1, const pu &a2, const pu &b1, const pu &b2) {
	return (1/kr(a1-a2,b1-b2))*(kr(a1,a2)*(b1-b2) - kr(b1,b2)*(a1-a2));
}

struct NoRightTurnDiv2 {
    vector <int> findPath(vector <int> x, vector <int> y) {
		VI ret;
		int n = x.size();
		vector< pair< pu,pu > > segs;
		VI used;
		vector< pair< double, int > > angs;
		REP(ii,0,n){
			REP(jj,0,n){
				if( ii == jj ) continue;
				segs.clear();
				used.clear();
				REP(kk,0,n) used.PB( -1 ); 
				pu ant = pu(x[ii],y[ii]) , cur = pu( x[jj],y[jj]);
				segs.PB( MP( ant,cur));
				used[ii] = 0; used[jj] = 1;
				bool ok = true;
				REP(pos,1,n){
					angs.clear();
					double best = 100; int bpos = 0;
					REP(i,0,n){
						if( used[i] == -1){
							double ang = kr( cur - ant, pu( x[i], y[i]) - cur );
							if( ang > 0 && best > ang ){
								best = ang; bpos = i;
							}
						}
					}
					used[bpos] = pos + 1;
					ant = cur;
					cur = pu( x[bpos], y[bpos]);
					REP(i,0,(int)segs.size()){
						if( intersects( segs[i].FT, segs[i].SD, cur, ant ){
							ok = false; goto aqui;
						}
					}
					segs.PB( MP( ant, cur ));
				}
				aqui : 
				if( ok ){
					REP(i,0,n){
						REP(j,0,n){
							if( used[j] == i){
								ret.PB( j );
							}
						}
					}
					return ret;
				}
			}
		}		
        return vector<int>();
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int x[]                   = {-10, 0, 10};
			int y[]                   = {10, -10, 10};
			int expected__[]          = {0, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,0,-3,-3,3,3};
			int y[]                   = {-1,1,-3,3,-3,3};
			int expected__[]          = {0, 4, 5, 3, 2, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {10,9,8,7,6,5,4,3,2,1};
			int y[]                   = {1,4,9,16,25,36,49,64,81,100};
			int expected__[]          = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {0, 2,-2, 4,-4, 2,-2, 0};
			int y[]                   = {1, 2, 2, 4, 4, 6, 6, 5};
			int expected__[]          = {4, 2, 0, 1, 3, 5, 6, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {-76,98,83,58,-15,94,21,55,80,84,-39,-90,-46,100,-80,-49,-2,-70,36,48,88,10, 55,-56,22,67,31,81,100,-39,64,-62,-7,45,-82,-24,51,-33,53,11,20,-74,-83,47, 9,39,42,63,-97,94};
			int y[]                   = {-90,68,91,-92,-6,88,99,10,39,-69,-61,-4,71,-5,90,-51,21,-53,-21,-86,41,-9, 42,-23,-4,12,94,-59,55,18,70,-88,-86,-17,-97,-33,87,80,91,-80,-79,-79,-78, -99,57,67,-52,-46,61,-10};
			int expected__[]          = {39, 32, 40, 31, 19, 27, 47, 46, 0, 34, 43, 3, 9, 13, 28, 1, 5, 2, 6, 14, 48, 42, 41, 49, 20, 38, 26, 37, 12, 11, 17, 10, 33, 25, 8, 30, 36, 44, 29, 23, 15, 18, 7, 22, 45, 16, 4, 35, 24, 21 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
Roger the Robot has been sent to explore a planet. 
The surface of the planet can be thought of as a two-dimensional plane. 
You are given two vector <int>s x and y.
The planet has N interesting points described by these vector <int>s.
The i-th interesting point has coordinates (x[i], y[i]).
No three interesting points will be collinear.



Roger will choose a permutation of {0,1,...,N-1}, and will visit the points in that order.
Roger will travel in a straight line in between points. There are two conditions he must follow:

He must never cross his own path (that is, if we look at the line segments formed by the path, no two segments strictly intersect). 
 Due to rather unfortunate oversight, Roger is incapable of making any right turns. This means that for any three consecutive points that he visits, these three points constitute a counter-clockwise orientation. 




Your job is to find a path that Roger can take.
If there is no valid path, return an empty vector <int>.
Otherwise, return an vector <int> containing a permutation of 0,...,N-1, representing a valid path that Roger can take.




DEFINITION
Class:NoRightTurnDiv2
Method:findPath
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> findPath(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 2 and 50 elements, inclusive.
-y will contain exactly the same number of elements as x.
-Each element of x,y will be between -1,000 and 1,000, inclusive.
-All pairs (x[i], y[i]) will be distinct.
-No three points will be collinear.


EXAMPLES

0)
{-10, 0, 10}
{10, -10, 10}

Returns: {0, 1, 2 }

The points form a triangle.
Any of the following return values will be accepted: {0,1,2},{1,2,0},{2,0,1}

1)
{0,0,-3,-3,3,3}
{-1,1,-3,3,-3,3}

Returns: {0, 4, 5, 3, 2, 1 }


Here is a picture of the points:







Here is an example of a different valid solution. This would correspond to a return value of {1,5,3,2,4,0}






2)
{10,9,8,7,6,5,4,3,2,1}
{1,4,9,16,25,36,49,64,81,100}

Returns: {9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }



3)
{0, 2,-2, 4,-4, 2,-2, 0}
{1, 2, 2, 4, 4, 6, 6, 5}

Returns: {4, 2, 0, 1, 3, 5, 6, 7 }



4)
{-76,98,83,58,-15,94,21,55,80,84,-39,-90,-46,100,-80,-49,-2,-70,36,48,88,10,
55,-56,22,67,31,81,100,-39,64,-62,-7,45,-82,-24,51,-33,53,11,20,-74,-83,47,
9,39,42,63,-97,94}
{-90,68,91,-92,-6,88,99,10,39,-69,-61,-4,71,-5,90,-51,21,-53,-21,-86,41,-9,
42,-23,-4,12,94,-59,55,18,70,-88,-86,-17,-97,-33,87,80,91,-80,-79,-79,-78,
-99,57,67,-52,-46,61,-10}

Returns: {39, 32, 40, 31, 19, 27, 47, 46, 0, 34, 43, 3, 9, 13, 28, 1, 5, 2, 6, 14, 48, 42, 41, 49, 20, 38, 26, 37, 12, 11, 17, 10, 33, 25, 8, 30, 36, 44, 29, 23, 15, 18, 7, 22, 45, 16, 4, 35, 24, 21 }



**/
// END CUT HERE
