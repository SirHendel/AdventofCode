#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string numbers[10] = {"abcefg","cf","acdeg","acdfg","bcdf","abdfg","abdefg","acf","abcdefg","abdcfg"};

bool isShuffledSubstring(string A, string B)
{
    int n = A.length();
    int m = B.length();
 
    // Return false if length of
    // string A is greater than
    // length of string B
    if (n > m) {
        return false;
    }
    else {
 
        // Sort string A
        sort(A.begin(), A.end());
 
        // Traverse string B
        for (int i = 0; i < m; i++) {
 
            // Return false if (i+n-1 >= m)
            // doesn't satisfy
            if (i + n - 1 >= m)
                return false;
 
            // Initialise the new string
            string str = "";
 
            // Copy the characters of
            // string B in str till
            // length n
            for (int j = 0; j < n; j++)
                str.push_back(B[i + j]);
 
            // Sort the string str
            sort(str.begin(), str.end());
 
            // Return true if sorted
            // string of "str" & sorted
            // string of "A" are equal
            if (str == A)
                return true;
        }
    }
}


int main(){
    
    vector <string> Datafront;
    vector <string> Databack;
    std::ifstream infile("inputfile2.txt");
    string line;
    int pos = 0;
    int sum = 0;
    while(getline(infile,line)){
        while((pos = line.find(" ")) != string::npos)
        {
            Datafront.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        Databack.push_back(line);
        /*while((pos = line.find(" ")) != string::npos)
        {

            Databack.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
            cout<<line<<" "; 
            for(int n = 0; n<Databack.size();n++){
                if(isShuffledSubstring(Datafront[i],Databack[n]) || isShuffledSubstring(Datafront[i],Databack[n]) || isShuffledSubstring(Datafront[i],Databack[n])){
                sum++;
            }
        } 
        }*/
        
    }
    
    for(int n = 0; n<10; n++){
        for(int i = 10; i< 15; i++){
            if(isShuffledSubstring(Datafront[i+n*15],numbers[1])){
                sum++;
                //cout<<Datafront[i+n*10]<<" "<<endl;
            }
            cout<<Datafront[i+n*15]<<" ";
        }
        cout<<endl;
    }
    
    cout<<sum<<endl;
    return 0;
}