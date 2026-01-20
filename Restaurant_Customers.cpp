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
3
5 8
2 4
3 9

2 4, 3 9, 5, 8
2 9  3 4  5 8

2 4, 5 8, 3 9


10
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
17 18
19 20

corr -> 1


10
45 84
2 43
34 64
42 99
50 80
12 21
72 82
39 86
33 89
47 97

*/



void sanskar_502() {
    int n;
    cin>>n;
    // vector<pair<ll, ll>> arr(n);
    vector<pair<int, int>> arr;

    for(int i=0; i<n; i++){
        // cin>>arr[i].second;  // arr
        // cin>>arr[i].first; //  dep
        
        int a,b;
        cin>>a>>b;

        arr.push_back({a, 1});
        arr.push_back({b, -1});

    }

    sort(arr.begin(), arr.end());
    // priority_queue<int, vector<int> > pq;
    // int maxi= 1;
    // for(int i= n-1 ; i>= 0; i--){

    //     pq.push(arr[i].second);

    //     while( pq.top()  >  arr[i].first){
    //         pq.pop();
    //     }

    //     int sz= pq.size();
    //     maxi= max(sz, maxi);
    // }

    // cout<<maxi<<nl;


    // i can replace the priority queue  by simpler approach

    int cnt=0;
    int maxi=1;
    for(int i=0; i<arr.size(); i++){
        cnt += arr[i].second;
        maxi= max(cnt,maxi);
    }

    cout<<maxi<<nl;


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