//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146

/*
* FDP - eles dizem que "we get an element x without error" mas eles podem remover do vazio...
*/


#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <stack>

using namespace std;

int n, m, i, j, k, len, resp, t, K;
int a, b , c, d, depth;
int g, p, s;

bool ehPilha, ehFila, ehHeap, fdp;

queue<int> fila;
stack<int> pilha;
priority_queue<int> heap;

int main(){

    //freopen("in.txt", "r", stdin );
	//freopen("out.txt", "w", stdout );    
    
	while(scanf("%d", &n) > 0){
        
		while( !fila.empty()) fila.pop();
		while( !pilha.empty()) pilha.pop();
		while( !heap.empty()) heap.pop();
		
		ehPilha = ehFila = ehHeap = true;
		
		while(n--){
            fdp = false;
			scanf("%d %d", &a, &b);
			if(!fdp){
				if( a == 1){
					fila.push(b);
					pilha.push(b);
					heap.push(b);
				} else {
					if( !fila.empty() ){
						if( fila.front() != b) ehFila = false;
						if( pilha.top() != b) ehPilha = false ;
						if( heap.top() != b) ehHeap = false;   
						fila.pop();
						pilha.pop();
						heap.pop();
					} else {
						fdp = true;
						ehPilha = ehFila = ehHeap = false;
					}
				}	
			}				
		}
		if( ehFila && !ehPilha && !ehHeap ){
			printf("queue\n");
		} else if( !ehFila && ehPilha && !ehHeap){
			printf("stack\n");
		} else if( !ehFila && !ehPilha && ehHeap){
			printf("priority queue\n");
		} else if( ehFila || ehPilha || ehHeap){
			printf("not sure\n");
		} else {
			printf("impossible\n");
		}

	}
    return 0;

}

