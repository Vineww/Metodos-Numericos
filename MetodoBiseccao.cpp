#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float calculaFx(float x){

    return x * log(3*x - 1);

}

float achaRz(float a, float b, float erro){
    
    float  xn, 
           fa, 
           fx;

    xn = (a + b) / 2;

    fa = calculaFx(a);
    fx = calculaFx(xn);

    if (fabs(xn - a) < erro){
        
        return xn;

    }

    if ((fa < 0 && fx < 0) || (fa > 0 && fx > 0)){

        a = xn;

    }else{

        b = xn;

    }

    return achaRz(a, b, erro); 

}

int main(){

float erro   = 0.0,
       a     = 0.0,
       b     = 0.0;

cout << "Entre com A: ";
cin >> a;
cout << "Entre com B: ";
cin >> b;
cout << "Entre com o erro: ";
cin >> erro;

float raiz = achaRz(a, b, erro);

cout << fixed << setprecision(4);
cout << "raiz por | Xn - a |: " << raiz << "\n";

return 0;

}
