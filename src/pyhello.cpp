#include "pyhello.h"

PyHello::PyHello()
{
    /* import hello */
    if (!PyHelper::classExists(py_module_name_, py_class_name_)){
        std::cerr << "Failed initalise " << py_class_name_ << ". Likely due to missing python script." << std::endl;
        return;
    }
    py_class_hello_ = PyHelper::initClass(py_module_name_, py_class_name_);
    py_class_ready_ = true;
}

bool PyHello::isInitalised(){
    return py_class_ready_;
}

std::string PyHello::getMsg(){
    /* hello.getMsg() -> str */
    if (isInitalised()){
        const char* py_func_name = "getMsg";
        if (PyHelper::hasattr(py_class_hello_, py_func_name)){
            py::object return_obj = py_class_hello_.attr(py_func_name)();
            std::string ret = py::extract<std::string>(return_obj);
            return ret;
        } else {
            std::cerr << "Failed find function '"<< py_func_name << "' in '"<< py_class_name_ << "' class" << std::endl;
            return "";
        }
    } else {
        std::cerr << "'" << py_class_name_ << "' is not initalised" << std::endl;
        return "";
    }
}

bool PyHello::setMsg(std::string msg){
    /* hello.setMsg(msg: str) -> bool */
    if (isInitalised()){
        const char* py_func_name = "setMsg";
        if (PyHelper::hasattr(py_class_hello_, py_func_name)){
            py::object return_obj = py_class_hello_.attr(py_func_name)(msg);
            bool ret = py::extract<bool>(return_obj);
            return ret;
        } else {
            std::cerr << "Failed find function '"<< py_func_name << "' in '"<< py_class_name_ << "' class" << std::endl;
            return false;
        }
    } else {
        std::cerr << "'" << py_class_name_ << "' python module is not initalised" << std::endl;
        return false;
    }
}

/* --- dll export functions --- */

PyHello * PyHello_create(){
    return new PyHello();
}

void PyHello_test(){
    std::cout << "PyHello_test()" << std::endl;
}

void PyHello_dispose(PyHello* instance){
    if(instance != NULL)
    {
        delete instance;
        instance = NULL;
    }
}