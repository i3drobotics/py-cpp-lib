#include "pyhello.h"

int main(int argc, char *argv[])
{
    pyHelper::initPython();   
    pyHello pyhello = pyHello();
    std::cout << pyhello.getMsg() << std::endl;

    return 0;
}