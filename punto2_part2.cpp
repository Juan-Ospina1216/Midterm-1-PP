#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

double a, b;
time_t inicio;
int suma();
int resta();
int mult();
int division();
int potencia();
int sumatoria();

int main(){
    srand(time(0));
    pthread_t hilo1, hilo2;
    a = rand() % 1000;
    b = rand() % 1000;
    cout << "a = " << a << " y b = " << b << endl;
    inicio = time(NULL);

    #pragma omp parallel sections
    {
        //Funcion A
        #pragma omp section
        {suma();}
        //funcion B
        #pragma omp section
        {resta();}

        //Funcion C
        #pragma omp section
        {mult();}
    }
    #pragma omp parallel sections
    {
        #pragma omp section
        //Funcion D
        {division();}
        #pragma omp section
        //Funcion F
        {sumatoria();}
    }
        //Funcion E
        potencia();
}
    
int suma(){
    sleep(2);
    time_t funcionA = time(NULL);
    cout << "Funcion A: " << funcionA - inicio << endl;
    cout << "a + b = " << a+b << endl;
    return 0;
}

int resta(){
    sleep(2);
    time_t funcionB = time(NULL);
    cout << "Funcion B: " << funcionB - inicio << endl;
    cout << "a - b = " << a - b << endl;
    return 0;
}

int mult(){
    sleep(2);
    time_t funcionC = time(NULL);
    cout << "Funcion C: " << funcionC - inicio << endl;
    cout << "a * b = " << a*b << endl;
    return 0;
}

int division(){
    sleep(2);
    time_t funcionD = time(NULL);
    cout << "Funcion D: " << funcionD - inicio << endl;
    cout << "a / b = " << a/b << endl;
    return 0;
}
    
int potencia(){
    sleep(2);
    time_t funcionE = time(NULL);
    cout << "Funcion E: " << funcionE - inicio << endl;
    cout << "a^2 = " << a*a << ". b^2 = " << b*b << endl;
    return 0;
}

int sumatoria(){
    int sum = 0;
    sleep(2);
    time_t funcionF = time(NULL);
    if(b < a){
        a, b = b, a;
    }else{
        for(int i = a; i < b; i++){
            sum += i;
        }
    }
    cout << "Funcion F: " << funcionF - inicio << endl;
    cout << "Sumatoria de a - b = " << sum << endl;
    return 0;
}
    