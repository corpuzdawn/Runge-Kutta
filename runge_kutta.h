#ifndef RUNGEKUTTA_H_INCLUDED
#define RUNGEKUTTA_H_INCLUDED

/*void inputData();
double f(double t, double y);
void computeK(double t, double y);
void computeRungeKutta();*/

class RungeKutta {
public:
    double A, B, C, D, F, R, Tmax;
    double pi, T0, Y0, H, RC, TwoPiF, N, dVC, k1, k2, k3, k4;

    double *t;
    double *y;

    RungeKutta();

    double f(double t, double y);
    void computeK(double t, double y);
    void computeRungeKutta();
    void inputData(double A, double B, double C, double D, double F, double R, double Tmax);
};

#endif // RUNGEKUTTA_H_INCLUDED

