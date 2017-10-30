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

map<string, int> ind;

int main (){
	scanf("%d\n", &n);
	int res = 0;
	for(int a=0;a<n;a++){
		string s;
		char c;
		int cnt = 0;
		while((c = getchar()) != EOF){
			if(c == '\n') break;
			if(c == 'k'){
				cnt++;
			}
			else{
				if(c == 'h')
					cnt = 0;
				while(cnt--)
					s += 'k';
				if(c == 'u'){
					s += 'o';
					s += 'o';
				}
				else
					s += c;
			}
		}
		cout << "ns "+s << endl;
		if(ind.find(s) == ind.end()){
			ind[s] = 1;
			res++;
		}
	}
	printf("%d\n", res);
}

