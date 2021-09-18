
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int dig[10] = {0};


void inc_dig(unsigned short i){
    dig[i]++;

}


unsigned long abs_own(unsigned long A , unsigned long B){
    if ((A-B) < 0){
        return  B - A;
    }else return A-B;
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


unsigned long rand_first(int A, int C, int M )
{   
    static unsigned long prev = 1;
    prev = (prev*A + C) % M  ;
    return prev;
}
int binpow(int a, int n, int temp) {
    int res = 1, x=n;
    while (x)
        if (x & 1) {
            res *= a;
            res = res % temp;
            --x;
        }
        else {
            a *= a;
            a = a % temp   ;
            x >>= 1;
        }
    return res;
}

unsigned long long  rand_second(int D, int A, int C, int M )
{
    static unsigned long long prev = 1;

    prev = (D*prev*prev+A*prev+C) % M  ;
    return prev;
}
unsigned long rand_third(int A, int C, int M)
{
    static unsigned long prev = C, preprev = A ;
    unsigned long temp;
    temp = prev;
    prev=(preprev + prev)% M;
    preprev = temp;
    return preprev;
}

unsigned long rand_fourth( int A, int C, int Q ) {
    static unsigned long prev = 1;
    if (prev != 0){
        prev = ((A * binpow(prev, Q-2, Q) + C) % Q);
    }
    else prev = C % Q;
    
    return prev;
}
void first(){
    int  A , C , M ;
    char check;
    
    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        cout << "Insert the coefficient A and C and M( M >1000 )" << endl;
        cin >> A >> C >> M ;
        }
    else A = 2, C = 666, M = 39916801;
    for (int i = 0; i < M - 1; i++) { sort_(static_cast<float>(rand_first(A, C, M)) / static_cast<float>(M) * 100); }
    cout << "From 0 to 10 --- " << static_cast<float>(dig[0]) / static_cast<float>(M - 1) << endl;
    cout << "From 10 to 20 --- " << static_cast<float>(dig[1]) / static_cast<float>(M - 1) << endl;
    cout << "From 20 to 30 --- " << static_cast<float>(dig[2]) / static_cast<float>(M - 1) << endl;
    cout << "From 30 to 40 --- " << static_cast<float>(dig[3]) / static_cast<float>(M - 1) << endl;
    cout << "From 40 to 50 --- " << static_cast<float>(dig[4]) / static_cast<float>(M - 1) << endl;
    cout << "From 50 to 60 --- " << static_cast<float>(dig[5]) / static_cast<float>(M - 1) << endl;
    cout << "From 60 to 70 --- " << static_cast<float>(dig[6]) / static_cast<float>(M - 1) << endl;
    cout << "From 70 to 80 --- " << static_cast<float>(dig[7]) / static_cast<float>(M - 1) << endl;
    cout << "From 80 to 90 --- " << static_cast<float>(dig[8]) / static_cast<float>(M - 1) << endl;
    cout << "From 90 to 100 --- " << static_cast<float>(dig[9]) / static_cast<float>(M - 1) << endl;
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
void second(){
    int D, A, C, M ;
    char  check;

    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        cout << "Insert the coefficient D, A and C and M( M >1000 )" << endl;
        cin >> D >> A >> C >> M ;
    }
    else D=2, A=5, C=1231379, M=39916801;

    for (int i = 0; i < M-1; i++) {sort_(static_cast<float>(rand_second(D, A, C, M)) / static_cast<float>(M) * 100);}
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
}
void third(){
    int  A , C , M ;
    char check;
    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        cout << "Insert the coefficient A and C and M( M >1000 )" << endl;
        cin >> A >> C >> M ;
    }
    else  A = 3, C = 5, M = 9973;
    for (int i = 0; i < M - 1; i++) { sort_(static_cast<float>(rand_third(A, C, M)) / static_cast<float>(M) * 100); }
    cout << "From 0 to 10 --- " << static_cast<float>(dig[0]) / static_cast<float>(M - 1) << endl;
    cout << "From 10 to 20 --- " << static_cast<float>(dig[1]) / static_cast<float>(M - 1) << endl;
    cout << "From 20 to 30 --- " << static_cast<float>(dig[2]) / static_cast<float>(M - 1) << endl;
    cout << "From 30 to 40 --- " << static_cast<float>(dig[3]) / static_cast<float>(M - 1) << endl;
    cout << "From 40 to 50 --- " << static_cast<float>(dig[4]) / static_cast<float>(M - 1) << endl;
    cout << "From 50 to 60 --- " << static_cast<float>(dig[5]) / static_cast<float>(M - 1) << endl;
    cout << "From 60 to 70 --- " << static_cast<float>(dig[6]) / static_cast<float>(M - 1) << endl;
    cout << "From 70 to 80 --- " << static_cast<float>(dig[7]) / static_cast<float>(M - 1) << endl;
    cout << "From 80 to 90 --- " << static_cast<float>(dig[8]) / static_cast<float>(M - 1) << endl;
    cout << "From 90 to 100 --- " << static_cast<float>(dig[9]) / static_cast<float>(M - 1) << endl;
}


void fourth(){
    int  A , C , Q, M=1;
    unsigned long first, temp1=0;
    char check;

    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        cout << "Insert the coefficient A and C and Q" << endl;
        cin >> A >> C >> Q ;
    }
    else A = 2, C = 3, Q = 9973;
    first=rand_fourth( A, C, Q);
    while (temp1 != first) { sort_(static_cast<float>(temp1=rand_fourth( A, C, Q)) / static_cast<float>(Q) * 100);
    M++;}
    cout << "From 0 to 10 --- " << static_cast<float>(dig[0]) / static_cast<float>(M-1) << endl;
    cout << "From 10 to 20 --- " << static_cast<float>(dig[1]) / static_cast<float>(M-1) << endl;
    cout << "From 20 to 30 --- " << static_cast<float>(dig[2]) / static_cast<float>(M-1) << endl;
    cout << "From 30 to 40 --- " << static_cast<float>(dig[3]) / static_cast<float>(M-1) << endl;
    cout << "From 40 to 50 --- " << static_cast<float>(dig[4]) / static_cast<float>(M-1) << endl;
    cout << "From 50 to 60 --- " << static_cast<float>(dig[5]) / static_cast<float>(M-1) << endl;
    cout << "From 60 to 70 --- " << static_cast<float>(dig[6]) / static_cast<float>(M-1) << endl;
    cout << "From 70 to 80 --- " << static_cast<float>(dig[7]) / static_cast<float>(M-1) << endl;
    cout << "From 80 to 90 --- " << static_cast<float>(dig[8]) / static_cast<float>(M-1) << endl;
    cout << "From 90 to 100 --- " << static_cast<float>(dig[9]) / static_cast<float>(M-1) << endl;
}
void fifth(){
    int  A1 , C1 , M1  , A , C, M;
    char check;
    unsigned long first, temp;
    cout << "write 'y' if you want to choose params for a first sequence by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        cout << "Insert the coefficient A and C and M( M >1000 )" << endl;
        cin >> A1 >> C1 >> M1 ;
    }
    else A1 = 2, C1 = 666, M1 = 39916801;
    cout << "write 'y' if you want to choose params for a second sequence by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        cout << "Insert the coefficient A and C and M( M >1000 )" << endl;
        cin >> A >> C >> M ;
    }
    else  A = 3, C = 5, M = 9973;
    first= abs_own(rand_first(A1, C1, M1), rand_third(A, C, M));
    while (temp != first) { sort_(static_cast<float>(temp=rand_first(A, C, M)) / static_cast<float>(M) * 100);
        M++;}
}
int main() {

    int type;
    print_menu();
    cin >> type;

    switch (type)
    {   case 1:
            first();
            break;
        case 2:
            second();
            break;
        case 3:
            third();
            break;
        case 4:
            fourth();
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
            break;
        default:
            cout << "Wrong input!!!\nOnly 1-10 requires";
    }

    return 0;
}

#pragma clang diagnostic pop