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

bool comp(vector<int>a, vector<int> b){
    return a[0] < b[0];
}


int solve(vector<vector<int>> arr) {
    
    std::sort(arr.begin(), arr.end(), comp);

    for(auto el : arr){
        for(auto e : el) cout << e << " ";
        cout << endl;
    }

    int n = arr.size();

    int ans = 1;

    int i = 0, j = 1;
    while(i < n && j < n){

        if(arr[i][1] >= arr[j][0]){

            j++;
            ans = std::max(ans, j-i);
        }
        else{
            i++;
            j++;
        }
    }

    return ans;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {

        int n;
        cin >> n;

        vector<vector<int>> arr;

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            arr.push_back({temp});
        }

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
        cout << solve(arr) << endl;
    }
}