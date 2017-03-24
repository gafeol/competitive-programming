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

const int MAXN = 235;

int n, m, k;
char inp[MAXN];
int s[MAXN];
string st, res[MAXN];

char nm[5];

string next(string str){
	int j = str.size()-1;
	while(str[j] == 'z'){
		str[j] = 'a';
		j--;
	}
	char c = str[j];
	c++;
	str[j] = c;
	return str;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<=n-k;a++){
		scanf(" %s", inp);
		if(inp[0] == 'Y')
			s[a] = 1;
		else
			s[a] = 0;
	}
	st = "Zaaaa";
	for(int a=0;a<=n-k;a++){
		if(s[a]){
			for(int b=a;b<a+k;b++){
				if(res[b].size() == 0 ){
					res[b] = st;
					st = next(st);
				}
			}
		}
	}
	for(int a=0;a<=n-k;a++){
		if(res[a].size() == 0){
			for(int b= 1+a;b<a+k;b++){
				if(!(res[b].size() == 0)){
					res[a] = res[b];
					break;
				}
			}
			if(res[a].size() == 0){
				res[a] = "A";
				for(int b=a+1;b<a+k;b++){
					if(res[b].size() == 0){
						res[b] = res[a];
						break;
					}
				}
			}
		}
	}
	for(int a=n-k+1;a<n;a++){
		if(res[a].size() == 0){
			for(int b=max(a-k+1, 0);b<a+k;b++){
				if(!(res[b].size() == 0)){
					res[a] = res[b];
					break;
				}
			}
			if(res[a].size() == 0){
				res[a] = "A";
				for(int b=a+1;b<a+k;b++){
					if(res[b].size() == 0){
						res[b] = res[a];
						break;
					}
				}
			}
		}
	}
	for(int a=0;a<n;a++){
		cout << res[a] << " ";
	}
	cout << endl;
}

