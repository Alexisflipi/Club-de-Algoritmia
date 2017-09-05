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
    bool ans = ch[s[idx]].search(s, idx + 1);
    return ans;
  }
};

