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

const int MAXN = 61;

int n, m, k;
char nm[MAXN], v[MAXN];

stack<int> s[MAXN];

string nam[] = {"Dee", "Dum"};

int main (){
	for_tests(t, tt){
		scanf("%d %s", &n, nm);
		for(int a=0;a<n;a++){
			while(!s[a].empty())
				s[a].pop();
		}
		int j = (strcmp(nm, "Dee") != 0);
		int cnt =0;
		for(int i=0;i<n;i++){
			scanf(" %s", v);
			int tam = strlen(v);
			for(int a=tam-1;a>=0;a--){
				s[i].push((v[a]=='1'));
				cnt++;
			}
		}
		int ok = 1;
		while(ok){
			ok = 0;
			for(int a=0;a<n;a++){
				if(s[a].empty()) continue;
				if(s[a].top() == j){
					ok = 1;
					s[a].pop();
					cnt--;
					while(!s[a].empty() && s[a].top() == 1-j){
						s[a].pop();
						cnt--;
					}
					break;
				}
			}
			j = 1 - j;
		}
		cout << nam[j] << endl;
	}
}

