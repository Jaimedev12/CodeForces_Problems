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
    
    int t; scanf("%d", &t);
    

    while(t--){
        int n; scanf("%d", &n);
        set <int> unique;
        // Leer numeros
        for(int i = 0; i < n; ++i){
            int temp; scanf("%d", &temp);
            unique.insert(temp);
        }
        // 
        function  f = [&]() -> bool{
            set<int>::iterator p1 = unique.begin();
            set<int>::iterator p2 = unique.begin(); p2++;
            
            while(p2 != unique.end()){
                int valor = *p2 % *p1;
                if(valor != 0){
                    if(valor == 1){
                        unique.insert(1);
                        return true;

                    }
                    else{
                        unique.insert(*p2%*p1);
                        return false;
                    }
                    
                }
                p2++;
            }

            return true;
                
        };
        // Agregar los modulos
        bool final = true;
        while(true){
            
            // El primero coparamos con los demás
            // Si te da un numero diferente de 0 reinicias, agregamos el numero y reiniciamos
            // Sino sigues hasta el final
                // 
                // 
            final =  f();
            if(final){
                printf("%d\n", *unique.rbegin() / *unique.begin());
                break;
            }
        }

    }

    return 0;

}   