#include <iostream>
#include <iomanip>
#include <cmath>
#include "runge_kutta.h"

using namespace std;


RungeKutta :: RungeKutta(){
 pi = 3.1416;
 T0 = 0;
 Y0 = 0;
};


double RungeKutta::f(double t, double y)
{
    return dVC = (1.0/RC)*(-y+D+A*sin(TwoPiF*t+B));
}

void RungeKutta::computeK(double t, double y)
{
    k1 = f(t,y);
    k2 = f(t+0.5*H, y+0.5*k1*H);
    k3 = f(t+0.5*H, y+0.5*k2*H);
    k4 = f(t+H, y+k3*H);

}

void RungeKutta::computeRungeKutta()
{
    double H = 1.0/(16.0*F);
    int i;
    y[0] = Y0;

    for (i=0; i<N; i++)
        t[i] = i*H;

    for (i=0; i<N; i++)
    {
        computeK(t[i],y[i]);
        y[i+1] = y[i] + (H/6.0)*(k1+2.0*k2+2.0*k3+k4);
        cout << "\ty[" << t[i] << "]  =  " << y[i] << endl;
    }
}

void RungeKutta::inputData(double A, double B, double C, double D, double F, double R, double Tmax) {
    this -> A = A;
    this -> B = B;
    this -> C = C;
    this -> D = D;
    this -> F = F;
    this -> R = R;
    this -> Tmax = Tmax;

 H = 1.0/(16.0*F);
 RC = R*C;
 TwoPiF = 2.0*pi*F;
 N = Tmax/H;
 t = new double[int(N)];
 y = new double[int(N)];
}
