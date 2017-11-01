#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <Halite.hpp>

namespace py = pybind11;

bool quiet_output =
        false; //Need to be passed to a bunch of classes; extern is cleaner.

bool always_log =
        false; //Flag to always log game state (regardless of whether bots are error-ing out)

PYBIND11_MODULE(halite, m) {
    m.doc() = "Halite client as a library";

    py::class_<Halite>(m, "Halite")
            .def(py::init([](unsigned short width_, unsigned short height_, unsigned int seed_, const std::vector<std::string> players_) {
                return new Halite(width_, height_, seed_, players_);
            }))
            .def()

            ;


}