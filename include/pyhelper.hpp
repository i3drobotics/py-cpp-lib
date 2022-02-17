#ifndef PYHELPER_HPP
#define PYHELPER_HPP

#define BOOST_PYTHON_STATIC_LIB 
// #define BOOST_NUMPY_STATIC_LIB

#pragma push_macro("slots")
#undef slots
#include <boost/python/detail/wrap_python.hpp>
#pragma pop_macro("slots")

#include <iostream>
#include <boost/python.hpp>
// #include <boost/python/numpy.hpp>

namespace pyhelper
{
    namespace py = boost::python;
    // namespace np = boost::python::numpy;

    template <class T>
    py::list toPythonList(std::vector<T> v) {
        typename std::vector<T>::iterator iter;
        py::list list;
        for (iter = v.begin(); iter != v.end(); ++iter) {
            list.append(*iter);
        }
        return list;
    }
	
	template <class T>
    void toPythonList(std::vector<T> v, py::list* l) {
        typename std::vector<T>::iterator iter;
        for (iter = v.begin(); iter != v.end(); ++iter) {
            l->append(*iter);
        }
    }

    template <class T>
    std::vector<T> toStdVector(py::list l) {
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
    void toStdVector(py::list l,std::vector<T>* v) {
        py::ssize_t n = py::len(l);
		std::cout << "converting list of size: " << n << " to vector" << std::endl;
        for(py::ssize_t i=0;i<n;i++) {
            py::object elem = l[i];
            T str = py::extract<T>(elem);
            v->push_back(str);
        }
    }

    static bool hasattr(py::object o, const char* name) {
        return PyObject_HasAttrString(o.ptr(), name);
    }

    static void initPython(){
        std::wstring pyws1(Py_GetPath());
        std::string pystr1(pyws1.begin(), pyws1.end());
        std::cout << "Python: " << pystr1 << std::endl;
        try {
            Py_Initialize();
            // np::initialize();
        } catch( py::error_already_set ) {
            PyErr_Print();
        }
    }

    static py::object getPyClass(char* py_module, char* py_class){
        py::object main_module((
        py::handle<>(py::borrowed(PyImport_AddModule("__main__")))));

        py::object main_namespace = main_module.attr("__dict__");

        // >>> import *py_module*
        py::object module_obj = py::import(py_module);

        py::object class_obj = module_obj.attr(py_class)();
        return class_obj;
    }
}

#endif //PYHELPER_HPP