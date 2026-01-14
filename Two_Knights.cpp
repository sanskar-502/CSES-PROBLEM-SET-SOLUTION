#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

#define len(x) int((x).size())
#define pb push_back

bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

void sanskar_502() {
    int n;
    cin>>n;

    for(int i=1; i<=n ; i++){
        if(i==1){
            cout<<0<<endl;
        }else{
            ll j= i*i;
            ll total_slab=  (j*(j-1))/2;
            ll attacking_poistion=  (i-1)*(i-2)*2*2;

            cout<<total_slab-attacking_poistion<<endl;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        sanskar_502();
}
