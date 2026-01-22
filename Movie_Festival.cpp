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

    vii arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].second;
        cin>>arr[i].first;
    }

    sort(arr.begin(), arr.end());

    int prev= arr[0].first;
    // cout<<sp<<"prev"<<sp<<prev<<endl;
    int cnt=1;
    for(int i=1; i<n; i++){
        // cout<<sp<<"prev"<<sp<<prev<<endl;
        // cout<<sp<<"arrival"<<sp<<arr[i].second<<endl;
        // cout<<sp<<"dep"<<sp<<arr[i].first<<endl;
        if(prev <= arr[i].second){
            prev= arr[i].first;
            cnt++;
        }else{
            continue;
        }
    }


    cout<<cnt<<nl;
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