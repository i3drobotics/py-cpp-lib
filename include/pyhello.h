#pragma once

#include "export.h"
#include "pyhelper.h"

class PyHello
{
public:
    PyHello();

    bool isInitalised();

    std::string getMsg();
    bool setMsg(std::string msg);

private:

    const char* py_module_name_ = "hello";
    const char* py_class_name_ = "hello";
    bool py_class_ready_ = false;
    py::object py_class_hello_;

};

extern "C" {
    PyHello DLL_EXPORT * PyHello_create();
    void PyHello_test();
    void DLL_EXPORT PyHello_dispose(PyHello* instance);
}
