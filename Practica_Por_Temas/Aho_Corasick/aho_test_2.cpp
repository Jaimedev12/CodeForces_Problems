#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(lli i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;
typedef long long int lli;
const lli MOD = 1e9 + 7;
 
struct vertex {
	map<char,lli> next,go;
	lli p,link, len = 0;
	char pch;
	bool is_terminal = 0;
	vertex(lli p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
 
vector<vertex> t;
 
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
 
lli go(lli v, char c);
 
void add_string(string s, lli id){
	lli v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		t[go(v,c)].len = t[v].len + 1; // Esto es para calcular el largo de la cadena que se forma
		v=t[v].next[c];
	}
	t[v].is_terminal = true;
}
 
 
lli get_link(lli v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
 
lli go(lli v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}
 
// void proc(lli x){
// 	if(vis[x])return;
// 	vis[x]=true;
// 	fore(i,0,t[x].leaf.size())r[t[x].leaf[i]]=true;
// 	proc(t[x].link);
// }
 
int main(){
	lli n; cin >> n;
 
    aho_init();
 
	set<string> stringSet;
 
	fore(i, 0, n) {
        string tempS; cin >> tempS;
		stringSet.insert(tempS);
        add_string(tempS, i);
    }
 
    string s; cin >> s;
 
	bool flag = 0;
 
	if (stringSet.find(s) != stringSet.end()) {
		flag = 1;
	} 
 
    fore(i, 0, t.size()) {
        get_link(i);
    }
 
 
    // fore(i, 0, t.size()) {
    //     cout << "Node: " << i << " " << t[i].pch << "   Ancestro: " << t[i].p << "   Link: " << t[i].link << "   Len: " << t[i].len << endl;
    //     cout << endl;;
    // }
 
	lli v = 0;
	n = s.size();
 
	vector<lli> dp(n+1, 0);
	dp[0] = 1;
 
	for(lli i=0; i < s.size(); i++){
		v = go(v, s[i]);
		if (t[v].is_terminal) {
			dp[i+1] += dp[i+1 - t[v].len] % MOD;
			dp[i+1] %= MOD;
			
			lli linked_v = get_link(v);
			while (linked_v != 0) {
				if (t[linked_v].is_terminal) {
					dp[i+1] += dp[i+1 - t[linked_v].len] % MOD;
					dp[i+1] %= MOD;
				}
				linked_v = get_link(linked_v);
			}
 
		} 
	}
 
	if (flag && dp[n] != 0) {
		dp[n]--;
	}
 
	cout << dp[n] % MOD << endl;
 
	// fore(i, 0, n+1) {
	// 	cout << dp[i]  << " ";
	// }
 
    // cout << endl;
 
	return 0;
}