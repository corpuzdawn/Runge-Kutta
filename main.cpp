#include <iostream>
#include "runge_kutta.h"

using namespace std;

int main()
{
    double A, B, C, D, F, R, Tmax;
    cout<<"+--------------------------+\n" << \
          "|    Runge Kutta Project   |\n" << \
          "|           CE 30          |\n" << \
          "|  Corpuz, Domingo, Prado  |\n" << \
          "+--------------------------+\n\n" ;

    cout<< "Solving for the voltage 'y' across the capacitor in a series RC circuit...\n"<<\
           "When the voltage source is D + A sin (2piFt+B)\n\n"<<\
           "Enter the values for...\n";
    cout<< "D: ";
    cin>> D;
    cout<< "A: ";
    cin>> A;
    cout<< "F: ";
    cin>> F;
    while (F <= 0) {cout<< "F should be greater than zero!\nF: "; cin>> F;}
    cout<< "B: ";
    cin>> B;
    cout << "The voltage source is " << D << " + " << A << " sin(" << 2*F << "pit+"<< B << ")\n\n";
    cout<< "Enter the value of the resistor R: ";
    cin>> R;
    while (R <= 0) {cout<< "R should be greater than zero!\nR: "; cin>> R;}
    cout<< "Enter the value of the capacitor C (in microfarads): ";
    cin>> C;
    C = C*0.000001;
    while (C <= 0) {cout<< "C should be greater than zero!\nR: "; cin>> C;}
    cout << "Enter the Time limit or Time end: ";
    cin >> Tmax;
    while (Tmax <= 0) {cout<< "Tmax should be greater than zero!\nR: "; cin>> Tmax;}
    cout<< "\nGraph of Vc from t = 0 to t = " << Tmax << ":\n\n";

    RungeKutta RK;
    RK.inputData(A, B, C, D, F, R, Tmax);

    RK.computeRungeKutta();
    return 0;
}
