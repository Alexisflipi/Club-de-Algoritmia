#include <bits/stdc++.h>
#define INF 1000000000
#define MAX 100000
using namespace std;

int parent[ MAX ];
int rank[ MAX ];
struct Edge{
	int origen;
	int destino;
	int peso;
	Edge(){}
	bool operator<( const Edge &e ) const {
		return peso < e.peso;
	}
}arista[ MAX ];

void makeset( int n ){
	for ( int i = 0; i < n; i++ ){
		parent[ i ] = i;
		rank[ i ] = 0;
	}
}

int Find( int x ){
	if ( x == parent[ x ] ) return x;
	return parent[ x ] = Find( parent[ x ] );
}

bool samec( int a, int b ){
	if ( Find( a ) == Find( b ) ) return true;
	return false;
}

void Union( int x, int y ){
	int xroot = Find( x );
	int yroot = Find( y );
	if ( rank[ xroot ] > rank[ yroot ] )
		parent[ yroot ] = xroot;
	else{
		parent[ xroot ] = yroot;
		if ( rank[ xroot ] == rank[ yroot ] )
			rank[ yroot ]++;
	}
}

vector< Edge > aux;
vector< Edge > MST;

int kruskal( int d, bool ban ){
	int total = 0;

	for ( int i = 0; i < d; i++ ){
		int a = arista[ i ].origen;
		int b = arista[ i ].destino;
		int peso = arista[ i ].peso;
		if ( !samec( a, b ) ){
			Union( a, b );
			total += peso;
			if ( ban ) MST.push_back( arista[ i ] );
		}
	}
	return total;
}

void copy( int n ){
	for ( int i = 0; i < n; i++ ){
		arista[ i ].origen = aux[ i ].origen;
		arista[ i ].destino = aux[ i ].destino;
		arista[ i ].peso = aux[ i ].peso;
	}
}

bool check( int i, int j ){
	if ( MST[ i ].peso == arista[ j ].peso && MST[ i ].origen == arista[ j ].origen && MST[ i ].destino == arista[ j ].destino )
		return true;
	return false;
}
int main(){
	int T, N, V, A, B, W;
	cin >> T;

	for ( int i = 0; i < T; i++ ){
		cin >> N >> V;
		for ( int k = 0; k < V; k++ ){
			cin >> A >> B >> W;
			arista[ k ].origen = A;
			arista[ k ].destino = B;
			arista[ k ].peso = W;
		}
		sort( arista, arista + V );
		for ( int i = 0; i < V; i++ )
			aux.push_back( arista[ i ] );

		makeset( N+1 );
		int ans1 = kruskal( V, true );
		int mini = INF;

		for ( int i = 0; i < MST.size(); i++ ){
			copy( V );
			for ( int j = 0; j < V; j++ ){
				if ( check( i, j ) ){
					arista[ j ].peso = INF;
					break;
				}
			}
			makeset( N+1 );
			sort( arista, arista + V );
			mini = min( mini, kruskal( V, false ) );
		}
		cout << ans1 << " " << mini << "\n";
		aux.clear();
		MST.clear();
	}
	return 0;
}
/*
2
5 8
1 3 75
3 4 51
2 4 19
3 2 95
2 5 42
5 4 31
1 2 9
3 5 66
9 14
1 2 4
1 8 8
2 8 11
3 2 8
8 9 7
8 7 1
7 9 6
9 3 2
3 4 7
3 6 4
7 6 2
4 6 14
4 5 9
5 6 10
*/