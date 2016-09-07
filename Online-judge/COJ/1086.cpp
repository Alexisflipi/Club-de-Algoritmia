#include<bits/stdc++.h>
using namespace std;

int n,i,k,aux;
int m[4567895];

int criba( int tam){
	m[0] = false;
    m[1] = false;
    for(int i = 2; i <= tam; ++i) 
        m[i] = true;

    for(int i = 2; i*i <= tam; ++i) {
        if(m[i]){
            for(int h = 2; i*h <= tam; ++h)
                m[i*h] = false;
        }
    }
}


int main(){
	criba(4567891);
	while( i != 10){
		scanf("%d",&n);
		for( k = 2 ; k <= n ;k++)
			if( m[k] == true)
				aux++;
		printf("%d\n",aux);
		i++;
		aux = 0;
	}
	return 0;
}