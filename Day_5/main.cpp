#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

void bresenham(int x1, int y1, int x2, int y2,  vector<vector<int> >& invector)
{
    int  delta, step_x = 0, step_y = 0;
    
    if(x1 != x2)
    {
        delta = abs(x1 - x2);
        step_x = (x2 - x1)/delta;
    }

    if(y1 != y2)
    {
        delta = abs(y1 - y2);
        step_y = (y2 - y1)/delta;
    }

    for(int i = 0; i <= delta; i++)
    {
        invector[x1][y1]++;
        x1 += step_x;
        y1 += step_y;
    }
}
class Line{
    private:
        int x1 = 0;
        int x2 = 0;
        int y1 = 0;
        int y2 = 0;
    public:
        Line(int X1,int X2,int Y1,int Y2){
            x1=X1;
            x2=X2;
            y1=Y1;
            y2=Y2;
        }
        bool DrawLine(vector<vector<int> >& invector){
            if(x1 > invector.size() && x2 > invector.size() && y1 > invector.size() && y2 > invector.size())
                return false;
            if(x1 == x2 || y1 == y2 ){
                if(x1<x2){
                    for(int i = x1; i<=x2;i++)
                        invector[i][y1]++;
                }
                if(x1>x2){
                    for(int i = x2; i<=x1;i++)
                        invector[i][y1]++;
                }
                if(y1<y2){
                    for(int i = y1; i<=y2;i++)
                        invector[x1][i]++;
                }
                if(y1>y2){
                    for(int i = y2; i<=y1;i++)
                        invector[x1][i]++;
                }
                return true;
            }
            else{
                if(x1<x2 || y1<y2)
                    bresenham(x1,y1,x2,y2,invector);
                else
                    bresenham(x2,y2,x1,y1,invector);
                return true;
            }
            return false;
        }
    friend ostream& operator<<(ostream &out, Line c)
    {
        out << c.x1 << "," << c.y1 << "->" << c.x2 << ","<< c.y2;
        return out;
    }
};



int main(){
    
    vector<Line> Lines;

    string line;
    vector<vector<int> > Spielfeld  (1000, vector<int>(1000, 0));
    ifstream infile("inputfile.txt");
    int x1,x2,y1,y2;
    int i = 0;
    Lines.reserve(1000);

    while (getline(infile, line)){
        istringstream iss(line);
        sscanf(line.c_str(), "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
        Line obj(x1,x2,y1,y2);  // 88,177 -> 566,655
        Lines[i]=obj;
        if(Lines[i].DrawLine(Spielfeld))
            cout<<obj<<endl;
        i++;
    }
    int marks = 0;
    int fieldfalue = 0;
    for(int n=0; n<1000;n++){
        for(int k=0; k<1000;k++){
            if(2 <= Spielfeld[k][n])
                marks++;
            cout<<Spielfeld[k][n]<< " ";
        }
        cout<<endl;
    }
    cout<<marks<<endl;
    return 0;
}