#ifndef PYHELLO_HPP_
#define PYHELLO_HPP_

#include "pyhelper.hpp"

namespace pyh = pyhelper;

class pyHello
{
public:
    pyHello(): py_class_name_("hello"), py_module_ready_(false)
    {
        /* hello.__init__() */
        py_class_hello_ = pyh::getPyClass(py_class_name_, py_class_name_);
        py_module_ready_ = true;
        if (!py_module_ready_){
            std::cerr << "Failed initalise " << py_class_name_ << " python module" << std::endl;
        } else {
            std::cout << "Successfully initalised " << py_class_name_ << " python module" << std::endl;
        }
    }

    bool isInitalised(){
        return py_module_ready_;
    }

    bool printMsg(){
        /* hello.printMsg() -> bool */
        if (py_module_ready_){
            char* py_func_name = "printMsg";
            if (pyh::hasattr(py_class_hello_, py_func_name)){
                pyh::py::object return_obj = py_class_hello_.attr(py_func_name)();
                bool ret = pyh::py::extract<bool>(return_obj);
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

    std::string getMsg(){
        /* hello.getMsg() -> str */
        if (py_module_ready_){
            char* py_func_name = "getMsg";
            if (pyh::hasattr(py_class_hello_, py_func_name)){
                pyh::py::object return_obj = py_class_hello_.attr(py_func_name)();
                std::string ret = pyh::py::extract<std::string>(return_obj);
                return ret;
            } else {
                std::cerr << "Failed find function '"<< py_func_name << "' in '"<< py_class_name_ << "' class" << std::endl;
                return "";
            }
        } else {
            std::cerr << "'" << py_class_name_ << "' python module is not initalised" << std::endl;
            return "";
        }
    }

    bool setMsg(std::string msg){
        /* hello.setMsg(msg: str) -> bool */
        if (py_module_ready_){
            char* py_func_name = "setMsg";
            if (pyh::hasattr(py_class_hello_, py_func_name)){
                pyh::py::object return_obj = py_class_hello_.attr(py_func_name)(msg);
                bool ret = pyh::py::extract<bool>(return_obj);
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

private:

    bool py_module_ready_;
    char* py_class_name_;
    pyh::py::object py_class_hello_;

};

#endif /* PYHELLO_HPP_ */