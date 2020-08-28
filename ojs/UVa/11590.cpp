#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int base = 1000000000;
const int base_digits = 9;

struct Int {
    vector<int> a;
    int sign;
    int size(){
        if(a.empty()) return 0;
        int ans=(a.size()-1)*base_digits;
        int ca=a.back();
        while(ca)
            ans++,ca/=10;
        return ans;
    }

    string to_string(){
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }

    Int() :
        sign(1) {
        }

    Int(long long v) {
        *this = v;
    }

    void operator=(const Int &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        a.clear();
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    Int operator+(const Int &v) const {
        if (sign == v.sign) {
            Int res = v;
            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    Int operator-(const Int &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                Int res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    Int operator*(int v) const {
        Int res = *this;
        res *= v;
        return res;
    }


    Int operator*(long long v) const {
        Int res = *this;
        res *= v;
        return res;
    }

    friend pair<Int, Int> divmod(const Int &a1, const Int &b1) {
        int norm = base / (b1.a.back() + 1);
        Int a = a1.abs() * norm;
        Int b = b1.abs() * norm;
        Int q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    Int operator/(const Int &v) const {
        return divmod(*this, v).first;
    }

    Int operator%(const Int &v) const {
        return divmod(*this, v).second;
    }

    Int operator/(int v) const {
        Int res = *this;
        res /= v;
        return res;
    }

    void operator+=(const Int &v) {
        *this = *this + v;
    }

    void operator-=(const Int &v) {
        *this = *this - v;
    }

    void operator*=(const Int &v) {
        *this = *this * v;
    }

    void operator/=(const Int &v) {
        *this = *this / v;
    }


    bool operator<(const Int &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const Int &v) const {
        return v < *this;
    }

    bool operator<=(const Int &v) const {
        return !(v < *this);
    }

    bool operator>=(const Int &v) const {
        return !(*this < v);
    }

    bool operator==(const Int &v) const {
        return !(*this < v) && !(v < *this);
    }

    bool operator!=(const Int &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    Int operator-() const {
        Int res = *this;
        res.sign = -sign;
        return res;
    }

    Int abs() const {
        Int res = *this;
        res.sign *= res.sign;
        return res;
    }


    friend ostream& operator<<(ostream &stream, const Int &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);

        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    Int operator*(const Int &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);

        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());

        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);

        vll c = karatsubaMultiply(a, b);
        Int res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};

const int K = 2;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    Int q;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t;

int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - '0';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

const int MAXN = 21234;

map<string, int> fim;

Int soma(int v, Int x){
    if(v == -1) return Int(0);
    if(v == 0 || t[v].leaf){
        t[v].q = Int(x);
        t[v].q -= soma(t[v].next[0], x/2);
        t[v].q -= soma(t[v].next[1], x/2);
        return x;
    }
    else{
        t[v].q = soma(t[v].next[0],x/2);
        t[v].q += soma(t[v].next[1],x/2);
        return t[v].q;
    }
}

int main (){
    int n, m, k;
    while(scanf("%d%d", &n, &k) != EOF && n + k > 0){
        t.clear();
        t.emplace_back();

        fim.clear();
        fim[""] = 0;
        for(int i=0;i<n;i++){
            char pal[MAXN];
            scanf(" %s", pal);
            int sz = strlen(pal);
            pal[sz-1] = '\0';
            assert(strlen(pal) == sz-1);
            fim[pal] = add_string(pal);
        }

        Int x = Int(1);
        while(k--){
            x *= 2ll;
        }
        soma(0, x);
        scanf("%d", &m);
        for(int a=0;a<m;a++){
            char pal[MAXN];
            scanf(" %s", pal);
            int sz = strlen(pal);
            pal[sz-1] = '\0';
            assert(strlen(pal) == sz-1);
            cout << t[fim[pal]].q;
            puts("");
        }
        puts("");
    }
}
