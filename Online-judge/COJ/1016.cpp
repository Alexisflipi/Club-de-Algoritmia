#include <bits/stdc++.h>
#define MAX 5000
#define p pair< double, double >
using namespace std;

struct Edge{
	
	int origen;
	int destino;
	double peso;
	Edge(){}
	bool operator<(const Edge &e ) const {
		return peso < e.peso;
	}

}arista[ MAX ];

int parent[ MAX ];
int rank[ MAX ];

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

void Union( int x, int y ){
	int xroot = Find( x );
	int yroot = Find( y );
	if ( rank[ xroot ] > rank[ yroot ] ){
		parent[ yroot ] = xroot;
	}else{
		parent[ xroot ] = yroot;
		if ( rank[ xroot ] == rank[ yroot ] ){
			rank[ yroot ]++;
		}
	}
}

bool samec( int x, int y ){
	if ( Find( x ) == Find( y ) ) return true;
	return false;
}

double dist( p x, p y ){
	return (x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second);
}

vector< p > puntos;

double kruskal( int V, int A ){
	double total = 0.0;
	for ( int i = 0; i < A; i++ ){
		int a = arista[ i ].origen;
		int b = arista[ i ].destino;
		double peso = arista[ i ].peso;

		if ( !samec( a, b ) ){
			Union( a, b );
			total += sqrt( peso );
		}
	}
	return total;
}

int main(){
	int N;
	double x, y;

	cin >> N;
	for ( int i = 0; i < N; i++ ){
		cin >> x >> y;
		puntos.push_back( make_pair( x, y ) );
	}
	int cont = 0;
	for ( int i = 0; i < N; i++ ){
		for ( int j = i+1; j < N; j++ ){
			arista[ cont ].origen = i+1;
			arista[ cont ].destino = j+1;
			arista[ cont ].peso	= dist( puntos[ i ], puntos[ j ] );
			cont++;
		}
	}
	sort( arista, arista + cont );
	makeset( N+1 );
	cout << fixed;
	cout << setprecision( 2 ) << kruskal( N, cont ) << endl;
	return 0;
}
/*
4
1.0 1.0
2.0 2.0
2.0 4.0
1.0 2.0

3
1.0 1.0
2.0 2.0
2.0 4.0
*/