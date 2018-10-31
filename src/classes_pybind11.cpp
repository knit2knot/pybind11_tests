#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include "CppClasses.hpp"

PYBIND11_PLUGIN(orcFile) {

    py::module m("ClassBinding", "python binding");
    py::class_<Base>(m,"Base")
        .def(py::init<>)
        .def("virtualFunction", &Base::virtualFunction)
        .def("publicFunction", &Base::publicFunction)
        .def("virtualPrivateFunction", &Base::virtualPrivateFunction);
        
    
    py::class_<Derived, Base>(m,"Derived")
        .def(py::init<>)
        .def("virtualFunction", &Derived::virtualFunction)
        .def("publicFunction", &Derived::publicFunction)
        .def("virtualPrivateFunction", &Derived::virtualPrivateFunction);




    

    return m.ptr();
}