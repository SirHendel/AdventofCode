#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    vector<int> Position;
    Position.reserve(10);
    std::ifstream infile("inputfile.txt");
    string line;
    int a =0 ;
    int pos ,median,sum=0;
    int32_t mean = 0, sum_low = 0, sum_up = 0, n;
    getline(infile,line);

    while((pos = line.find(",")) != string::npos)
    {
        Position.push_back(stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);
    }
    Position.push_back(stoi(line));

    sort(Position.begin(), Position.end());

    median = (Position[Position.size() / 2 - 1] + Position[Position.size() / 2]) / 2;

    for(int32_t& num : Position){
        sum += (int32_t)abs(num - median);
    }
    cout << sum << endl;

    for(int32_t& num: Position)
        mean += num;
    mean = mean / 1000;
    
    cout << mean << endl;

    for(int32_t& num: Position)
    {
        n = abs(num - mean);
        sum_low += (n * n + n) / 2;
        n = abs(num - mean + 1);
        sum_up += (n * n + n) / 2;
    }

    cout << (sum_low < sum_up ? sum_low : sum_up) << endl;
    return 0;
}