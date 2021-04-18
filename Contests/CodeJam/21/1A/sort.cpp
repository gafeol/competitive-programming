#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

int n, m, k;
string s[MAXN];

bool smaller(string &a, string &b){
    if(a.size() != b.size())
        return (a.size() < b.size());
    return a < b;
}

bool pref(string &a, string &b){
    if(a.size() > b.size())
        return false;
    return (a == (b.substr(0, a.size())));
}

bool hasNineSuffix(string &s, int from){
    for(int i=from;i<s.size();i++){
        if(s[i] != '9')
            return false;
    }
    return true;
}

void inc(string &s){
    int i = s.size()-1;
    while(s[i] == '9'){
        s[i] = '0';
        i--;
    }
    s[i]++;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            char pal[12];
            scanf(" %s", pal);
            s[a] = pal;
        }
        string curr = s[0];
        int res = 0;
        for(int i=1;i<n;i++){
            if(smaller(curr, s[i])){
                curr = s[i];
            }
            else if(pref(s[i], curr)){
                if(hasNineSuffix(curr, s[i].size())){
                    int dif = 1 + curr.size() - s[i].size();
                    curr = s[i];
                    while(dif--){
                        curr.push_back('0');
                        res++;
                    }
                }
                else{
                    res += curr.size() - s[i].size();
                    inc(curr);
                }
            }
            else{
                assert(s[i].size() <= curr.size());
                string aux = curr.substr(0, s[i].size());
                int dif = curr.size() - s[i].size() + smaller(s[i], aux);
                curr = s[i];
                while(dif--){
                    curr.push_back('0');
                    res++;
                }
            }
        }
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}

