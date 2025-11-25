#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cout<<" *** Multiplication Table ***"<<endl <<"Enter a number (2-100) : ";
    cin >> n;
    for (int i = 1;i<=12;i++){
        cout<< setw(4) <<right << n << " x " <<setw(2) << left << i << " = " << n*i <<endl;
    }
    return 0;
}