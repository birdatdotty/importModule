#include <ImportLib.h>

int main()
{
    Import import;
    import.load("libmodule1.so");
    import.load("libmodule2.so");
    ImportLib* testModule11 = import.build("libmodule1.so");
    ImportLib* testModule22 = import.build("libmodule2.so");

    puts("___test__without__subdir___");
    testModule11->testModule();
    testModule22->testModule();
    puts("___test__without__subdir___");


    return EXIT_SUCCESS;
}
