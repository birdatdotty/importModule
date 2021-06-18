#include "module1.h"

#include <stdio.h>
#include <iostream>

using namespace std;

extern "C" void init(ImportLib** ret) {
    *ret = new Module1();
}

Module1::Module1()
{
}

void Module1::testModule()
{
    cout << "void Module1::testModule()" << endl;
}
