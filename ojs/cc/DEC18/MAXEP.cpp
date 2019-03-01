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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int lst;

void fix(){
	printf("2\n");
	fflush(stdout);
}

int check(int ult){
	if(lst)
		fix();

	printf("1 %d\n", ult);
	fflush(stdout);

	scanf("%d", &lst);
	return lst;
}

int main (){
	scanf("%d%d", &n, &k);
	int ult = 1;
	while(ult + 300 <= n){
		ult += 300;
		if(check(ult)){
			ult -= 300;
			break;
		}
	}

	while(ult <= n && !check(ult++));

	printf("3 %d\n", ult-1);
	fflush(stdout);
}

