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

class OneForYou {
  public:
  long long coinCount(long long N) {
      ll ans = 0;
      ll r = 1;
      while(N > 0){
          N--;
          ll aux = min(N, r);
          N -= aux;
          ans += aux;
          r++;
      }
      return ans;
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
			long long N               = 2;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = OneForYou().coinCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long N               = 9;
			long long expected__      = 6;

			std::clock_t start__      = std::clock();
			long long received__      = OneForYou().coinCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long N               = 11;
			long long expected__      = 7;

			std::clock_t start__      = std::clock();
			long long received__      = OneForYou().coinCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long N               = 33;
			long long expected__      = 26;

			std::clock_t start__      = std::clock();
			long long received__      = OneForYou().coinCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

                /*
      case 4: {
			long long N               = 1000000000000000LL;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = OneForYou().coinCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		} */
/*      case 5: {
			long long N               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = OneForYou().coinCount(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long N               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = OneForYou().coinCount(N);
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
