#include <iostream>
#include <fstream>
#include <climits>
#include <string>


using namespace std;

int main(int argc, char* argv[]){
    ifstream myInput("input.txt");

    int max = INT_MIN;
    int total = 0;
    int value = 0;
    string sValue;
    while(!myInput.eof()){
        getline(myInput,sValue);
        if (sValue.empty()){
            if (total > max){
                max = total;
            }
            total = 0;
            continue;
        }
        value = stoi(sValue);
        total += value;
    }

    cout << max << endl;

    return 0;
}