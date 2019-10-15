
// extended euclid
ll gcd(ll a, ll b, ll &x, ll &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}


bool join(ll &a, ll &n, ll b, ll m){ // joins two clauses
    // finds positive res such that res%n = a and res%m = b
    ll x, y;
    ll gc = gcd(n, m, x, y);
    if((a - b)%gc != 0 || (n == m && a != b))
        return false; // no solution

    ll lcm = (n/gc)*m;
    ll res = (a + x * (b - a)/gc % (m / gc) * n) % lcm; 
    res = (res + lcm)%lcm; // get a positive solution

    // preparing for the next step
    a = res;
    n = lcm;
    return true;
}

void normalize(vector<ll> &val, vector<ll> &md){
    for(int i=0;i<val.size();i++)
        val[i] = (val[i]%md[i] + md[i])%md[i];
}

ll crt(vector<ll> &val, vector<ll> &md){
    normalize(val, md);

    ll lval = val[0], lmd = md[0];
    for(int i=1;i<val.size();i++){
        if(!join(lval, lmd, val[i], md[i]))
            return -1; // failed!
    }
    return lval;
}


int main (){
    ll res = crt(val, md);
    if(res == -1) // no solution
        fail();
}


