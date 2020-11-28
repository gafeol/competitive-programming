#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

class OverallScores {
  public:
  int findWinner(int N, vector <int> scores) {
      vector<int> sums(N, 0);
      for(int a=0;a<scores.size();a++){
          sums[a%N] += scores[a];
      }
        int mx = *max_element(sums.begin(), sums.end());
        for(int a=0;a<N;a++){
            if(sums[a] == mx)
                return a;
        }
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
			int N                     = 2;
			int scores[]              = { 10, 20, 30, 40 };
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = OverallScores().findWinner(N, vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int scores[]              = { 1, 1, 1, 1 };
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = OverallScores().findWinner(N, vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int scores[]              = { 71, 23, 18, 15, 28, 93, 11, 12, 13 };
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = OverallScores().findWinner(N, vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int N                     = ;
			int scores[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OverallScores().findWinner(N, vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int N                     = ;
			int scores[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OverallScores().findWinner(N, vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int scores[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OverallScores().findWinner(N, vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
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
