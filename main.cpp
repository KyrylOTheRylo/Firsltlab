#define _USE_MATH_DEFINES 
#include <iostream>
#include <string>
#include <cmath>
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
    } else if (temp >= 90 && temp < 100) {
        inc_dig(9);
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
bool coprime(int a, int b) {

    if (gcd(a, b) == 1)
        return 1;
    else
        return 0;
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
    prev=(preprev + prev) % M;
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
int getOperator1(int& A , int& C, int& M)
{
    int tempA, tempC, tempM;
    while (true) 
    {
        cout << "Insert the coefficient A and C and M( M >1000 )";
        cin >> tempA >> tempC >> tempM;



        if (coprime(tempC, tempM)) {
            if (tempM < 1000) {
                cout << "Oops, that input is invalid. M must be > 1000" << endl;
            }
            else {
                if (tempA > 0 && tempC > 0) {
                    A = tempA;
                    C = tempC;
                    M = tempM;
                    return A;
                }
                else
                    cout << "Oops, that input is invalid." << endl;
            }
           
        }
        else 
            cout << "Oops, that input is invalid.C isn's comprime with M\n";
    }
}
void first(){
    int   A = 2, C = 666, M = 784981;
    char check;
    
    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        getOperator1(A, C ,M);
        }
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
int getOperator2(int& D, int& A, int& C, int& M)
{
    int tempD,tempA, tempC, tempM;
    while (true)
    {
        cout << "Insert the coefficient D, A and C and M( M >1000 )";
        cin >> tempD >> tempA >> tempC >> tempM;

        if (coprime(tempC, tempM)) {
            if ((tempM % 3 ==0) && (tempD%9==3*tempC % 9) ) {
                cout << "Oops, that input is invalid. D must be != 3*c mod 9" << endl;
            }
            else if ((tempM % 4 == 0) && ((tempD % 2 == 1) || (tempD % 4 != (tempA - 1) % 4))) {
                cout << "Oops, that input is invalid. D is odd-numbered or D mod 4 != (A - 1) mod 4 " << endl;
            }
            else if ((tempM % 2 == 0) && (tempD % 2 != (tempA - 1) % 2)) {
                cout << "Oops, that input is invalid.  D mod 2 != (A - 1) mod 2 " << endl;
            }
            else {
                D = tempD;
                A = tempA;
                C = tempC;
                M = tempM;
                return A;
            }
        }
        else
            cout << "Oops, that input is invalid.C isn's comprime with M\n";
    }
}
void second(){
    int D = 60, A = 110, C = 3111, M = 784981;
    char  check;

    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        getOperator2(D, A, C, M);
    }

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
    int A = 3, C = 5, M = 9973;
    char check;
    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        cout << "Insert the coefficient A and C and M( M >1000 )" << endl;
        cin >> A >> C >> M ;
    }
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



bool isPrime(int n)
{
    bool temp=true;
    if (n <= 1)
        temp= false;
    if (n <= 3)
        temp= true;

    if (n % 2 == 0 || n % 3 == 0)
        temp= false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            temp= false;
    return temp;
}
int getOperator3(int& A, int& C, int& Q)
{
    int tempA, tempC, tempQ;
    while (true)
    {
        cout << "Insert the coefficient A and C and Q( Q is prime )";
        cin >> tempA >> tempC >> tempQ;
        if (isPrime(tempQ) == false) {
            cout << "Oops, that input is invalid. Q isn't prime" << endl;
        }
        else {
            A = tempA;
            C = tempC;
            Q = tempQ;
            return A;
        }
    }
}
void fourth(){
    int  A = 5, C = 6, Q = 9973, M=1;
    unsigned long first, temp1=0;
    char check;

    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        getOperator3(A,C,Q);
    }
    first=rand_fourth( A, C, Q);
    sort_(first);
    while ((temp1 != first)&& (M < 100000000) ) { sort_(static_cast<float>(temp1=rand_fourth( A, C, Q)) / static_cast<float>(Q) * 100);
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
int rand_fifth(int A1, int C1, int A, int C, int M) {
    long temp = rand_first(A1, C1, M) - rand_third(A, C, M);
    if (temp % M < 0) {
        temp = temp + M;
    }
    return temp;

}
void fifth(){
    int  A1 = 4, C1 = 333, A = 13, C = 21, M = 9973,T=10001;
    char check;
    long first, temp=0;
    cout << "write 'y' if you want to choose params for a first sequence by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        getOperator1(A1, C1, M);
    }
    cout << "write 'y' if you want to choose params for a second sequence by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        cout << "Insert the coefficient A and C " << endl;
        cin >> A >> C  ;
    } 
    first = rand_fifth(A1, C1, A, C, M);
    sort_(first / (M - 1) * 100);
    for (int i = 1; i < T; i++) {
        sort_(static_cast<float>(rand_fifth(A1, C1, A, C, M)) / (M - 1) * 100);
    }
    cout << "From 0 to 10 --- " << static_cast<float>(dig[0]) / static_cast<float>(T - 1) << endl;
    cout << "From 10 to 20 --- " << static_cast<float>(dig[1]) / static_cast<float>(T - 1) << endl;
    cout << "From 20 to 30 --- " << static_cast<float>(dig[2]) / static_cast<float>(T - 1) << endl;
    cout << "From 30 to 40 --- " << static_cast<float>(dig[3]) / static_cast<float>(T - 1) << endl;
    cout << "From 40 to 50 --- " << static_cast<float>(dig[4]) / static_cast<float>(T - 1) << endl;
    cout << "From 50 to 60 --- " << static_cast<float>(dig[5]) / static_cast<float>(T - 1) << endl;
    cout << "From 60 to 70 --- " << static_cast<float>(dig[6]) / static_cast<float>(T - 1) << endl;
    cout << "From 70 to 80 --- " << static_cast<float>(dig[7]) / static_cast<float>(T - 1) << endl;
    cout << "From 80 to 90 --- " << static_cast<float>(dig[8]) / static_cast<float>(T - 1) << endl;
    cout << "From 90 to 100 --- " << static_cast<float>(dig[9]) / static_cast<float>(T - 1) << endl;
}unsigned long rand_six1(int A, int C, int M)
{
    static unsigned long prev = C, preprev = A;
    
    unsigned long temp;
    temp = prev;
    prev = (preprev + prev) % M;
    preprev = temp;
    return prev;
}
float rand_six(int A, int C, int M)
{
    float temp = 0;
    static int first=A, second = C;
    temp = (static_cast<float>(first)/(M - 1));
    temp += (static_cast<float>(second) / (M - 1));
    for (int i=1; i < 9; i++) {
        temp+=static_cast<float>(rand_six1(A, C, M))/(M-1);
    }
    first = rand_six1(A, C, M);
    temp += (static_cast<float>(first) / (M - 1));
    second = rand_six1(A, C, M);
    temp += (static_cast<float>(second) / (M - 1));
    return temp;
}
void sort1_(float temp) {
    if (temp >= -3 && temp < -2.4) {
        inc_dig(0);
    }
    else if (temp >= -2.4 && temp < -1.8) {
        inc_dig(1);
    }
    else if (temp >= -1.8 && temp < -1.2) {
        inc_dig(2);
    }
    else if (temp >= -1.2 && temp < -0.6) {
        inc_dig(3);
    }
    else if (temp >= -0.6 && temp < 0) {
        inc_dig(4);
    }
    else if (temp >= 0 && temp < 0.6) {
        inc_dig(5);
    }
    else if (temp >= 0.6 && temp < 1.2) {
        inc_dig(6);
    }
    else if (temp >= 1.2 && temp < 1.8) {
        inc_dig(7);
    }
    else if (temp >= 1.8 && temp < 2.4) {
        inc_dig(8);
    }
    else if (temp >= 2.4 && temp <= 3) {
        inc_dig(9);
    }
}
void six() {
    float one;
    long x1=0, x2=5, M= 9973,T=10000;
    for (int i = 1; i < T; i++) {
        sort1_(rand_six(x1, x2, M)-6);
    }
    cout << "From -3.0 to -2.4 --- " << static_cast<float>(dig[0]) / static_cast<float>(T - 1) << endl;
    cout << "From -2.4 to -1.8 --- " << static_cast<float>(dig[1]) / static_cast<float>(T - 1) << endl;
    cout << "From -1.8 to -1.2 --- " << static_cast<float>(dig[2]) / static_cast<float>(T - 1) << endl;
    cout << "From -1.2 to -0.6 --- " << static_cast<float>(dig[3]) / static_cast<float>(T - 1) << endl;
    cout << "From -0.6 to 0.00 --- " << static_cast<float>(dig[4]) / static_cast<float>(T - 1) << endl;
    cout << "From 0.00 to 0.60 --- " << static_cast<float>(dig[5]) / static_cast<float>(T - 1) << endl;
    cout << "From 0.60 to 1.20 --- " << static_cast<float>(dig[6]) / static_cast<float>(T - 1) << endl;
    cout << "From 1.20 to 1.80 --- " << static_cast<float>(dig[7]) / static_cast<float>(T - 1) << endl;
    cout << "From 1.80 to 2.40 --- " << static_cast<float>(dig[8]) / static_cast<float>(T - 1) << endl;
    cout << "From 2.40 to 3.00 --- " << static_cast<float>(dig[9]) / static_cast<float>(T - 1) << endl;



}
float rand_seven_first(int A,int B,int M) {
    float temp;
    temp = 2 * (static_cast<float>(rand_first(A, B, M)) / (M - 1)) - 1;
    return temp;
}
float rand_seven_second(int A, int B, int M) {
    float temp;
    temp = 2 * (static_cast<float>(rand_third(A, B, M)) / (M - 1)) - 1;
    return temp;
}
void rand_seven(int A, int B, int C, int D, int M) {
    float X1, X2, sum ;

    X1 = rand_seven_first(A, B, M);
    X2 = rand_seven_second(C, D, M);
    sum = X1 * X1 + X2 * X2;
    if ( sum >= 1) {
        
        rand_seven(A, B, C, D, M);
    }
    else {
        sort1_(X1 * sqrt(-2 * log(sum) / sum));
        sort1_(X2 * sqrt(-2 * log(sum) / sum));
    }
}

void seven() {
    int A=2, B=563, M=9973, C=2, D=3,T=10001;
    for (int i=1; i < T; i++) {
        rand_seven(A, B, C, D, M);
    }
    cout << "From -3.0 to -2.4 --- " << static_cast<float>(dig[0]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From -2.4 to -1.8 --- " << static_cast<float>(dig[1]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From -1.8 to -1.2 --- " << static_cast<float>(dig[2]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From -1.2 to -0.6 --- " << static_cast<float>(dig[3]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From -0.6 to 0.00 --- " << static_cast<float>(dig[4]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From 0.00 to 0.60 --- " << static_cast<float>(dig[5]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From 0.60 to 1.20 --- " << static_cast<float>(dig[6]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From 1.20 to 1.80 --- " << static_cast<float>(dig[7]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From 1.80 to 2.40 --- " << static_cast<float>(dig[8]) / static_cast<float>(T - 1)/2 << endl;
    cout << "From 2.40 to 3.00 --- " << static_cast<float>(dig[9]) / static_cast<float>(T - 1)/2 << endl;

}
float rand_eight(int A, int B, int C, int D, int M) {
    float X1, X2, sum;
    X1 = (static_cast<float>(rand_first(A, B, M))/(M-1));
    X2 = (static_cast<float>(rand_six1(C, D, M))/(M-1));
    
    if (X1 != 0) {
        float temp,temp1, temp2, temp3;
        sum = (static_cast<float>(sqrt(8 / exp(1))) * (X2 - static_cast<float>(0.5)) / (static_cast<float>(X1)));
        temp = sum * sum;
        if (temp<= static_cast<float>(5.0) - (static_cast<float>(4.0) * static_cast<float>(exp(0.25))) * X1) {

            return sum;
        }
        else if (temp >= (static_cast<float>(4.0) * static_cast<float>(exp(-1.35)) / X1) + (static_cast<float>(1.40))) {
            rand_eight(A,B,C,D,M);
        }
        else if (temp <= (static_cast<float>(4.0) * static_cast<float>(log(X1)))) {
            return sum;
        }
        else rand_eight(A, B, C, D, M);
    }
    else rand_eight(A, B, C, D, M);
}
void eight() {
    int A = 2, B = 563, M = 9973, C = 2, D = 3, T = 10001;
    for (int i = 1; i < T; i++) {
        sort1_(rand_eight(A, B, C, D, M));
    }
    cout << "From -3.0 to -2.4 --- " << static_cast<float>(dig[0]) / static_cast<float>(T - 1)  << endl;
    cout << "From -2.4 to -1.8 --- " << static_cast<float>(dig[1]) / static_cast<float>(T - 1)  << endl;
    cout << "From -1.8 to -1.2 --- " << static_cast<float>(dig[2]) / static_cast<float>(T - 1)  << endl;
    cout << "From -1.2 to -0.6 --- " << static_cast<float>(dig[3]) / static_cast<float>(T - 1)  << endl;
    cout << "From -0.6 to 0.00 --- " << static_cast<float>(dig[4]) / static_cast<float>(T - 1)  << endl;
    cout << "From 0.00 to 0.60 --- " << static_cast<float>(dig[5]) / static_cast<float>(T - 1)  << endl;
    cout << "From 0.60 to 1.20 --- " << static_cast<float>(dig[6]) / static_cast<float>(T - 1)  << endl;
    cout << "From 1.20 to 1.80 --- " << static_cast<float>(dig[7]) / static_cast<float>(T - 1)  << endl;
    cout << "From 1.80 to 2.40 --- " << static_cast<float>(dig[8]) / static_cast<float>(T - 1)  << endl;
    cout << "From 2.40 to 3.00 --- " << static_cast<float>(dig[9]) / static_cast<float>(T - 1)  << endl;
}
float rand_ninth(int A, int B, int M, float mu) {
    float temp;
    temp = -mu*log(static_cast<float>(rand_first(A, B, M)) / (M - 1));
    return temp;
}
float getOperator9(float& mu)
{
    int tempmu;
    while (true)
    {
        cout << "Insert the coefficient mu: ";
        cin >> tempmu;

        if (tempmu < 0) {
            cout << "Wrong input mu < 0";
        }
        else mu = tempmu;
        return mu;
    }
}
void ninth() {
    int A = 2, B = 563, M = 9973,T =10001;
    float mu = 25;
    char check;
    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        getOperator9(mu);

    }
    for (int i = 1; i < T; i++) {
        sort_(rand_ninth(A, B, M, mu));
    }
    cout << "From 0 to 10 --- " << static_cast<float>(dig[0]) / static_cast<float>(T - 1) << endl;
    cout << "From 10 to 20 --- " << static_cast<float>(dig[1]) / static_cast<float>(T - 1) << endl;
    cout << "From 20 to 30 --- " << static_cast<float>(dig[2]) / static_cast<float>(T - 1) << endl;
    cout << "From 30 to 40 --- " << static_cast<float>(dig[3]) / static_cast<float>(T - 1) << endl;
    cout << "From 40 to 50 --- " << static_cast<float>(dig[4]) / static_cast<float>(T - 1) << endl;
    cout << "From 50 to 60 --- " << static_cast<float>(dig[5]) / static_cast<float>(T - 1) << endl;
    cout << "From 60 to 70 --- " << static_cast<float>(dig[6]) / static_cast<float>(T - 1) << endl;
    cout << "From 70 to 80 --- " << static_cast<float>(dig[7]) / static_cast<float>(T - 1) << endl;
    cout << "From 80 to 90 --- " << static_cast<float>(dig[8]) / static_cast<float>(T - 1) << endl;
    cout << "From 90 to 100 --- " << static_cast<float>(dig[9]) / static_cast<float>(T - 1) << endl;
}
float rand_tenth(int A, int B, int M, float c) {
    float temp, temp1;
    temp1 = tan(M_PI* (static_cast<float>(rand_first(A,B,M)) / static_cast<float>(M-1)));
    temp = sqrt(2 * c - 1) * temp1 + c - 1;
    if (temp <= 0) { rand_tenth(A, B, M, c)/(M-1); }
    else if (static_cast<float>(rand_third(A, B, M))/(M-1) > ((1 + temp1 * temp1) * exp((c - 1) * log(temp / (c - 1)))) - (sqrt(2 * c - 1) * temp1))
    {
        rand_tenth(A, B, M, c);
    }
    else return temp;
}
int getOperator10(int& c)
{
    int tempc;
    while (true)
    {
        cout << "Insert the coefficient c: ";
        cin >> tempc;

        if (tempc < 1) {
            cout << "Wrong input c < 1";
        }
        else c = tempc;
        return c;
    }
}

void tenth() {
    int A = 2, B = 563, M = 9973, T = 10001,c=15;
    int X1 = 13, X2 = 21;
    char check;
    cout << "write 'y' if you want to choose params by yourself" << endl;
    cin >> check;
    if (check == 'y') {
        getOperator10(c);
       
    }
    for (int i=1; i < 5; i++) {
        rand_six1(X1, X2, M);
    }
    for (int i = 1; i < T; i++) {
        sort_(rand_tenth(A, B, M, c));
    }
    cout << "From 0 to 10 --- " << static_cast<float>(dig[0]) / static_cast<float>(T - 1) << endl;
    cout << "From 10 to 20 --- " << static_cast<float>(dig[1]) / static_cast<float>(T - 1) << endl;
    cout << "From 20 to 30 --- " << static_cast<float>(dig[2]) / static_cast<float>(T - 1) << endl;
    cout << "From 30 to 40 --- " << static_cast<float>(dig[3]) / static_cast<float>(T - 1) << endl;
    cout << "From 40 to 50 --- " << static_cast<float>(dig[4]) / static_cast<float>(T - 1) << endl;
    cout << "From 50 to 60 --- " << static_cast<float>(dig[5]) / static_cast<float>(T - 1) << endl;
    cout << "From 60 to 70 --- " << static_cast<float>(dig[6]) / static_cast<float>(T - 1) << endl;
    cout << "From 70 to 80 --- " << static_cast<float>(dig[7]) / static_cast<float>(T - 1) << endl;
    cout << "From 80 to 90 --- " << static_cast<float>(dig[8]) / static_cast<float>(T - 1) << endl;
    cout << "From 90 to 100 --- " << static_cast<float>(dig[9]) / static_cast<float>(T - 1) << endl;

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
            fifth();
            break;
        case 6:
            six();
            break;
        case 7:
            seven();
            break;
        case 8:
            eight();
            break;
        case 9:
            ninth();
            break;
        case 10:
            tenth();
            break;
        default:
            cout << "Wrong input!!!\nOnly 1-10 requires";
    }

    return 0;
}
