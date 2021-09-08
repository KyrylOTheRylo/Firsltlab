
#include <iostream>

using namespace std;

void print_menu();

int main() {
    print_menu();

    int type;
    cin >> type;

    switch (type)
    {   case 1:
            cout<<"OK"<<endl;
        case 2:
            //code
            break;
        case 3:
            //code
            break;
        case 4:
            //code
            break;
        case 5:
            //code
            break;
        case 6:
            //code
            break;
        case 7:
            //code
            break;
        case 8:
            //code
            break;
        case 9:
            //code
            break;
        case 10:
            //code
            break;
        default:
            cout << "Wrong input!!!\nOnly 1-10 requires";
    }

    return 0;
}

void print_menu() {
    cout << "Enter generator type: " << endl;
    cout << "\t1 - Linear Congruential Generator" << endl;
    cout << "\t2 - Quadratic Congruential Generator" << endl;
    cout << "\t3 - Fibonacci Numbers Generator" << endl;
    cout << "\t4 - Inverse Congruent SequenceGenerator" << endl;
    cout << "\t5 - Union Method Generator" << endl;
    cout << "\t6 - Sigma Method Generator" << endl;
    cout << "\t7 - Polar Coordinate Method Generator" << endl;
    cout << "\t8 - Relation Method Generator" << endl;
    cout << "\t9 - Logarithm Method Generator" << endl;
    cout << "\t10 - Arens Method Generator\n" << endl;
}
#pragma clang diagnostic pop