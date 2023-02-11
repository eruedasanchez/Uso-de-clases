#include <vector>
#include "algobot.h"

using namespace std;

/* Ejercicio 1 de la clase. Vector */

pair<vector<int>, vector<int>> pares_e_impares(vector<int> s){
    pair<vector<int>, vector<int>> paresEimpares;
    vector<int> pares;
    vector<int> impares;

    for(int i = 0; i < s.size(); i++){
        if(s[i] % 2 == 0){
            /* El elemento es par */
            pares.push_back(s[i]);
        } else {
            /* El elemento es impar */
            impares.push_back(s[i]);
        }
    }
    /* Una vez colocados todos los elementos segun su paridad, devuelvo la tupla */
    paresEimpares = make_pair(pares, impares);
    return paresEimpares;
}

/* Ejercicio 2 de la clase. Interseccion utilizando conjuntos */

vector<int> interseccion(vector<int> a, vector<int> b){
    vector<int> inter;
    set<int> conjuntoA;

    /* Pasamos todos los elementos del vector "a" al conjunto "conjuntoA" */
    for(int i = 0; i < a.size(); i++){
        conjuntoA.insert(a[i]);
    }

    /* Por ultimo, vemos que elementos del vector "b" se encuentra en el conjunto "conjuntoA" */
    for(int j = 0; j < b.size(); j++){
        if(conjuntoA.count(b[j]) == 1){
            inter.push_back(b[j]);
        }
    }
    return inter;
}

/* Ejercitacion a resolver */

/* Ejercicio 1 */

int cantApariciones(vector<int> vec, int elem, int desde, int hasta){
    int apariciones = 0;
    for(int i = desde; i < hasta; i++){
        if(vec[i] == elem){
            apariciones++;
        }
    }
    return apariciones;
}

vector<int> quitar_repetidos(vector<int> s){
    vector<int> sinRepetidos;

    for(int i = 0; i < s.size(); i++){
        if(cantApariciones(s,s[i],0,i) == 0){
            sinRepetidos.push_back(s[i]);
        }
    }
    return sinRepetidos;
}

/* Ejercicio 2 */
vector<int> quitar_repetidos_v2(vector<int> s){
    vector<int> sinRepe;
    set<int> setSinRepetidos;
    for(int i = 0; i < s.size(); i++){
        if(setSinRepetidos.count(s[i]) == 0){
            setSinRepetidos.insert(s[i]);
        }
    }

    /* Por ultimo, se pasan los elementos del conjunto al vector */
    for(int n: setSinRepetidos){
        sinRepe.push_back(n);
    }
    return sinRepe;
}

/* Ejercicio 3 */
bool estaEn(vector<int> vec, int elemento){
    bool seEncuentra = false;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == elemento){
            seEncuentra = true;
            break;
        }
    }
    return seEncuentra;
}
bool mismos_elementos(vector<int> a, vector<int> b) {
    int indexA = 0;
    int indexB = 0;
    bool mismos = false;

    if(a.size() == 0 && b.size() == 0){
        /* Caso particular donde ambos vectores son vacios */
        mismos = true;
    } else {
        /* Casos restantes */
        while((indexA < a.size()) && (estaEn(b,a[indexA]))){
            /* No hago nada. Aumento i */
            indexA++;
        }
        while((indexB < b.size()) && (estaEn(a,b[indexB]))){
            /* No hago nada. Aumento i */
            indexB++;
        }
    }

    if(indexA == a.size() && indexB == b.size()){
        mismos = true;
    }
    return mismos;
}

/* Ejercicio 4 */
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    bool mismosElementos = false;
    int i = 0;
    int j = 0;
    set<int> conjuntoA;
    set<int> conjuntoB;

    if(a.size() == 0 && b.size() == 0){
        /* Caso particular donde ambos vectores son vacios */
        mismosElementos = true;
    } else {
        /* Casos restantes */

        /* Se coloca en un conjunto a los elementos de a sin repetidos */
        for(int indexA = 0; indexA < a.size(); indexA++){
            if(conjuntoA.count(a[indexA]) == 0){
                conjuntoA.insert(a[indexA]);
            }
        }

        /* Se coloca en un conjunto a los elementos de b sin repetidos */
        for(int indexB = 0; indexB < a.size(); indexB++){
            if(conjuntoB.count(a[indexB]) == 0){
                conjuntoB.insert(a[indexB]);
            }
        }

        /* Por ultimo, se fija si ambos conjuntos tienen los mismos elementos */
        for(int n: conjuntoA){
            if(conjuntoB.count(n) == 0){
                mismosElementos = false;
                break;
            } else {
                i++;
            }
        }

        for(int m: conjuntoB){
            if(conjuntoA.count(m) == 0){
                mismosElementos = false;
                break;
            } else {
                j++;
            }
        }
    }

    if((i == conjuntoA.size()) && (j == conjuntoB.size())){
        mismosElementos = true;
    }
    return mismosElementos;
}

/* Ejercicio 5 */
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> elementosyApariciones;

    for(int n: s){
        if(elementosyApariciones.count(n) == 0){
            /* La  clave no esta definida */
            elementosyApariciones[n] = 1;
        } else {
            /* La clave esta definida */
            elementosyApariciones[n] = elementosyApariciones[n] + 1;
        }
    }
    return elementosyApariciones;
}

/* Ejercicio 6 */
int apariciones(vector<int> vec, int elem){
    int ap = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == elem){
            ap++;
        }
    }
    return ap;
}


vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> sinRepetidos;

    for(int i = 0; i < s.size(); i++){
        if(apariciones(s,s[i]) < 2){
            sinRepetidos.push_back(s[i]);
        }
    }
    return sinRepetidos;
}

/* Ejercicio 7 */
set<int> interseccion(set<int> a, set<int> b) {
    set<int> inter;

    /* Vemos que elementos del conjunto "b" se encuentran en el conjunto "a" */
    for(int n: b){
        if(a.count(n) == 1){
            inter.insert(n);
        }
    }
    return inter;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
