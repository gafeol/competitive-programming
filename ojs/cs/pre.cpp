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

const int MAXN = 1123456;

int n, m, k, ff[MAXN];
char s[MAXN], nd[MAXN];

ll res;

bool men(int tam){
	if(tam < 2*tt){
		for(int a=0;a<tt;a++){
			nd[a+tam-tt] = nd[a];
		}
		tt = tam;
		int men = 1;
		for(int a=0;a<tt;a++){
			if(s[a] > nd[a]){
				break;
			}
			else if(s[a] < nd[a]){
				men = 0;
				break;
			}
		}
		return men;
	}
	if(tam >= 2*tt){
		int men = 1;
		for(int a=0;a<tt;a++){
			if(s[a] > nd[a]){
				men = 2;
				break;
			}
			else if(s[a] < nd[a]){
				men = 0;
				break;
			}	
		}
		int men2 = 1;
		for(int a=0;a<tt;a++){
			if(s[a] > nd[t-tt+a]){
				men = 2;
				break;
			}
			else if(s[a] < nd[t-tt+a]){
				men = 0;
				break;
			}	
		}	
		if(men == 2){
			for(int cnt = 0;cnt < t - 2*tt;cnt++){
				res = mod(res*10 + 10);
			}
		}
		else 
		ll ans = 0;
		for(int i=0;i<t;i++){
			
		}
	}
}

int main (){
	scanf(" %s", s);
	scanf(" %s", nd);
	int t = strlen(s), tt = strlen(nd);
	int l = 0;
	for(l = 0;l < tt-1;l++){
		if(nd[l] != nd[tt-l-1])
			break;
	}
	res = 0;
	for(int i=tt+1;i<=tt+l;i++){
		if(i < t)
			res++;
		else if(i == t && men(i))
			res++;
		else
			break;
	}
	for(int 
	//MODDD
}
