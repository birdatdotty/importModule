#ifndef IMPORTLIB_H
#define IMPORTLIB_H

#include <string>
#include <dlfcn.h>
#include <map>

class ImportLib;
typedef void(*fnInit)(ImportLib**);

//// add like it in your lib:
//extern "C" void init(ImportLib** ret) {
//    *ret = new Module1();
//}


class ImportLib
{
public:
    virtual void testModule() = 0;
};

struct Import {
    bool load(std::string name);
    ImportLib* build(std::string name);

private:
    std::map <std::string,fnInit> constructors;
    fnInit import(std::string lib);
};


#endif // IMPORTLIB_H
