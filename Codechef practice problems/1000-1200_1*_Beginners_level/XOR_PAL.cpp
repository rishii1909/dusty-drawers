#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// HELPER STUFF ENDS HERE, ACTUAL SOLUTION STARTS |


// Solution : The question allows us to replace the mismatches with a xor operation of two array elements.
// Logically, if we do have two array elements mismatched, it means either one of them is 1 and the other is 0. So, we always know we can atleast replace those two with a^b = 1
// Additionally, if we have two ones that are MISMATCHED, then we can XOR them with each other to give us 0, and replace them with this product. Since these 1s were mismatched, the corresponding palindrome value is already 0.
// This reduces the problem to finding out total number of mismatched 1s. For as many as possible, we will XOR 1s with each other, resulting in 1 operation to correct two indices.
// For the remainder 1s which don't have another 1 to pair with, we XOR it with a 0, which results in 1 operation correcting one indice.
// Hence the formula : (a / 2) + (a % 2); 

int solve(string s, int n) {

    int a = 0;
    for(int i = 0; i < n/2; i++){

        if(s[i] != s[n-i-1]) a++;
    }

    // cout << "Ones out of place are : " << a << endl;



    return (a/2) + (a%2);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        string temp = "";
        cin >> temp;
        cout << solve(temp, n) << endl;
    }
}