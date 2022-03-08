#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class uboot{
    private: 
        int up = 0;
        int down = 0;
        int foward = 0;
        int aim = 0;
        int depth = 0;
        int horizontal_position = 0;
    public:
        inline int getup(){ return (up); };
        inline int getdown(){ return (down); };
        inline int getfoward(){ return (foward); };
        inline int getaim(){ return (aim); };
        inline int getdepth(){ return (depth); };
        inline int gethorizontal_position(){ return (horizontal_position); };
        
        inline void setup(int Up){ up=Up; };
        inline void setdown(int Down){ down=Down; };
        inline void setfoward(int Foward){ foward=Foward; };
        inline void setaim(int Aim){ aim=Aim; };
        inline void setdepth(int Depth){ depth=Depth; };
        inline void sethorizontal_position(int Horizontal_position){ horizontal_position=Horizontal_position; };

};

int main(){

    std::string line,Direction;
    std::ifstream infile("inputfile.txt");
    uboot c;
    int a;

    while (std::getline(infile, line))
    {
        std::istringstream iss(line);

        if (!(iss >> Direction >> a)) { 
            break;
        } // error
        switch (Direction[0])
        {
            case 'f' : /* constant-expression */
                c.sethorizontal_position(a+c.gethorizontal_position());
                c.setdepth(c.getdepth() +(a*c.getaim()));
                break;
            case 'd' : /* constant-expression */
                c.setdown(a+c.getdown());
                c.setaim(c.getaim()+a);
                break;
            case 'u' : /* constant-expression */
                c.setup(a+c.getup());
                c.setaim(c.getaim()-a);
                break;
            default:
                break;   
        }
    }
    std::cout<<"Depth :"<<c.getdepth()<<"Foward :"<<c.gethorizontal_position()<<std::endl;
    return 0; 
}