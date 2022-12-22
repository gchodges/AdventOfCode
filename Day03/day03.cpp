#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    // ifstream input("input.txt");

    // int total = 0;
    // int currIt = 0;

    // while(1){
    //     string currElf;
    //     input >> currElf;
    //     if (input.eof()) break;
    //     unordered_set <char> sectOne;
    //     unordered_set <char> duplicates;
    //     for (int c = 0;c<currElf.size();c++){
    //         if (c < (currElf.size()/2)){
    //             if (sectOne.find(currElf[c]) == sectOne.end()) sectOne.insert(currElf[c]);
    //         }
    //         else{
    //             if (sectOne.find(currElf[c]) != sectOne.end()){
    //                 if(currElf[c] >= 'a' && currElf[c] <= 'z' && (duplicates.find(currElf[c])== duplicates.end())){
    //                     total += currElf[c] - 'a'  + 1;
    //                     duplicates.insert(currElf[c]);
    //                     cout << "Found a duplicate " << currElf[c] << endl;
    //                 }
    //                 else{
    //                     if((duplicates.find(currElf[c])== duplicates.end()))
    //                         total += currElf[c] - 'A'  + 27;
    //                         duplicates.insert(currElf[c]);
    //                         cout << "Found a duplicate " << currElf[c] << endl;
    //                 }
    //             }
    //         }
    //     }
    // }

    ifstream input("input.txt");

    int total = 0;
    int currIt = 0;

    while(1){
        if (input.eof()) break;
        string elfOneS, elfTwoS, elfThreeS;
        input >> elfOneS >> elfTwoS >> elfThreeS;
        
        unordered_set <char> elfOne;
        unordered_set <char> elfTwo;
        for (int c = 0;c<elfOneS.size();c++){
            if (elfOne.find(elfOneS[c]) == elfOne.end()){
                elfOne.insert(elfOneS[c]);
            }
            
        }
        for (int c = 0;c<elfTwoS.size();c++){
            if (elfTwo.find(elfTwoS[c]) == elfTwo.end()){
                elfTwo.insert(elfTwoS[c]);
            }
        }
        for (int c = 0;c<elfThreeS.size();c++){
            if ((elfTwo.find(elfThreeS[c]) != elfTwo.end()) && (elfOne.find(elfThreeS[c]) != elfOne.end())){
                if(elfThreeS[c] >= 'a' && elfThreeS[c] <= 'z'){
                        total += elfThreeS[c] - 'a'  + 1;
                        break;
                    }
                else{
                        total += elfThreeS[c] - 'A'  + 27;
                        break;
                    }
            }
        }
    }
    

    cout  << total << endl;

    return 0;
}