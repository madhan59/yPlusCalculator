#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    double referenceLength;
    double yPlus;
    double deltaS;
    double uInf;
    double dynamicViscosity;
    double density;
    double uPlus;
    double wallShearStress;
    double Re;
    double Cf;
    string flow;
    flow = "internal", "external";

    cout << "Enter the reference length (m): " << endl;
    cin >> referenceLength;
    cout << "Enter the density (kg/m3): " << endl;
    cin >> density;
    cout << "Enter the freestream velocity (m/s): " << endl;
    cin >> uInf;
    cout << "Enter the viscosity (Pa/s): " << endl;
    cin >> dynamicViscosity;
    cout << "Enter the desired yPlus value: " << endl;
    cin >> yPlus;

    Re = ((density*uInf*referenceLength)/(dynamicViscosity));

    cout << "Enter the type of flow (internal/external): " << endl;
    cin >> flow;

    if (flow == "external" && Re <= 5E5)
    {
        cout << "The flow is laminar." << endl;
    }
    else if (flow == "external" && Re >= 1E7)
    {
        cout << "The flow is turbulent." << endl;
    }
    else if (flow == "internal" && Re <= 2300)
    {
        cout << "The flow is laminar." << endl;
    }
    else if (flow == "internal" && Re >= 4000)
    {
        cout << "The flow is turbulent." << endl;
    }
    else
    {
        cout << "The flow is in transitional regime." << endl;
    }

    cout << "The value of Reynolds number is: " << Re << endl;


    if (Re <= 10E9)
    {
        Cf = 0.026/pow (Re, 0.142857);                  // pow (Re, 0.142857) = (Re^(1/7)
        wallShearStress = (Cf*0.5*density*uInf*uInf);
        uPlus = sqrt (wallShearStress/density);
        deltaS = ((yPlus*dynamicViscosity)/(uPlus*density));

        cout << "The value of first cell height is " << deltaS << " m." << endl;
    }
    else
    {
        cout << "The value of Reynolds number is unphysical." << endl;
    }


}
