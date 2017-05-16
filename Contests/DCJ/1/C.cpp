#include"todd_and_steven.h"
#include<message.h>
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


const int MAXN = 2123456;
int main (){
	ll id = MyNodeId();
	if(!id){
		ll i = 0, j= 0;
		ll res =0;
		ll n = GetToddLength();
		ll m = GetStevenLength();
		ll t, s;
		t = s = -1;
		while(i < n && j < m){
			if(t == -1)
				t = GetToddValue(i);
			if(s == -1)
				s = GetStevenValue(j);
			if(t < s){
				res = mod(res + (t^(i + j)));
				i++;
				t = -1;
			}
			else{
				res = mod(res + (s^(i + j)));
				s = -1;
				j++;
			}
		}
		while(i < n){
			res = mod(res + (GetToddValue(i)^(i + j)));
			i++;
		}
		while(j < m){
			res = mod(res + (GetStevenValue(j)^(i + j)));
			j++;
		}
		printf("%lld\n", res);
	}
}
