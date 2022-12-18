#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

// int main(int argc, char* argv[]){
//     ifstream myInput("input.txt");

//     int max = INT_MIN;
//     int total = 0;
//     int value = 0;
//     string sValue;
//     while(!myInput.eof()){
//         getline(myInput,sValue);
//         if (sValue.empty()){                         Code that would complete Part I
//             if (total > max){
//                 max = total;
//             }
//             total = 0;
//             continue;
//         }
//         value = stoi(sValue);
//         total += value;
//     }

//     cout << max << endl;

//     return 0;
// }


int main(int argc, char* argv[]){
    ifstream myInput("input.txt");

    int total = 0;
    int value = 0;
    string sValue;
    vector <int> topThree;
    for (int i = 0;i<3;i++){
        getline(myInput,sValue);
        topThree.push_back(stoi(sValue));
        //cout << topThree[i] << endl;
    }

    std::sort(topThree.begin(),topThree.end());
    while(!myInput.eof()){
        getline(myInput,sValue);
        if (sValue.empty()){
            int lowest = -1;
            for (int i = 0;i<3;i++){
                
                if(total > topThree[i]){
                    topThree[i] = total;
                    break;
                }
            }
            total = 0;
            sort(topThree.begin(),topThree.end());
            continue;
        }
        value = stoi(sValue);
        total += value;
    }
    int bigTotal = 0;
    for (int i = 0;i<3;i++){
        bigTotal += topThree[i];
        cout << topThree[i] << endl;
    }


    cout << bigTotal << endl;
    return 0;
}