#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;
typedef vector<vi> vvi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

int main() { _

    int k; cin >> k;
    string s; cin >> s;
    lli sz = sz(s);

    vi pre(sz);
    lli sum = 0;
    lli cnt = 0;
    map<int, lli> mp;

    fore(i, 0, sz) {
        cout << "Sum: " << sum << " cnt: " << cnt << endl;
        for(auto it : mp) {
            cout<< it.first << " " << it.second << endl;
        }
        cout << endl;
        if (s[i] == '1') sum++;
        if (sum == k) cnt++;
        cnt += mp[sum-k];
        mp[sum]++;
    }

    cout << "Sum: " << sum << " cnt: " << cnt << endl;
    for(auto it : mp) {
        cout<< it.first << " " << it.second << endl;
    }
    cout << endl;

    print(cnt);
    return 0;

}


/*

typedef long long ll;

int n, m, k;

int main(){
  cin>>k;
  string s;
  cin>>s;
  int sz=s.size();
  int pre[sz];
  int sum=0;
  ll cnt=0ll;
  map<int,ll>m;
  for(int i=0;i<sz;i++)
  {
      if(s[i]=='1') sum+=1;
      if(sum==k) cnt=cnt+1ll;
      cnt+=m[sum-k];
      m[sum]++;
  }
  cout<<cnt<<endl;
}

*/