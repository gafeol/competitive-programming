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

const int MAXN = 510*1001;

int n, m, k;
char s[MAXN];

int main (){
	scanf(" %s", s);
	int val = 0;
	n = strlen(s);
	int num = 0; 
	int sum = 0;
	for(int a=0;a<n;a++){
		if(s[a] == ','){
			sum += val;
			val = 0;
			num++;
		}
		else{
			val *= 10;
			val += (s[a]-'0');
		}
	}
	sum += val;
	num++;
	int res = sum/num;
	double med = ((double)sum)/((double)num) + 0.50000001;
	res = (int)med; 
	printf("%d\n", res);
}

