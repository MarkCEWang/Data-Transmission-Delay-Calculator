#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cmath>

using namespace std;



float calcDecay(int bias) {
    srand(time(NULL));
    double variability = pow(2.0, (double)(bias));
    float r = (float)(rand()%(1+2*(int)variability)-(int)variability);
    return r;
}
