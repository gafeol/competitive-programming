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

map<char, int> cnt;

int ans[10];
vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


void rmv(int n){
    ans[n]++;
    string s = v[n];
    for(char c: s){
        cnt[c]--;
    }
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        char c;
        scanf(" %c", &c);
        cnt[c]++;
	}

    while(cnt['z'] > 0)
        rmv(0);
    while(cnt['w'] > 0)
        rmv(2);
    while(cnt['x'] > 0)
        rmv(6);
    while(cnt['g'] > 0)
        rmv(8);
    while(cnt['u'] > 0)
        rmv(4);
    while(cnt['f'] > 0)
        rmv(5);
    while(cnt['o'] > 0)
        rmv(1);
    while(cnt['i'] > 0)
        rmv(9);
    while(cnt['h'] > 0)
        rmv(3);
    while(cnt['v'] > 0)
        rmv(7);

    for(int n = 9;n>=0;n--){
        while(ans[n]--){
            cout << n << " ";
        }
    }
    cout << endl;
}

