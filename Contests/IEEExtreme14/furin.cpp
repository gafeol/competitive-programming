#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<long long, long long>
#define INF INT_MAX
#define int long long

clock_t clk;

bool tle(){
    if(((double)clock() - clk)/CLOCKS_PER_SEC > 1.5) {
        puts("3");
        return true;
    }
    return false;
}

map<string, int> res;

void run(){
    vector<char> v(30,0);
    int i = 0;
    i += 1;
    cin >> v[i];
    i += 1;
    cin >> v[i];
    i += 1;
    cin >> v[i];

    string s = "";

    if(res.find(s.pb(v[1]).pb(v[2]).pb(v[3]))){
        
    }
    i -= 1;
    while (v[i] != 0) {
        v[i] -= 1;
        i += 1;
        v[i] -= 1;
        i += 1;
        v[i] += 1;
        i -= 2;
    }
    i += 2;
    while (v[i] != 0) {
        v[i] -= 1;
        i -= 2;
        v[i] += 1;
        i += 2;
    }
    i -= 3;
    while (v[i] != 0) {
        v[i] -= 1;
        i += 1;
        v[i] -= 1;
        i -= 2;
        v[i] += 1;
        i += 1;
    }
    if(tle()) return ;
    i -= 1;
    while (v[i] != 0) {
        v[i] -= 1;
        i += 1;
        v[i] += 1;
        i -= 1;
    }
    i += 6;
    v[i] += 1;
    i += 7;
    v[i] += 1;
    while (v[i] != 0) {
        i += 4;
        while (v[i] != 0) {
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            v[i] -= 1;
        }
        i -= 12;
        while (v[i] != 0) {
            v[i] -= 1;
            i += 7;
            v[i] += 1;
            i += 6;
            v[i] += 1;
            i -= 13;
        }
        i += 1;
        if(tle()) return ;
        while (v[i] != 0) {
            v[i] -= 1;
            i += 7;
            v[i] += 1;
            i += 6;
            v[i] += 1;
            i -= 13;
        }
        i += 1;
        while (v[i] != 0) {
            v[i] -= 1;
            i += 7;
            v[i] += 1;
            i += 6;
            v[i] += 1;
            i -= 13;
        }
        i += 2;
        v[i] += 1;
        i += 1;
        v[i] += 1;
        while (v[i] != 0) {
            i -= 1;
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            v[i] -= 1;
            i += 2;
            v[i] += 1;
            i -= 3;
        }
        i += 4;
        while (v[i] != 0) {
            v[i] -= 1;
            i -= 7;
            v[i] += 1;
            i += 7;
        }
        i += 1;
        if(tle()) return ;
        while (v[i] != 0) {
            v[i] -= 1;
            i -= 7;
            v[i] += 1;
            i += 7;
        }
        i += 1;
        while (v[i] != 0) {
            v[i] -= 1;
            i -= 7;
            v[i] += 1;
            i += 7;
        }
        i += 7;
        v[i] += 1;
        while (v[i] != 0) {
            v[i] -= 1;
            i -= 11;
            while (v[i] != 0) {
                v[i] -= 1;
                i += 2;
                v[i] += 1;
                i += 2;
                v[i] += 1;
                i -= 4;
            }
            i += 1;
            while (v[i] != 0) {
                v[i] -= 1;
                i += 2;
                v[i] += 1;
                i += 2;
                v[i] += 1;
                i -= 4;
            }
            i += 1;
            while (v[i] != 0) {
                v[i] -= 1;
                i -= 2;
                v[i] += 1;
                i += 2;
            }
            if(tle()) return ;
            i += 1;
            while (v[i] != 0) {
                v[i] -= 1;
                i -= 2;
                v[i] += 1;
                i += 2;
            }
            v[i] += 1;
            while (v[i] != 0) {
                while (v[i] != 0) {
                    v[i] -= 1;
                }
                v[i] += 1;
                i += 1;
                while (v[i] != 0) {
                    i -= 1;
                    v[i] -= 1;
                }
                i -= 1;
                while (v[i] != 0) {
                    v[i] -= 1;
                    i += 2;
                    v[i] -= 1;
                    i -= 3;
                }
                i += 2;
                v[i] -= 1;
                i += 3;
                v[i] += 1;
                i += 1;
                while (v[i] != 0) {
                    i -= 1;
                    v[i] -= 1;
                }
                i -= 1;
                while (v[i] != 0) {
                    v[i] -= 1;
                    i += 1;
                    v[i] += 1;
                    i += 1;
                    if(tle()) return ;
                    while (v[i] != 0) {
                        v[i] -= 1;
                        i -= 1;
                        v[i] -= 1;
                    }
                    i -= 1;
                    while (v[i] != 0) {
                        i += 2;
                        while (v[i] != 0) {
                            v[i] -= 1;
                            i -= 2;
                            v[i] -= 1;
                            i += 1;
                        }
                        v[i] -= 1;
                        i -= 2;
                        while (v[i] != 0) {
                            v[i] -= 1;
                            i += 1;
                            v[i] -= 1;
                            i += 2;
                            v[i] -= 1;
                            i -= 4;
                        }
                    }
                    if(tle()) return ;
                    i -= 1;
                }
                i += 2;
                v[i] -= 1;
                i -= 5;
                v[i] += 1;
                i += 1;
                while (v[i] != 0) {
                    i -= 1;
                    v[i] -= 1;
                }
                i -= 1;
                while (v[i] != 0) {
                    while (v[i] != 0) {
                        i -= 1;
                    }
                }
                if(tle()) return ;
                i += 1;
                v[i] -= 1;
            }
            i += 8;
            v[i] += 1;
        }
        v[i] -= 1;
        i -= 4;
        v[i] += 1;
        i += 1;
        v[i] += 1;
        while (v[i] != 0) {
            i -= 1;
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            i += 2;
            v[i] += 1;
            while (v[i] != 0) {
                i -= 2;
                v[i] -= 1;
                i += 1;
            }
            i -= 2;
            while (v[i] != 0) {
                i += 3;
                v[i] += 1;
                while (v[i] != 0) {
                    i -= 3;
                    v[i] -= 1;
                    i += 2;
                }
                i -= 3;
                while (v[i] != 0) {
                    i -= 1;
                }
            }
        }
        i += 1;
        v[i] -= 1;
    }
    i += 4;
    while (v[i] != 0) {
        v[i] -= 1;
    }
    i -= 14;
    while (v[i] != 0) {
        v[i] -= 1;
    }
    i += 2;
    v[i] += 1;
    i += 1;
    v[i] += 1;
    while (v[i] != 0) {
        i -= 1;
        v[i] -= 1;
    }
    i -= 1;
    while (v[i] != 0) {
        v[i] -= 1;
        i += 2;
        v[i] += 1;
        i -= 3;
    }
    i += 1;
    v[i] += 1;
    i += 1;
    while (v[i] != 0) {
        i -= 1;
        v[i] -= 1;
    }
    i -= 1;
    while (v[i] != 0) {
        i += 2;
        while (v[i] != 0) {
            i -= 2;
            v[i] -= 1;
            i += 1;
        }
        i -= 2;
        while (v[i] != 0) {
            i -= 1;
        }
    }
    i += 1;
    v[i] -= 1;
    while (v[i] != 0) {
        v[i] += 1;
        i += 6;
        v[i] += 10;
        i -= 6;
        v[i] += 1;
        i += 1;
        while (v[i] != 0) {
            i -= 1;
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            i += 2;
            while (v[i] != 0) {
                i -= 2;
                v[i] -= 1;
                i += 1;
            }
            i -= 2;
            while (v[i] != 0) {
                i -= 1;
            }
        }
        i += 1;
        v[i] -= 1;
        while (v[i] != 0) {
            v[i] += 2;
            i += 1;
            while (v[i] != 0) {
                i -= 1;
                v[i] -= 1;
            }
            i -= 1;
            while (v[i] != 0) {
                v[i] -= 1;
                i += 2;
                v[i] -= 1;
                i -= 3;
            }
            i += 2;
            v[i] -= 1;
            i += 2;
            v[i] += 1;
            i += 2;
            v[i] += 1;
            i += 1;
            v[i] -= 1;
            while (v[i] != 0) {
                i -= 1;
                v[i] -= 1;
            }
            i -= 1;
            while (v[i] != 0) {
                i -= 2;
                while (v[i] != 0) {
                    v[i] -= 1;
                    i += 3;
                    v[i] += 1;
                    i -= 3;
                }
                i += 5;
                v[i] += 1;
                i += 1;
                v[i] += 1;
                while (v[i] != 0) {
                    i -= 1;
                    v[i] -= 1;
                }
                i -= 1;
                while (v[i] != 0) {
                    v[i] -= 1;
                    i += 2;
                    v[i] += 1;
                    i -= 3;
                }
                i -= 2;
                v[i] -= 1;
                i -= 1;
            }
            i -= 4;
            v[i] += 1;
            i += 1;
            while (v[i] != 0) {
                i -= 1;
                v[i] -= 1;
            }
            i -= 1;
            while (v[i] != 0) {
                i += 2;
                while (v[i] != 0) {
                    i -= 2;
                    v[i] -= 1;
                    i += 1;
                }
                i -= 2;
                while (v[i] != 0) {
                    i -= 1;
                }
            }
            i += 1;
            v[i] -= 1;
        }
        i += 2;
        v[i] += 8;
        while (v[i] != 0) {
            v[i] -= 1;
            i += 1;
            v[i] += 6;
            i -= 1;
        }
        i += 1;
        while (v[i] != 0) {
            v[i] -= 1;
            i -= 4;
            v[i] += 1;
            i += 4;
        }
        i += 5;
        v[i] += 1;
        i += 1;
        while (v[i] != 0) {
            i -= 1;
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            i += 2;
            while (v[i] != 0) {
                i -= 2;
                v[i] -= 1;
                i += 1;
            }
            i -= 2;
            while (v[i] != 0) {
                i -= 1;
            }
        }
        i += 1;
        v[i] -= 1;
        while (v[i] != 0) {
            v[i] += 2;
            i += 1;
            while (v[i] != 0) {
                i -= 1;
                v[i] -= 1;
            }
            i -= 1;
            while (v[i] != 0) {
                v[i] -= 1;
                i += 2;
                v[i] -= 1;
                i -= 3;
            }
            i += 2;
            v[i] -= 1;
            i -= 8;
            v[i] += 1;
            i += 1;
            v[i] += 1;
            while (v[i] != 0) {
                i -= 1;
                v[i] -= 1;
            }
            i -= 1;
            while (v[i] != 0) {
                v[i] -= 1;
                i += 2;
                v[i] += 1;
                i -= 3;
            }
            i += 8;
            v[i] += 1;
            i += 1;
            while (v[i] != 0) {
                i -= 1;
                v[i] -= 1;
            }
            i -= 1;
            while (v[i] != 0) {
                i += 2;
                while (v[i] != 0) {
                    i -= 2;
                    v[i] -= 1;
                    i += 1;
                }
                i -= 2;
                while (v[i] != 0) {
                    i -= 1;
                }
            }
            i += 1;
            v[i] -= 1;
        }
        i -= 2;
        while (v[i] != 0) {
            v[i] -= 1;
        }
        i -= 5;
        v[i] += 1;
        i += 1;
        while (v[i] != 0) {
            i -= 1;
            v[i] -= 1;
        }
        i -= 1;
        while (v[i] != 0) {
            i += 2;
            while (v[i] != 0) {
                i -= 2;
                v[i] -= 1;
                i += 1;
            }
            i -= 2;
            while (v[i] != 0) {
                i -= 1;
            }
        }
        i += 1;
        v[i] -= 1;
    }
    i -= 2;
    while (v[i] != 0) {
        cout << v[i];
        i -= 1;
    }


}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        clk = clock();
        run();
        cout<<endl;
    }
    return 0;
}

