#include <iostream>
using namespace std;

class course
{
     int code;
     int hours;
public:
    course(int c, int h)
    {

        set(c,h);
        
       
    }
    void set(int c, int h){
        code = c;
        hours = h;
    }
    void print()
    {
        cout << code << endl;
    }
};

