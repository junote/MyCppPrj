#include <string>
#include <pybind11/pybind11.h>
#include "BaseClass.h"
#include "MyDev.h"
namespace py = pybind11;


PYBIND11_MODULE(MyDev, m) {
    py::class_<BaseBus>(m, "BaseBus")
        .def(py::init<>());
    py::class_<MyBus>(m, "MyBus")
        .def(py::init<>())
        .def("read8", &MyBus::read8)  
        .def("read16", &MyBus::read16)   
        .def("read32", &MyBus::read32);   
    py::class_<BaseDev>(m, "BaseDev")
        .def(py::init<BaseBus*>());    
    py::class_<MyDev8,BaseDev>(m, "MyDev8")
        .def(py::init<MyBus*>())
        .def("read", py::overload_cast<uint8>(&BaseDev::read));
    py::class_<MyDev16>(m, "MyDev16")
        .def(py::init<MyBus*>())
        .def("read", &MyDev16::read);
    py::class_<MyDev32,BaseDev>(m, "MyDev32")
        .def(py::init<MyBus*>())
        .def("read", py::overload_cast<uint32>(&BaseDev::read));
}