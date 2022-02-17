#pragma once

#include "pyhelper.h"

class pyHello
{
public:
    pyHello();

    bool isInitalised();

    std::string getMsg();
    bool setMsg(std::string msg);

private:

    const char* py_module_name_ = "hello";
    const char* py_class_name_ = "hello";
    bool py_class_ready_ = false;
    py::object py_class_hello_;

};
