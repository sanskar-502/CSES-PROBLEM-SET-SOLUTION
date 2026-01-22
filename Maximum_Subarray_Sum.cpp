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
    int n;
    cin>>n;
    vll a(n);
    for(int i=0; i<n; i++)  cin>>a[i];

    ll sum=0;
    ll maxiSum = 0;

    for(int i=0; i<n; i++){
        sum += a[i];

        if(sum < 0)
            sum=0;

        maxiSum= max(maxiSum, sum);
    }

    cout<<(maxiSum==0 ? *max_element(a.begin(), a.end()) : maxiSum )<<nl;
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