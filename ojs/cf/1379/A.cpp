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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
char s[MAXN];
string res = "abacaba";

bool ok(){
    int cnt = 0;
    for(int a=0;a<=n-res.size();a++){
        bool eq = true;
        for(int i=0;i<res.size();i++)
            if(s[a+i] != res[i])
                eq = false;
        cnt += eq; 
    }
    return (cnt == 1);
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        scanf(" %s", s);
        int cnt = 0;
        int pos = 0;
        for(int a=0;a<=n-res.size();a++){
            bool eq = true;
            for(int i=0;i<res.size();i++)
                if(s[a+i] != res[i])
                    eq = false;
            cnt += eq; 
            //printf("testando em a %d %d\n", a, eq);
            eq = true;
            for(int i=0;i<res.size();i++)
                if(s[a+i] != '?' && s[a+i] != res[i])
                    eq = false;
            pos += eq;
        }
        //printf("Cnt %d pos %d\n", cnt, pos);
        if((cnt == 0 && pos >= 1) || cnt == 1){
            if(cnt == 1){
                puts("Yes");
                for(int a=0;a<n;a++){
                    if(s[a] == '?')
                        s[a] = 'z';
                }
                printf("%s\n", s);
            }
            else{
                bool deu = false;
                for(int a=0;a<=n-res.size();a++){
                    bool eq = true;
                    for(int i=0;i<res.size();i++)
                        if(s[a+i] != '?' && s[a+i] != res[i])
                            eq = false;
                    if(eq){
                        string ori = s;
                        for(int i=0;i<res.size();i++){
                            s[a+i] = res[i]; 
                        }
                        for(int a=0;a<n;a++){
                            if(s[a] == '?')
                                s[a] = 'z';
                        }
                        //printf("tstando %s\n", s);
                        if(ok()){
                            deu = true;
                            puts("Yes");
                            printf("%s\n", s);
                            break;
                        }
                        for(int i=0;i<ori.size();i++){
                            s[i] = ori[i];
                        }
                    }
                }
                if(!deu)
                    puts("No");
            }
        }
        else
            puts("No");

    }
}

