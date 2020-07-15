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
const ll modn = 997;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 1005;

vector<int> pri = {2, 3, 5, 7, 11, 13, 17, 19, 23};
vector<int> id(30);
vector<int> cnt = {0, 0, 0, 0,  0,  0,  0,  0,  0};
vector<ll> magic = {9857, 9859, 9871, 9883, 9887, 9901, 9907, 9923, 9929};

int n, m, k;
char s[MAXN];

int prv[40];


int dp[500][MAXN];
void add(int x){
    while(x > 1){
        cnt[id[prv[x]]]++;
        x /= prv[x];
    }
}

void rmv(int x){
    while(x > 1){
        cnt[id[prv[x]]]--;
        x /= prv[x];
    }
}

void addf(int x){
    while(x > 1){
        add(x);
        x--;
    }
}

void rmvf(int x){
    while(x > 1){
        rmv(x);
        x--;
    }
}

int h(){
    ll ans = 0; 
    for(int a=0;a<cnt.size();a++){
        ans = mod(ans + magic[a]*cnt[a]);  
    }
    return ans;
}

bool valid(){
    int ult = INT_MAX;
    for(int x: cnt){
        if(x < 0 || ult < x)
            return false;
        ult = x;
    }
    return true;
}


vector<char> ans;
bool go(int i, int hsh){
    /*printf("go %d hsh %d\n", i, hsh);
    for(int x: cnt){
        printf("%d ", x);
    }
    puts("");*/
    int &r = dp[i][hsh];
    if(r != -1)
        return r;
    r = false;
    if(*max_element(cnt.begin(), cnt.end()) == 0)
        return r = true;
    for(int ch=2;ch<=28;ch++){
        rmvf(ch);     
        if(!valid()){
            addf(ch);
            return r = false;
        }
        if(go(i+1, h())){
            ans.pb('a'+ch-2);
            addf(ch);
            return r = true;
        }
        addf(ch);
    }
    return r = false;
}


int main (){
    prv[1] = 1;
    for(int a=2;a<30;a++){
        if(prv[a]) continue;
        prv[a] = a;
        for(int b=a;a*b<30;b++){
            prv[a*b] = a;
        }
    }
    for(int a=0;a<pri.size();a++){
        id[pri[a]] = a;
    }
    random_shuffle(magic.begin(), magic.end());
    for_tests(t,tt){
        memset(dp, -1, sizeof(dp));
        scanf(" %s", s);
        n = strlen(s);
        for(int i=0;i<n;i++){
            char c = s[i];
            addf(c-'a'+2);
        }
        if(go(0, h())){
            reverse(ans.begin(), ans.end());
            bool eq = (ans.size() == n);
            if(eq){
                for(int a=0;a<n;a++){
                    if(s[a] != ans[a]){
                        eq = false;
                        break;
                    }
                }
            }
            printf("Case %d: ", tt);
            if(eq)
                puts("Impossible");
            else{
                for(char c: ans){
                    printf("%c", c);
                }
                puts("");
            }
        }
        else{
            puts("no go");
        }
    }
}

