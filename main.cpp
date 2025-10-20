#include <iostream>
#include "Figure.hpp"
#include "point.hpp"
using namespace std;
int main(){
    Figure F;
    cin >> F;
    cout << F; 
    Figure B;
    B = F;
    cout << "Coordinated B" << endl;
    cout << B;


}