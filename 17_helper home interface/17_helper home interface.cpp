#include <iostream>
#include "SmartRemote.h"
int main()
{
    TV tv;
    SmartRemote remote(&tv);

    remote.testDevice();
}
