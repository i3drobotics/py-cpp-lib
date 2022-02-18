#include "pyhelper.h"

namespace py = boost::python;
    
template <class T>
py::list PyHelper::toPythonList(std::vector<T> v) {
    typename std::vector<T>::iterator iter;
    py::list list;
    for (iter = v.begin(); iter != v.end(); ++iter) {
        list.append(*iter);
    }
    return list;
}

template <class T>
void PyHelper::toPythonList(std::vector<T> v, py::list* l) {
    typename std::vector<T>::iterator iter;
    for (iter = v.begin(); iter != v.end(); ++iter) {
        l->append(*iter);
    }
}

template <class T>
std::vector<T> PyHelper::toStdVector(py::list l) {
    py::ssize_t n = py::len(l);
    std::cout << "converting list of size: " << n << " to vector" << std::endl;
    std::vector<T> v;
    for(py::ssize_t i=0;i<n;i++) {
        py::object elem = l[i];
        T str = py::extract<T>(elem);
        v.push_back(str);
    }
    return v;
}

template <class T>
void PyHelper::toStdVector(py::list l,std::vector<T>* v) {
    py::ssize_t n = py::len(l);
    std::cout << "converting list of size: " << n << " to vector" << std::endl;
    for(py::ssize_t i=0;i<n;i++) {
        py::object elem = l[i];
        T str = py::extract<T>(elem);
        v->push_back(str);
    }
}

bool PyHelper::hasattr(py::object o, const char* name) {
    return PyObject_HasAttrString(o.ptr(), name);
}

void PyHelper::initPython(){
    try {
        Py_Initialize();
        // Insert the current working directory into the python path so module search is relative
        std::string workingDir = ".";
        PyObject* sysPath = PySys_GetObject("path");
        PyList_Insert( sysPath, 0, PyUnicode_FromString(workingDir.c_str()));
    } catch( py::error_already_set ) {
        PyErr_Print();
    }
}

bool PyHelper::classExists(const char* py_module, const char* py_class){
    try
    {
        py::object main_module((
            py::handle<>(py::borrowed(PyImport_AddModule("__main__")))));

        py::object main_namespace = main_module.attr("__dict__");

        // >>> import *py_module*
        py::object module_obj = py::import(py_module);

        // >>> class_obj = *py_class*
        py::object class_obj = module_obj.attr(py_class)();
        return true;
    }
    catch(py::error_already_set const &)
    {
        return false;
    }
}

py::object PyHelper::initClass(const char* py_module, const char* py_class){
    // for safety 'classExists' should be run before 'initClass'
    py::object main_module((
        py::handle<>(py::borrowed(PyImport_AddModule("__main__")))));

    py::object main_namespace = main_module.attr("__dict__");

    // >>> import *py_module*
    py::object module_obj = py::import(py_module);

    // >>> class_obj = *py_class*
    py::object class_obj = module_obj.attr(py_class)();
    return class_obj;
}