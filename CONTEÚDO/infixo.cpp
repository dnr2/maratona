#include <bits/stdc++.h>
using namespace std;

/* Programa para avaliação de uma expressão infixada
 * A expressão pode conter os operadores +, -, *, /, ^,
 * 	números com representação decimal (1.2, 10, -6E-1),
 * 	a incógnita 'x', a função unária f(x), a binária g(x,y)
 * Os operadores têm precedência, (+,-) < (*,/) < (^),
 * 	sendo que (-) pode ser operador infixado. Os operadores
 * 	infixados (-,f,g) tem a maior precedência.
 * +,-,*,/ têm avaliação da esquerda para direita, isso é,
 * 	a-b-c é interpretado como ((a-b)-c) e não (a-(b-c))
 * ^ tem avaliação da direita pra esquerda, isso é, a^b^c é
 * 	interpretado como (a^(b^c)), e não ((a^b)^c)
 * De quebra, podemos decidir se a expressão é válida ou não.
 * Ex.: 3.1-x^x^2*f(1)+g(-1e2+-1,x*---x) é válida, 2-*1+1e2e3 não
 * 
 * A gramatica pode ser escrita da seguinte forma (com avaliação de EXPRESSÃO):
 * 	EXPRESSÃO = FATOR | EXPRESSÃO+FATOR | EXPRESSÃO-FATOR
 * 	FATOR = EXPO | FATOR*EXPO | FATOR/EXPO
 * 	EXPO = ELEMENTO | ELEMENTO^EXPO
 * 	ELEMENTO = -ELEMENTO | (EXPRESSÃO) | f(EXPRESSÃO) | g(EXPRESSÃO,EXPRESSÃO) | x | NÚMERO
 * 
 * Observe que ao expandir EXPRESSÃO em "A+B+C", fica (pela 2a regra)
 * 	EXPRESSÃO = "A+B" e FATOR = "C", ao avaliar, temos (A+B)+C, diferente de
 * 	EXPO = "A^B^C", onde se tem pela segunda regra ELEMENTO = "A" e EXPO = "B^C",
 * 	avaliando para A^(B^C).
 * Observe também que a gramática é não-ambígua (desde que se avalie NÚMERO corretamente),
 * 	por exemplo, em EXPRESSÃO, a parti de FATOR, se não houver parênteses,
 * 	um "+" nunca será encontrado.
 * Mas o mais importante que se deve notar é que a gramática é "avaliável pela esquerda",
 * 	isso é, sempre é possível saber qual regra se deve aplicar a parti de avaliações simples,
 * 	interpretando token (caracter) a token, sem nunca precisar "olhar para trás", isso é,
 * 	fazer um backtracking.
 * Uma expansão importante aqui está em EXPRESSÃO (e em FATOR), a princípio não se sabe se
 * 	a regra a ser aplicada é a primeira ou a (segunda ou terceira), isso é, não se sabe se
 * 	se deve avaliar inicialmente uma EXPRESSÃO ou FATOR, porém em algum momento EXPRESSÃO será
 * 	avaliada unicamente como FATOR, então podemos expandir todas as EXPRESSÃOs alinhadas:
 * 	EXPRESSÃO = EXPRESSÃO+FATOR = EXPRESSÃO+FATOR+FATOR = ... = FATOR+...+FATOR, podemos
 * 	"acumular" EXPRESSÃO. Isso é usado para avaliação da esquerda para direita. Esse problema
 * 	não é encontrada em EXPO, por exemplo, pois a avaliação se dá da direita para esquerda.
 * O melhor da técnica é que ela cria a pilha do algoritmo de avaliação na própria pilha de execução!
 */

#define MAX_SIZE (1<<20)
char str[MAX_SIZE]; // armazena a expressão
int ptr; // ponteiro que indica o caracter sendo avaliado no momento
bool ok; // se estiver errado, ficar false
double x; // valor de x

// funções f e g
double f(double x) {
	return exp(x);
}
double g(double x, double y){
	return atan2(x,y);
}

// tente ler de baixo para cima

// captura número
double numero() {
	char *fim;
	double r = strtod(str+ptr, &fim);
	if( fim-str == ptr ) ok = false;
	ptr = fim-str;
	return r;
}

double expressao(); // só esse é necessário declarar cabeçalho

double elemento() {
	double X,Y;
	switch( str[ptr] ) {
	case '-':
		++ptr;
		return -elemento();
	case '(':
		++ptr;
		X = expressao();
		if( !ok ) return X;
		if( str[ptr++] != ')' ) ok = false;
		return X;
	case 'f':
		++ptr;
		if( str[ptr++] != '(' ) ok = false;
		X = expressao();
		if( !ok ) return X;
		if( str[ptr++] != ')' ) ok = false;
		return f(X);
	case 'g':
		++ptr;
		if( str[ptr++] != '(' ) ok = false;
		X = expressao();
		if( !ok ) return X;
		if( str[ptr++] != ',' ) ok = false;
		Y = expressao();
		if( !ok ) return Y;
		if( str[ptr++] != ')' ) ok = false;
		return g(X,Y);
	case 'x':
		++ptr;
		return x;
	default:
		return numero();
	}
}

// EXPO
double expo() {
	double e = elemento();
	if( str[ptr] == '^' ) {
		++ptr;
		e = pow(e, expo());
	}
	return e;
}

// FATOR
double fator() {
	// "acumulado"
	double acc = expo();
	while( str[ptr] == '*' || str[ptr] == '/' ) {
		if( str[ptr] == '*' ) {
			++ptr;
			acc = acc * expo();
		} else { // '/'
			++ptr;
			acc = acc / expo();
		}
	}
	return acc;
}

// EXPRESSÃO
double expressao() {
	// "acumulado"
	double acc = fator();
	while( str[ptr] == '+' || str[ptr] == '-' ) {
		if( str[ptr] == '+' ) {
			++ptr;
			acc = acc + fator();
		} else { // '-'
			++ptr;
			acc = acc - fator();
		}
	}
	return acc;
}

double avaliar(double x) {
	// init
	::x = x;
	ok = true;
	ptr = 0;
	// chama EXPRESSÃO e vê se acabou
	double r = expressao();
	ok &= str[ptr] == '\0';
	return r;
}

// tem como ficar bem menor, mas o código é prioritariamente didático
// também tem como fazer um dinâmico (como avaliações em haskell)

int main() {
	while( scanf("%s%lf", str, &x) == 2 ) {
		double r = avaliar(x);
		if( ok ) printf("%lf\n", r);
		else puts("Expressao incorreta");
	}
	return 0;
}


