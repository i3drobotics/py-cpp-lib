#pragma once

#define BOOST_PYTHON_STATIC_LIB 
// #define BOOST_NUMPY_STATIC_LIB

// #pragma push_macro("slots")
// #undef slots
// #include <boost/python/detail/wrap_python.hpp>
// #pragma pop_macro("slots")

#include <iostream> // cout
#include <cstdlib> // setenv
#include <boost/python.hpp>
// #include <boost/python/numpy.hpp>

namespace py = boost::python;
// namespace np = boost::python::numpy;

class pyHelper
{
public:
    
    template <class T>
    static py::list toPythonList(std::vector<T> v);
	
	template <class T>
    static void toPythonList(std::vector<T> v, py::list* l);

    template <class T>
    static std::vector<T> toStdVector(py::list l);
	
	template <class T>
    static void toStdVector(py::list l,std::vector<T>* v);
    
    static bool hasattr(py::object o, const char* name);

    static void initPython();

    static bool classExists(const char* py_module, const char* py_class);

    static py::object initClass(const char* py_module, const char* py_class);
};
