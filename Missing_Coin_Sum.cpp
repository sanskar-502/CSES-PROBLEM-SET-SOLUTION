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
5
2 9 1 2 7




3
1 2 2
1 3 4


1 2 2 7 9
1 3 5 12 21


4
2 1 4 3

1 3 3 4
1 4 7 11

1 2 4 8
1 3 7 15

1 2 4 8 16
1 3 7 15 31



if i form 1 2  that is upto  3 if next coin is 3 then also i can from 4 as i form 3 and also 1  same i can form 3 +2= 5 3+3 =6  but i can't form >3   as 
i have 3  but next is 4
1 2 4
1 3 7


1 2 2 5 9
1 3 5 10 19            12 kar sakte hain  (12 -1 )==11 bhi kyuki 1 kar sakte lastly 5 tak 12-5= 7 tak lekin pahle to 6 tha

1 3 7 10  25   --> lastly 15 kar sakte hain



1 2 2 7 9
1 3 (5) 12 21
hum 5 tak to pahuch hi gye hain...    6tha chahiye 6th hai to think hai warna usse chot bhi hao to think hai

*/



void sanskar_502() {
    ll n;
    cin >> n;

    vll arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll reachable = 0;   // we can form all sums in [1, reachable]

    for (int i = 0; i < n; i++) {
        if (arr[i] > reachable + 1) {
            cout << reachable + 1 << nl;
            return;
        }
        reachable += arr[i];
    }

    cout << reachable + 1 << nl;

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