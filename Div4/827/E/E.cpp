// Plantilla de Tsurus Tuneados

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;


///-------------------------------------------------------------------------
///-------------------------------------------------------------------------

const lli MOD = 1e9 + 7;

///-------------------------------------------------------------------------

lli mcd(lli a, lli b) {return b ? mcd (b, a % b) : a;}
lli mcm(lli a, lli b) {return (!a || !b) ? 0 : a * b / mcd(a, b);}


int main() { _
    
    int T; cin >> T;

    while (T--) {
        lli nSteps, nQuestions; cin >> nSteps >> nQuestions;

        vi h(nSteps), sum(nSteps), min(nSteps);

        // Vector de alturas
        //cout << "Alturas: " << endl;
        fore(i, 0, nSteps) {
            cin >> h[i];

            //cout << h[i] << " ";
        }
        //cout << endl;

        // Vector de altura máxima para cada punto
        //cout << "Alturas máximas: " << endl;
        sum[0] = h[0];
        fore(i, 1, nSteps){
            sum[i] = sum[i-1] + h[i];

            //cout << sum[i] << " ";
        }
        //cout << endl;

        // Vector de longitud mínima de pierna para llegar a cada punto
        //cout << "Mínimos: " << endl; 
        min[0] = h[0];
        fore(i, 1, nSteps) {
            min[i] = max(min[i], min[i-1]);

            //cout << h[i] << " ";
        }
        //cout << endl;


        fore(i, 0, nQuestions) {
            lli temp; cin >> temp;
            auto upper = upper_bound(min.begin(), min.end(), temp);
            auto index = (upper - min.begin());

            //cout << "Upper: " << *upper << endl; 
            cout << "Index: " << index << endl;
            cout << "Temp: " << temp << endl;

            if (index == 0) {
                cout << 0 << " ";
            } 
            else if (index == min.size()) {
                cout << sum[nSteps-1] << " ";
            }
            else {
                cout << sum[index-1] << " ";
            }

            cout << endl << endl;

        }

        cout << endl;

    }

}   
