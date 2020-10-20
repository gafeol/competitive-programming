#include "bits/stdc++.h"
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

bool one() {
    int sum = s[0] + s[1] + s[2] + s[3];
    for(int i=0;i<4;i++){
        if(sum - s[i] == s[i])
            return true;
    }
    return false;
}

bool two(){
    int sum = s[0] + s[1] + s[2] + s[3];
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(sum - s[i] - s[j] == s[i] + s[j])
                return true;
        }
    }
    return false;
}

bool three(){
    int sum = s[0] + s[1] + s[2] + s[3];
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            for(int k=j+1;k<4;k++){
                if(sum - s[i] - s[j] - s[k] == s[i] + s[j] + s[k])
                    return true;
            }
        }
    }
    return false;
}


int main (){
	for(int a=0;a<4;a++){
        scanf("%d", s+a);
	}
    if(one() || two() || three())
        puts("Yes");
    else
        puts("No");
}

