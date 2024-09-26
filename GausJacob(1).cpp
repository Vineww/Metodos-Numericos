#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float resolveX1(float x2, float x3) {
   
    return (32 - 5 * x2 - x3) / 20;

}

float resolveX2(float x3, float x1) {

    return ((-20 - 2 * x3 + 2* x1) / 10);  

}

float resolveX3(float x1, float x2) {

    return (14 - x1 - 4 * x2) / 10;

}

float calcErro(float novo, float antigo) {

    return fabs(novo - antigo);

}

int main() {

    float x1 = 2.0, x2 = 2.0, x3 = 2.0; 
    float novoX1, novoX2, novoX3; 
    float erro1, erro2, erro3;   
    float tolerancia = 0.2; 
    int maxIteracoes = 100; 
    int iteracao = 0;

    cout << fixed << setprecision(5);

    do {
        
        novoX1 = resolveX1(x2, x3);
        novoX2 = resolveX2(x3, x1);
        novoX3 = resolveX3(x1, x2);

        
        erro1 = calcErro(novoX1, x1);
        erro2 = calcErro(novoX2, x2);
        erro3 = calcErro(novoX3, x3);

        x1 = novoX1;
        x2 = novoX2;
        x3 = novoX3;

        iteracao++;

    } while ((erro1 > tolerancia || erro2 > tolerancia || erro3 > tolerancia) && iteracao < maxIteracoes);

    if (iteracao == maxIteracoes) {
   
        cout << "Método não convergiu após " << maxIteracoes << " iterações." << endl;
   
    } else {
   
        cout << "Iteração " << iteracao << ": x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 
        << ", erro1 = " << erro1 << ", erro2 = " << erro2 << ", erro3 = " << erro3 << endl;
        cout << "Convergiu em " << iteracao << " iterações." << endl;
   
    }

    return 0;
}
