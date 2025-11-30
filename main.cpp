#include <iostream>
#include "op.h"

using namespace std;
int main()
{
    cout << "hello world" << endl;
    cout << "1 + 1 = " << add(1, 1) << endl;
    cout << "3.14 - 1 = " << sub(3.14, 1) << endl;
    cout << "2.5 x 2.5 = " << mult(2.5, 2.5) << endl;
    cout << "5.5 / 5 = " << divide(5.5, 5) << endl;
    system("pause");
    return 0;
}