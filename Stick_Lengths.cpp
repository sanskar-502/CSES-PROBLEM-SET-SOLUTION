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

1 2 2 2 50
24 23 23 25     25
1 0 0 0 48
1 2 4 4 4 7 8 6 11  5 5 5 3
3 2 0 0 0 3 4 2 5 1 1 1 1  = 23
4 3 1 1 1 2 3 1 6 0 0 0 2= 24
13/5= 2.5 --> 3  or   2.5 >3  and  2.5 <= 2


5
1 4 5 100 100


avg may represent randomness

but mid value shows equal distribution....
8
0 1 2 3 4 5 6 7
*/



void sanskar_502() {
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    ll val=-1;
    if(odd(n)){
        val= arr[n/2];
    }else{
        val = (arr[n/2] + arr[n/2 - 1])/2;
    }

    ll val1=0;
    for(int i=0; i<n; i++){
        val1 += abs(arr[i] - val);
    }
 
    cout<<val1<<nl;

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