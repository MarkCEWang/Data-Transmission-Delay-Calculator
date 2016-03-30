#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cmath>

using namespace std;





float avg(float item[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += item[i];
    }
    return sum/size;
}

float median(float item[], int size) {
    float temp;
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-i-1; j++) {
            temp = item[j];
            item[j] = item[j+1];
            item[j+1] = temp;
        }
    }
    if (size%2 == 1) {
        return item[(size-1)/2];
    }  else {
        return (item[size/2-1]+item[size/2])/2;
    }
}

float stdDev(float item[], float a, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (abs(item[i]-a))*(abs(item[i]-a));
    }
    return sqrt(sum/size);

}

float aad(float item[], float a, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += abs(item[i]-a);
    }
    return sum/size;
}
