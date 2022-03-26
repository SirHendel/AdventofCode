#include <iostream> 
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


class lanterfish{
    private:
        uint8_t daystillborn;
    public:
        lanterfish(){
            daystillborn = 9;
        }
        lanterfish(int Daystillborn){
            daystillborn = Daystillborn;
        }
        inline int getDaystillborn(){ return this->daystillborn; }
        inline void setDaystillborn(int Daystillborn){ this->daystillborn=Daystillborn; }
        void doDay( std::vector<lanterfish> &swarm){
            if(this->daystillborn == 0){
                lanterfish fish;
                swarm.push_back(fish);
                this->daystillborn = 7;
            }
            this->daystillborn = this->daystillborn-1;
            return;
        }
};

int main(){

    std::vector<lanterfish> swarm;
    lanterfish fish;
    std::ifstream infile("inputfile.txt");
    swarm.reserve(2147400000);
    char line;
    int a =0 ;
    while(infile.get(line)){
            if(line != ','){
                fish.setDaystillborn(static_cast<int>(line-'0'));
                swarm.push_back(fish);
                a++;
            }
    }

    for(int n = 0;n < 80;n++){
        for(uint64_t i = 0; i < swarm.size();i++){
            swarm[i].doDay(swarm);
        }
    }
    std::cout<<swarm.size()<<std::endl;
    return 0;
}