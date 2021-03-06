#include <bits/stdc++.h>
using namespace std;

//Minimum number of characters you need to type in your text message. (Trie)

struct Trie{
  int cont;
  map<char, Trie> ch;
  Trie() : cont(0) {}

  int add(string &s, int idx) {
    ++cont;
    if (idx >= s.size()) return 0;
    int res = ch[s[idx]].add(s, idx + 1);
    return (cont == 1) ? 0 : res + 1;
  }
};

//Built Trie and search a string

struct Trie{
  bool flag;
  map<char, Trie> ch;
  
  Trie() : flag(0) {}

  void add(string &s, int idx) {
    if (idx == s.size()) {flag = 1; return;}
    ch[s[idx]].add(s, idx + 1);
  }

  bool search(string &s, int idx) {
    if (idx == s.size()) return flag;
    if (!ch.count(s[idx])) return 0;
    bool ans = ch[s[idx]].search(s, idx + 1);
    return ans;
  }
};

//Trie (more quick)

struct Trie{
  bool flag;
  map<int, Trie*> ch;
  Trie() : flag(0) {}

  void add(string &s) {
    Trie *cab = this;
    forn(i, 0, s.size()) {
      if (!cab -> ch.count(s[i] - 'a'))
        cab -> ch[s[i] - 'a'] = new Trie();
      cab = cab -> ch[s[i] - 'a'];
    }
    cab -> flag = 1;
  }
};

