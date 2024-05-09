#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define endl '\n'
#define _                         \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for (lli i = (a), TT = (b); i < TT; ++i)

typedef vector<int> vi;

class UnionFind
{ // OOP style
private:
	vi p, rank, setSize; // vi p is the key part
	int numSets;

public:
	UnionFind(int N)
	{
		p.assign(N, 0);
		for (int i = 0; i < N; ++i)
			p[i] = i;
		rank.assign(N, 0);	  // optional speedup
		setSize.assign(N, 1); // optional feature
		numSets = N;		  // optional feature
	}

	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

	int numDisjointSets() { return numSets; }			 // optional
	int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

	void unionSet(int i, int j)
	{
		if (isSameSet(i, j))
			return;							// i and j are in same set
		int x = findSet(i), y = findSet(j); // find both rep items
		if (rank[x] > rank[y])
			swap(x, y); // keep x 'shorter' than y
		p[x] = y;		// set x under y
		if (rank[x] == rank[y])
			++rank[y];			  // optional speedup
		setSize[y] += setSize[x]; // combine set sizes at y
		--numSets;				  // a union reduces numSets
	}
};

int main()
{
	_ int n, m;
	cin >> n >> m;

	UnionFind uf(n);

	fore(i, 0, m)
	{
		int a, b;
		cin >> a >> b;

		uf.unionSet(a - 1, b - 1);
	}

	print(uf.numDisjointSets()-1);

	fore(i, 1, n) {
		if (uf.isSameSet(0, i)) continue;

		print(1 << " " << i+1);
		uf.unionSet(0, i);
	}

	return 0;
}