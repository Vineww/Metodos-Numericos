#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculaFx(double x){

    return x * log(3*x - 1);

}

double achaRz(double a, double b, double erro){
    
    double xn, 
           fa, 
           fx;

    xn = (a + b) / 2;

    fa = calculaFx(a);
    fx = calculaFx(xn);

    if (fabs(b - a) < erro){
        
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

double erro  = 0.01,
       a    = 0.4000,
       b    = 1.0000;

double raiz = achaRz(a, b, erro);

cout << fixed << setprecision(5);
cout << "raiz por | Xn - a |: " << raiz << "\n";

return 0;

}
