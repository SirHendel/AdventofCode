#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int main(){

    std::string line;
    int increased = 0,a[2000],b[2000],c=0;
    std::ifstream infile("inputfile.txt");
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss>>a[c];
        c++;
    }
    for(int n=0;n<1998;n++){
        b[n]=a[n]+a[n+1]+a[n+2];
    }
    for(int i=0;i<1998;i++){
        if(b[i+1]>b[i])
            increased++;
    }
    std::cout<<increased;
}