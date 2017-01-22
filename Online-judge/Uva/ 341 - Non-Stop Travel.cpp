#include <bits/stdc++.h>
#define MAX 100
#define INF 1000000000
#define Node pair< int, int >
using namespace std;

int dist[ MAX ];
int parent[ MAX ];
bool visit[ MAX ];
vector< Node > ady[ MAX ];

struct cmp{
  bool operator() ( const Node &a, const Node &b ){
    return a.second > b.second;
  }
};

priority_queue< Node, vector< Node >, cmp > Q;

void makeset( int n ){
  for ( int i = 0; i < n; i++ ){
    dist[i] = INF;
    visit[i] = false;
    parent[i] = -1;
    ady[i].clear();
  }
}

void relax( int a, int b, int peso ){
  if ( dist[a]+peso < dist[b] ){
    dist[b] = dist[a]+peso;
    parent[b] = a;
    Q.push( Node( b, dist[b] ) );
  }
}

void dijkstra( int source, int w ){
  dist[source] = 0;
  Q.push( Node( source, w ) );

  while ( !Q.empty() ){
    int actual = Q.top().first;
    Q.pop();
    if ( visit[actual] ) continue;
    visit[actual] = true;

    for ( int i = 0; i < ady[actual].size(); i++ ){
      int adyacente = ady[actual][i].first;
      int peso = ady[actual][i].second;
      if ( !visit[adyacente] ){
        relax( actual, adyacente, peso );
      }
    }
  }
}

void print( int x, int top, int N ){
  if ( top == N ) return;
  if ( parent[x] != -1 )
    print( parent[x], top+1, N );
  if ( x != 0 )
    cout << " " << x;
}

int main(){
  int N, R;
  int b, w;
  int o, d;
  int T = 0;
  while ( cin >> N && N != 0 ){
    makeset( N+1 );
    for ( int i = 0; i < N; i++ ){
      cin >> R;
      for ( int k = 0; k < R; k++ ){
        int a = i+1;
        cin >> b >> w;
        ady[a].push_back( Node( b, w) );
      }
    }
    cin >> o >> d;
    dijkstra( o, 0 );
    cout << "Case "<< ++T << ": Path =";
    print( d, 1, N+1 );
    cout << "; " << dist[d] << " second delay" << "\n";
    
  }
  return 0;
}
/*
5
2  3 3   4 6
3  1 2   3 7   5 6
1  4 5
0
1  4 7
2 4

2
1   2 5
1   1 6
1 2

7
4   2 5   3 13   4 8   5 18
2   3 7   6 14
1   6 6
2   3 5   5 9
3   6 2   7 9    4 6
1   7 2
0
1 7

0
*/
