#include<bits/stdc++.h>
using namespace std;

struct node {
    node *nxt[26];
    
    char lorw = '.';
    
    node() {
        for (int i = 0; i < 26; i++) {
            nxt[i] = nullptr;
        }
    }
};

node *root;

void insert_trie(string s) {
    node* cur = root;
    
    for (size_t i = 0; i < s.size(); i++) {
        int imap = s[i] - 'a';
        if (cur->nxt[imap] == nullptr) {
            cur->nxt[imap] = new node();
        }
        cur = cur->nxt[imap];
    }
    
    cur->lorw = 'L';
}

bool isWin(node* cur) {

    if (cur->lorw == 'W') {
        return true;
    } else if(cur->lorw == 'L') {
        return false;
    }
    
    for (int i = 0; i < 26; i++) {
        
        if (cur->nxt[i] == nullptr) continue;
        
        if (!isWin(cur->nxt[i])) {
            cur->lorw = 'W';
            return true;
        }
    }

    cur->lorw = 'L';
    return false;
    
}

bool solve( vector<string> words ){
    root = new node();
    
    for (auto word : words) {
        insert_trie(word);
    }
    
    return isWin(root);
}

int main() {

    vector<string> vec = {"ahas", "aghost", "aghostbuster"};

    cout << solve(vec) << endl;

    return 0;
}