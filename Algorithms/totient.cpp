typedef long long ll;
ll euler_totient(ll x){
    if(x == 1) return 1;
    ll phi = x;
    vector<ll> pri;
    ll lim = sqrt(x) + 1e-8;
    vector<int> mrk(lim+1, 0);
    for(ll i=2;i<=lim;i++){
        if(mrk[i]) continue;
        pri.pb(i);
        for(ll j=i;j*i <= lim;j++)
            mrk[j*i] = 1;
    }

    vector<ll> xprimes;
    for(int i=0;i<pri.size();i++){
        if(x % pri[i] == 0)
            xprimes.pb(pri[i]);
        while(x % pri[i] == 0)
            x /= pri[i];
    }
    if(x > 1)
        xprimes.pb(x);

    for(ll pri: xprimes){
        phi = (phi/pri)*(pri - 1);
    }
    return phi;
}
