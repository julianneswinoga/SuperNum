#include <iostream>
#include "SuperNum.h"

using namespace std;

int main()
{
    SuperNum sn1 {"2"};
    SuperNum sn2 {"102"};
    SuperNum sn3 = sn1 * 8;
    sn3.print();
    return 0;
}
