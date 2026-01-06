#include <iostream>
using namespace std;
/*
int multiply(int a, int b)
{
    int c = a * b;
    return c;
}

float multiply(int a, float b)
{
    float c = a * b;
    return c;
}

float multiply(float a, int b)
{
    float c = a * b;
    return c;
}
    */

template <typename myType>
myType multiple(myType a, myType b)
{
    myType c = a * b;
    return c;
}

template <typename T, typename U>
T multiple(T a, U b)
{
    T c = a * b;
    return c;
}

int main()
{

    int a = multiple<int>(3, 4);
    float b = multiple<float>(3.2, 5.8);
    double c = multiple<double>(3, 6);
    system("cls");
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
cout << "-----(1)-------------" << endl;
    int d = multiple<int, int>(3.3, 7);
    float e = multiple<float, float>(3.5, 8.2);
    double f = multiple<double, float>(3.4, 9.2);

    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
cout << "-----(2)-------------" << endl;

    return 0;
}