#include "module2.h"

#include <stdio.h>
#include <iostream>

using namespace std;

extern "C" void init(ImportLib** ret) {
    *ret = new Module2();
}

Module2::Module2()
{
}

void Module2::testModule()
{
    cout << "void Module2::testModule()" << endl;
}
