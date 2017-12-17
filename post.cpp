#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;///CODIGO POR: univ: MARAZA HUALLPA LIMBER.

const string operadores[5] = {"+", "-", "*", "/", "^"};
///lee la expresion ingresada por teclado
string leerExpresion(string infija){
     int c=0;
     vector<int>list;
     cout << "Digite una expresion infija: ">
     getline( cin, infija );
     char *str = strdup(infija.c_str());
     char *pch = strtok(str,"+-*/^");
     while(pch!= NULL){
         list.push_back(atoi(pch));
         pch = strtok (NULL,"+-*/^");
    }
     for(int i=0;i<list.size();i++){
        if(list[i]>9)c++;
     }
     if(c==0)
        return infija;
     else{
         cout<<"\nSolo se permite numeros de un digito\n\n";
         system("pause");
         exit(0);
     }
    }
bool opMate( const string caracter ) {///evalua operador matematico

	for ( int i = 0; i < 5; i++ )
        if ( operadores[i] == caracter )
            return true;

	return 0;
}
int precedencia( const string carcter ) {
    int preced[5] = {1, 1, 2, 2, 3};
        for ( int i = 0; i < 5; i++ )
            if ( operadores[i] == carcter )
                return preced[i];

        return -1;///si no es operador
}
int main() {
 stack <string> pila;
        string infija, postfija, caracter,inf;
        char c;
        infija = leerExpresion(inf);
        int i=0;
        while (i < infija.size()) {
        c = infija[i++];
        caracter.clear();
        caracter += c;
        if ( c ==' ')continue;///obviar espacio
        if ( c >= '0' && c <= '9' ) {///si es un numero pasar al postfijo
            postfija = postfija + " " + c;
            continue;
        }
        if(opMate(caracter)){///operador sacada segun su precedencia si es verdadero
            while (!pila.empty()&&precedencia(pila.top())>= precedencia(caracter)){
                postfija = postfija + " " + pila.top();///operador pasa a la pila
                pila.pop();
        }
            pila.push(caracter);///coloca en caracter en la pila
            continue;
        }
        if ( caracter == "(" ){/// si se lee "(": colocar en la pila
            pila.push(caracter);
            continue;
        }
        if (caracter == ")"){///si se lee una ")", saca de la pila hasta encontrar "("
            while ( !pila.empty() && pila.top() != "(" ) {
                postfija = postfija + " " + pila.top();
                pila.pop();
            }
            if ( !pila.empty() )
                pila.pop(); /// Elimina "("
            }
        }
        while ( !pila.empty()){///pasa caracteres sobrantes a postfija
            postfija = postfija + " " + pila.top();
            pila.pop();
        }
	cout <<"\n\nLa expresion Postfija es: \n"<<" _______________________________________________________\n\n\t";
    cout<< postfija << endl <<" _______________________________________________________\n";
	return 0;
}
