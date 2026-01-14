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
#define all(x) (x).begin(), (x).end()

#define len(x) int((x).size())
#define pb push_back

bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

/* Result and Observations


*/



void sanskar_502() {
    ll n;
    cin>>n;

    ll sum= n*(n+1)/2;

    if(odd(sum)){
        cout<<"NO"<<endl;
        return;
    }

    ll temp_sum=0;

    for(int i=1; i<=n; i++){
        temp_sum += i;
        if(temp_sum == sum/2){
            cout<<"YES"<<endl;

            cout<<i<<endl;
            for(int j=1 ; j<=i ; j++){
                cout<<j<<sp;
            }
            cout<<endl<<n-i<<endl;
            for(int j=i+1; j<=n; j++){
                cout<<j<<sp;
            }
            cout<<endl;
            return;

        }else if( temp_sum > sum/2){
            int skip= temp_sum - sum/2;
            cout<<"YES"<<endl;

            cout<<i-1<<endl;

            for(int j=1 ; j<=i ; j++){
                if(j== skip) continue;
                cout<<j<<sp;
            }

            cout<<endl<<n-i+1<<endl;
            cout<<skip<<sp;

            for(int j=i+1; j<=n; j++){
                cout<<j<<sp;
            }
            cout<<endl;
            return;
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

/*
    Golden Rules:
    Solutions are simple.
    Proofs are simple.
    Implementations are simple.
*/