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
char s[MAXN], ss[MAXN];

bool cmp(char c1, char c2){
    return c1 > c2;
}

int main (){
    for_tests(t, tt){
        scanf(" %s", s);
        scanf(" %s", ss);
        sort(s, s+strlen(s), cmp);
        sort(ss, ss+strlen(ss), cmp);
        bool eq = true;
        printf("Data set #%d: ", tt);
        for(int i=0;i<min(strlen(s), strlen(ss));i++){
            if(s[i] == ss[i]) continue;    
            if(s[i] < ss[i])
                puts("First is younger");
            else
                puts("First is older");
            eq = false;
            break;
        }
        if(eq){
            if(strlen(s) < strlen(ss))
                puts("First is younger");
            else if(strlen(s) > strlen(ss))
                puts("First is older");
            else
                puts("Same age");
        }
    }
}

