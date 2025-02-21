#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

double a, b;
time_t inicio;
void*suma(void* id);
void*resta(void* id);
void*mult(void* id);
void*division(void* id);
void*potencia(void*id);
void*sumatoria(void*id);

int main(){
    srand(time(0));
    pthread_t hilo1, hilo2, hilo3, hilo4, hilo5, hilo6;
    a = rand() % 1000;
    b = rand() % 1000;
    cout << "a = " << a << " y b = " << b << endl;
    inicio = time(NULL);
    pthread_create(&hilo1, NULL, suma, (void*) 0);  //funcion A
    pthread_create(&hilo2, NULL, resta, (void*) 1);  // Funcion B
    pthread_create(&hilo3, NULL, mult, (void*) 2);  // Funcion C

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    pthread_create(&hilo6, NULL, sumatoria, (void*) 5); //Funcion F

    pthread_join(hilo3, NULL);

    pthread_create(&hilo4, NULL, division, (void*) 4);  //Funcion D
    pthread_join(hilo6, NULL);
    pthread_join(hilo4, NULL);
    pthread_join(hilo5, NULL);

}

void*suma(void*id){
    sleep(2);
    time_t funcionA = time(NULL);
    cout << "Funcion A: " << funcionA - inicio << endl;
    cout << "a + b = " << a+b << endl;
    return NULL;
}

void*resta(void*id){
    sleep(2);
    time_t funcionB = time(NULL);
    cout << "Funcion B: " << funcionB - inicio << endl;
    cout << "a - b = " << a - b << endl;
    return NULL;
}

void*mult(void*id){
    sleep(2);
    time_t funcionC = time(NULL);
    cout << "Funcion C: " << funcionC - inicio << endl;
    cout << "a * b = " << a*b << endl;
    return NULL;
}

void*division(void* id){
    sleep(2);
    time_t funcionD = time(NULL);
    cout << "Funcion D: " << funcionD - inicio << endl;
    cout << "a / b = " << a/b << endl;
    return NULL;
}

void*potencia(void*id){
    sleep(2);
    time_t funcionE = time(NULL);
    cout << "Funcion E: " << funcionE - inicio << endl;
    cout << "a^2 = " << a*a << ". b^2 = " << b*b << endl;
    return NULL;
}

void*sumatoria(void*id){
    sleep(2);
    time_t funcionF = time(NULL);
    if(b < a){
            a, b = b, a;
    }
    int suma = 0;
    for(int i = a; i < b; i++){
            suma += i;
    }
    cout << "Funcion F: " << funcionF - inicio << endl;
    cout << "Suma de los numeros de a - b = " << suma << endl;
}