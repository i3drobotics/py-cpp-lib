#include "pyhello.h"

int main(int argc, char *argv[])
{
    PyHelper::initPython();   
    PyHello pyhello = PyHello();
    std::cout << pyhello.getMsg() << std::endl;

    return 0;
}