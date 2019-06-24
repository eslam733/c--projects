#include <iostream>
#include "course.h"
#include "t.h"
using namespace std;

int main(){

    course c1(300, 3);
    course c2(201, 4);
    course c3(500, 5);
    t t1;
    t1.addcourse(&c1);
    t1.addcourse(&c2);
    t1.addcourse(&c3);
    t1.printc();
    cout << endl;
    t1.del(&c2);
    t1.printc();
    return 0;
}