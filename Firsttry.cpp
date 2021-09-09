
#include <iostream>
using namespace std;
unsigned const short A = 4;
unsigned const short C = 7;
const unsigned long M = 21474836;
int dig[10] = {0};


int inc_dig(unsigned short i){
    dig[i]++;
    return 0;
}
void sort_(double temp) {
    if (temp >= 0 && temp < 10) {
        inc_dig(1);
    } else if (temp >= 10 && temp < 20) {
        inc_dig(2);
    } else if (temp >= 20 && temp < 30) {
        inc_dig(3);
    } else if (temp >= 30 && temp < 40) {
        inc_dig(4);
    } else if (temp >= 40 && temp < 50) {
        inc_dig(5);
    } else if (temp >= 50 && temp < 60) {
        inc_dig(6);
    } else if (temp >= 60 && temp < 70) {
        inc_dig(7);
    } else if (temp >= 70 && temp < 80) {
        inc_dig(8);
    } else if (temp >= 80 && temp < 90) {
        inc_dig(9);
    } else {
        inc_dig(10);
    }
}


int rand_()
{
    static int prev = 1;
    prev = (A*prev+C) % M;
    return prev;
}

int main()
{
    for (int i = 0; i < 10000; i++) { sort_(static_cast<double>(rand_()) / M * 100); }
    cout  <<"From 0 to 10 --- " << static_cast<float>(dig[1])/10000  <<  endl;
    cout  <<"From 10 to 20 --- " << static_cast<float>(dig[2]) / 10000 <<  endl;
    cout  <<"From 20 to 30 --- "<< static_cast<float>(dig[3]) / 10000 <<  endl;
    cout  <<"From 30 to 40 --- " << static_cast<float>(dig[4]) / 10000 <<  endl;
    cout  <<"From 40 to 50 --- " << static_cast<float>(dig[5]) / 10000 <<  endl;
    cout  <<"From 50 to 60 --- " << static_cast<float>(dig[6]) / 10000 <<  endl;
    cout  <<"From 60 to 70 --- " << static_cast<float>(dig[7]) / 10000 <<  endl;
    cout  <<"From 70 to 80 --- " << static_cast<float>(dig[8]) / 10000 <<  endl;
    cout  <<"From 80 to 90 --- " << static_cast<float>(dig[9]) / 10000 <<  endl;
    cout  <<"From 90 to 100 --- " << static_cast<float>(dig[10]) / 10000 <<  endl;
    return 0;
}

