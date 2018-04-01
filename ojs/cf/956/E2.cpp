
/**
 * This is a solution for problem wardrobe
 * This is nk_ok.cpp
 * 
 * @author: Nikolay Kalinin
 * @date: Tue, 20 Mar 2018 21:48:33 +0300
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

struct tbox
{
    int h, t;
};

inline bool operator<(const tbox &a, const tbox &b)
{
    if (a.t != b.t) return a.t < b.t;
    return a.h > b.h;
}

const int maxn = 10005;
const int inf = 1e9;

tbox b[maxn];
int ans[maxn];
int n, l, r;

int main()
{
    scanf("%d%d%d", &n, &l, &r);
    int sumh = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].h);
        sumh += b[i].h;
    }
	int auxl = l, auxr = r;
	l = sumh - auxr;
	r = sumh - auxl;
    for (int i = 0; i < n; i++) scanf("%d", &b[i].t);
    sort(b, b + n);
    for (int i = 0; i <= sumh; i++) ans[i] = -inf;
    ans[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int h = sumh - b[i].h; h >= 0; h--) ans[h + b[i].h] = max(ans[h + b[i].h], ans[h] + b[i].t * (h + b[i].h >= l && h + b[i].h <= r));
    }
    cout << *max_element(ans, ans + sumh + 1) << endl;
    return 0;
}
