#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
 
const int MAXN = 20;
 
int n, m, k;
char num[MAXN];
int s[MAXN];
 
//     >
int sz1, sz2;
int f1, f2;
 
int s1[MAXN], s2[MAXN];
 
ll goeq(int i, bool carry = false){ 
    if(i == n)
        return !carry;
    if(i < f1 && carry)
        return 0;
    ll ans = 0;
    if(s1[i] != -1){ // ja foi definido
        if(carry){
            if((s1[i] + s2[i])%10 == s[i] && s1[i] + s2[i] >= 10)
                ans += goeq(i+1, false);
            if((s1[i] + s2[i] +1)%10 == s[i] && s1[i] + s2[i] + 1 >= 10)
                ans += goeq(i+1, true);
        }
        else{
            if((s1[i] + s2[i])%10 == s[i] && s1[i] + s2[i] < 10)
                ans += goeq(i+1, false);
            if((s1[i] + s2[i] +1)%10 == s[i] && s1[i] + s2[i] + 1 < 10)
                ans += goeq(i+1, true);
        }
    }
    else{ // s1 nao ta definido
        if(i < f1){ // nao tem s1 ainda nem s2
            if(!carry && s[i] == 1)
                ans += goeq(i+1, true);
        }
        else{ // tem s1 mas nao definido
            int j1 = n - 1 - (i - f1);
            int j2 = n - 1 - (i - f2);
            for(int comcarry=0;comcarry<=1;comcarry++){
                for(int d1=0+(i == f1);d1<=9;d1++){
                    for(int d2=0+(i == f2);d2<=d1;d2++){
                        int sum = (d1 + d2 + comcarry)%10;
                        int c = (d1 + d2 + comcarry > 9);
                        if(carry != c || s[i] != sum) continue;

                        s1[i] = s1[j1] = d1;
                        s2[i] = s2[j2] = d2;
                        bool chama = false;
                        assert(s1[j2] != -1);
                        if((s1[j2] + s2[j2])%10 == s[j2] || (s1[j2] + s2[j2] + 1)%10 == s[j2])
                            chama = true;
                        if(chama)
                            ans += (d1 != d2 ? 2ll*goeq(i+1, comcarry) : goeq(i+1, comcarry));
                        s1[i] = s1[j1] = -1;
                        s2[i] = s2[j2] = -1;
                    }
                }
            }
        }
    }
    return ans;
}
 
ll go(int i, bool carry = false){ 
    if(i == n)
        return !carry;
    ll ans = 0;
    if(s1[i] != -1){ // ja foi definido
        if(s2[i] != -1){ // tb ja ta definido
            if(carry){
                if((s1[i] + s2[i])%10 == s[i] && s1[i] + s2[i] >= 10)
                    ans += go(i+1, false);
                if((s1[i] + s2[i] +1)%10 == s[i] && s1[i] + s2[i] + 1 >= 10)
                    ans += go(i+1, true);
            }
            else{
                if((s1[i] + s2[i])%10 == s[i] && s1[i] + s2[i] < 10)
                    ans += go(i+1, false);
                if((s1[i] + s2[i] +1)%10 == s[i] && s1[i] + s2[i] + 1 < 10)
                    ans += go(i+1, true);
            }
        }
        else{ // s2 nao foi definido
            if(i >= f2){
                int j = n - 1 - (i - f2); // deve valer que s2[i] == s2[j]
                if(carry){
                    // sem carry do prox
                    int val = 10 + s[i] - s1[i];
                    if(val < 10 && ((i > f2 && val >= 0) || (i == f2 && val > 0))){ // sem leading z
                        s2[i] = s2[j] = val;
                        ans += go(i+1, false);
                        s2[i] = s2[j] = -1;
                    }
                    // com carry do prox
                    val = 10 + s[i] - s1[i] - 1;
                    if(val < 10 && ((i > f2 && val >= 0) || (i == f2 && val > 0))){ // sem leading z
                        s2[i] = s2[j] = val;
                        ans += go(i+1, true);
                        s2[i] = s2[j] = -1;
                    }
                }
                else{
                    int val = s[i] - s1[i];
                    if(val < 10 && ((i > f2 && val >= 0) || (i == f2 && val > 0))){ // sem leading z
                        s2[i] = s2[j] = val;
                        ans += go(i+1, false);
                        s2[i] = s2[j] = -1;
                    }
                    // com carry do prox
                    val = s[i] - s1[i] - 1;
                    if(val < 10 && ((i > f2 && val >= 0) || (i == f2 && val > 0))){ // sem leading z
                        s2[i] = s2[j] = val;
                        ans += go(i+1, true);
                        s2[i] = s2[j] = -1;
                    }
                }
            }
            else{ // s1 definido, mas ainda nao tem s2
                if(carry){
                    if(s1[i] == 10 + s[i])
                        ans += go(i+1, false);
                    if(s1[i] + 1 == 10 + s[i])
                        ans += go(i+1, true);
                }
                else{
                    if(s1[i] == s[i])
                        ans += go(i+1, false);
                    if(s1[i] + 1 == s[i])
                        ans += go(i+1, true);
                }
            }
        }
    }
    else{ // s1 nao ta definido
        if(i < f1){ // nao tem s1 ainda nem s2
            if(!carry && s[i] == 1){
                //printf("sz1 %d f1 %d sz2 %d f2 %d i %d carry s %d chama go(i+1, true)\n", sz1, f1, sz2, f2, i, carry, s[i]);
                ans += go(i+1, true);
            }
        }
        else{ // tem s1 mas nao definido
            int j1 = n - 1 - (i - f1);
            //printf("i %d j1 %d f2  %d carry %d s[i] %d\n", i, j1, f2, carry, s[i]);
            if(i < f2){ // nao tem s2
                if(carry && s[i] > 0) // s1 sozinho nao da carry - EROU - tem que ser 9 com carry do proximo
                    return 0;
                if(carry){
                    s1[i] = s1[j1] = 9;
                    //printf("bota 9 em %d go(%d, true)\n", i, i+1);
                    ans += go(i+1, true); 
                    //printf("ans %lld\n", ans);
                    s1[i] = s1[j1] = -1;
                }
                else{
                    s1[i] = s1[j1] = s[i];
                    ans += go(i+1, false);
                    s1[i] = s1[j1] = -1;
                    if(s[i] > 1  || (s[i] == 1 && i > f1)){
                        s1[i] = s1[j1] = s[i]-1;
                        ans += go(i+1, true);
                        s1[i] = s1[j1] = -1;
                    }
                }
           }
            else{ // tem s1 e s2 nenhum definido
                int j2 = n-1 - (i - f2);
                for(int comcarry=0;comcarry<=1;comcarry++){
                    for(int d1=0+(i == f1);d1<=9;d1++){
                        for(int d2=0+(i == f2);d2<=9;d2++){
                            int sum = (d1 + d2 + comcarry)%10;
                            int c = (d1 + d2 + comcarry > 9);
                            if(carry != c || s[i] != sum) continue;
                            s1[i] = s1[j1] = d1;
                            s2[i] = s2[j2] = d2;
                            bool chama = false;
                            assert(s1[j2] != -1);
                            if((s1[j2] + s2[j2])%10 == s[j2] || (s1[j2] + s2[j2] + 1)%10 == s[j2])
                                chama = true;
                            if(chama)
                                ans += go(i+1, comcarry);
                            s1[i] = s1[j1] = -1;
                            s2[i] = s2[j2] = -1;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
 
int main (){
    scanf(" %s", num);
    n = strlen(num);
    for(int a=0;a<n;a++)
        s[a] = num[a]-'0';
    ll ans = 0;
    memset(s1, -1, sizeof(s1));
    memset(s2, -1, sizeof(s2));
    for(int sz=1;sz<=n;sz++){
        for(int szz=1;szz<sz;szz++){
            sz1 = sz;
            f1 = n - sz1;
            sz2 = szz;
            f2 = n - sz2;
            ll res = go(0);
            ans += 2*res;
        }
    }
    for(int sz=1;sz<=n;sz++){
        sz1 = sz;
        f1 = n - sz1;
        sz2 = sz;
        f2 = n - sz2;
        ans += goeq(0);
    }
    printf("%lld\n", ans);
}
