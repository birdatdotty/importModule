#include "ImportLib.h"

bool Import::load(std::string name) {
    if (constructors.find(name) != constructors.end())
        return false;

    fnInit initModule = import(name);
    constructors.insert(std::make_pair(name, initModule));

    return true;
}

ImportLib *Import::build(std::string name) {
    if (constructors.find(name) == constructors.end())
        return nullptr;

    ImportLib* ret;
    (*constructors[name])(&ret);

    return ret;;
}

fnInit Import::import(std::string lib) {
    void *handle;
    //    void* (*init)();
    fnInit init;

    char *error;

    handle = dlopen(lib.c_str(), RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();    /* Очистка всех результатов ошибок */
    init = (fnInit) dlsym(handle, "init");

    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    return init;
}
