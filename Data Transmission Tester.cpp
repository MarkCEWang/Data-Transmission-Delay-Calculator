#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cmath>

using namespace std;


int main(int argc, char *argv[]) {
extern float avg(float item[], int size);
extern float median(float item[], int size);
extern float stdDev(float item[], float a, int size);
extern float aad(float item[], float a, int size);
extern float calcDecay(int bias);

    struct Website {

    string url;
    float length;
    float transmission;
    float priority;


};
    if (argc != 2) {
        cerr << "error" << endl;
        return -1;
    }

    int bias = atoi(argv[1]);
    ifstream infile;
    ofstream outfile;
    string command;
    string line;
    int count = 0;
    Website ws[99999];

    while (cin >> command && command != "exit") {
        infile.open("ece150-proj1-input.txt");
        while (infile >> line) {
            if (line == command) {
                ws[count].url = command;
                infile >> ws[count].length;
                infile >> ws[count].priority;
                ws[count].transmission = (ws[count].length+calcDecay(bias))/1.25;
                count++;
            }
        }
        infile.close();
    }
    float lengthList[count], priorityList[count], transmissionList[count];
    for (int i = 0; i < count; i++) {
        lengthList[i] = ws[i].length;
        priorityList[i] = ws[i].priority;
        transmissionList[i] = ws[i].transmission;
    }
    float average1 = avg(lengthList, count);
    cout << average1 << " ";
    cout << median(lengthList,count) << " ";
    cout << stdDev(lengthList, average1, count) << " ";
    cout << aad(lengthList, average1, count) << " " << endl;
    float average2 = avg(priorityList, count);
    cout << average2 << " ";
    cout << median(priorityList,count) << " ";
    cout << stdDev(priorityList, average2, count) << " ";
    cout << aad(priorityList, average2, count) << " " << endl;
    float average3 = avg(transmissionList, count);
    cout << average3 << " ";
    cout << median(transmissionList,count) << " ";
    cout << stdDev(transmissionList, average3, count) << " ";
    cout << aad(transmissionList, average3, count) << " " << endl;

}
