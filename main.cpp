
#include <iostream>
int dig[10] = {0};


void inc_dig(unsigned short i){
    dig[i]++;

}
void sort_(float temp) {
    if (temp >= 0 && temp < 10) {
        inc_dig(0);
    } else if (temp >= 10 && temp < 20) {
        inc_dig(1);
    } else if (temp >= 20 && temp < 30) {
        inc_dig(2);
    } else if (temp >= 30 && temp < 40) {
        inc_dig(3);
    } else if (temp >= 40 && temp < 50) {
        inc_dig(4);
    } else if (temp >= 50 && temp < 60) {
        inc_dig(5);
    } else if (temp >= 60 && temp < 70) {
        inc_dig(6);
    } else if (temp >= 70 && temp < 80) {
        inc_dig(7);
    } else if (temp >= 80 && temp < 90) {
        inc_dig(8);
    } else {
        inc_dig(9);
    }
}


long rand_first(long A, long C, long M )
{
    static long prev = 1;
    prev = (A*prev+C) % M  ;
    return prev;
}
using namespace std;

void print_menu();

int main() {
    print_menu();

    int type;
    cin >> type;

    switch (type)
    {   case 1:
            long A, C, M;


            cout << "Insert the coefficient A and C and M( M >1000 )" << endl;
            cin >> A >>  C >> M ;

            for (int i = 0; i < M-1; i++) { sort_(static_cast<float>(rand_first( A, C, M)) / static_cast<float>(M) * 100);}
            cout  <<"From 0 to 10 --- " << static_cast<float>(dig[0])/ static_cast<float>(M-1)  <<  endl;
            cout  <<"From 10 to 20 --- " << static_cast<float>(dig[1]) / static_cast<float>(M-1) <<  endl;
            cout  <<"From 20 to 30 --- "<< static_cast<float>(dig[2]) / static_cast<float>(M-1) <<  endl;
            cout  <<"From 30 to 40 --- " << static_cast<float>(dig[3]) / static_cast<float>(M-1) <<  endl;
            cout  <<"From 40 to 50 --- " << static_cast<float>(dig[4]) / static_cast<float>(M-1) <<  endl;
            cout  <<"From 50 to 60 --- " << static_cast<float>(dig[5]) / static_cast<float>(M-1) <<  endl;
            cout  <<"From 60 to 70 --- " << static_cast<float>(dig[6]) / static_cast<float>(M-1) <<  endl;
            cout  <<"From 70 to 80 --- " << static_cast<float>(dig[7]) / static_cast<float>(M-1) <<  endl;
            cout  <<"From 80 to 90 --- " << static_cast<float>(dig[8]) / static_cast<float>(M-1) <<  endl;
            cout  <<"From 90 to 100 --- " << static_cast<float>(dig[9]) / static_cast<float>(M-1) <<  endl;

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