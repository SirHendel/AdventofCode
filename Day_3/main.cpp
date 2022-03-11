#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>

int count(int n, std::vector<std::string> &str, int bit) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i][bit] == '1') count++;
        else count--;
    }
    return count;
}

int main (){
    std::string number;
    std::ifstream fd("inputfile.txt");
    
    std::vector<std::string> oxy, co;

    while (fd >> number) {
        oxy.push_back(number);
        co.push_back(number);
    }

    int n = number.size();
    int m = oxy.size();

    int gamma = 0, epsilon = 0;
    for (int i = 0; i < n; i++) {
        if (count(m, oxy, i) > 0) gamma += pow(2, n-1-i);
        else epsilon += pow(2, n-1-i);
    }

    for (int i = 0; i < n; i++) {
        int m = oxy.size();
        int currCount = count(m, oxy, i);

        for (int j = 0; j < m; j++) {
            if (oxy.size() == 1) {
                i = n;
                break;
            }
            if (currCount >= 0){
                if (oxy[j][i] == '0') {
                    oxy.erase(oxy.begin()+j);
                    j--;
                    m--;
                }
            }
            else {
                if (oxy[j][i] == '1') {
                    oxy.erase(oxy.begin()+j);
                    j--;
                    m--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int m = co.size();
        int currCount = count(m, co, i);

        for (int j = 0; j < m; j++) {
            if (co.size() == 1) {
                i = n;
                break;
            }

            if (currCount < 0){
                if (co[j][i] == '0') {
                    co.erase(co.begin()+j);
                    j--;
                    m--;
                }
            }
            else {
                if (co[j][i] == '1') {
                    co.erase(co.begin()+j);
                    j--;
                    m--;
                }
            }
        }
    }

    int oxygen = 0, co2 = 0;
    for (int i = 0; i < n; i++) {
        if (oxy[0][i] == '1') oxygen += pow(2, n-1-i);
        if (co[0][i] == '1') co2 += pow(2, n-1-i);
    }
    

    std::cout <<"Star 1: " <<gamma * epsilon <<std::endl
              <<"Star 2: " <<oxygen * co2<<std::endl;
}
/*#include <fstream>
#include <string>
#include <iostream>

class bit{
    private:
    int gammarate_1 = 0;
    int gammarate_0 = 0;
    int gammarate = 0;
    int epsilonrate_1 = 0;
    int epsilonrate_0 = 0;
    public:
    inline void incgammarate_1(){ gammarate_1++; };
    inline void incgammarate_0(){ gammarate_0++; };
    inline void incepsilonrate_1(){ epsilonrate_1++; };
    inline void incepsilonrate_0(){ epsilonrate_0++; };
    inline void setgammarate(int Gammarate){ gammarate=Gammarate;};
    inline int getgammarate(){return gammarate;};
    inline int getgammarate_1(){return gammarate_1;};
    inline int getgammarate_0(){return gammarate_0;};
    inline int getepsilonrate_1(){return epsilonrate_1;};
    inline int getepsilonrate_0(){return epsilonrate_0;};
};


int main(){

    std::ifstream infile("inputfile.txt");
    std::string line;
    bit c[12];
/*    while (std::getline(infile, line))
    {
        for(int i = 0; i< line.length();i++){
            if(line[i] == '1'){
                c[i].incepsilonrate_0();
                c[i].incgammarate_1();
            }
            if(line[i] == '0'){
                c[i].incepsilonrate_1();
                c[i].incgammarate_0();
            }  
        }
    }
    for(int i = 0; i<12;i++){
        if(c[i].getgammarate_1() <c[i].getgammarate_0()){
            c[i].setgammarate(0);
        }
        if(c[i].getgammarate_0() <c[i].getgammarate_1()){
            c[i].setgammarate(1);
        }
    }
    bool correctline = true;
    for(int g=0;g<12;g++){
        infile.clear();
        infile.seekg(0);
        while (std::getline(infile, line))
        {
            correctline = true;
            for(int h=0;h<=g;h++){
                if((c[g-h].getgammarate() == 0 && '0' == (line[g-h])) || (c[g-h].getgammarate()== 1 && '1' == (line[g-h]))){
                    correctline = false;
                }
            }
            if(correctline == true){
                if(line[g+1] == '1'){
                    c[g+1].incepsilonrate_0();
                    c[g+1].incgammarate_1();
                }
                else if(line[g+1] == '0'){
                    c[g+1].incepsilonrate_1();
                    c[g+1].incgammarate_0();
                }
                
                for(int i = 0; i<=g+1;i++){
                    if(c[i].getepsilonrate_1() <c[i].getepsilonrate_0()){
                        c[i].setgammarate(0);
                    }
                    else if(c[i].getepsilonrate_0() <c[i].getepsilonrate_1()){
                        c[i].setgammarate(1);
                    }
                }
                
                std::cout<<line<<"\t"<<g<<c[g-1].getgammarate()<<std::endl;
            }
        }
         std::cout<<"\t"<<g<<std::endl;
         std::cout<<std::endl;
    }
    return 0; // alles okay
}*/