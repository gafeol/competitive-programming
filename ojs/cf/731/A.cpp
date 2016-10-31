#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
char s[MAXN];

int cus(char a, char b){
	if(a > b)
		swap(a, b);
	return min(b - a,  27 - (b - a + 1));
}

int main (){
	scanf(" %s", s);
	n = strlen(s);
	int res = 0;
	char ult = 'a';
	for(int a=0;a<n;a++){
		res += cus(ult, s[a]);
		ult = s[a];

	}
	printf("%d\n", res);

}
