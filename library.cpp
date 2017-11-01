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

    py::class_<hlt::Planet>(m, "Planet")
            .def_readonly("owner", &hlt::Planet::owner)
            .def_readonly("owned", &hlt::Planet::owned)
            .def_readonly("remaining_production", &hlt::Planet::remaining_production)
            .def_readonly("current_production", &hlt::Planet::current_production)
            .def_readonly("docking_spots", &hlt::Planet::docking_spots)
            .def_readonly("docked_ships", &hlt::Planet::docked_ships);

    py::class_<hlt::Ship>(m, "Ship")
            .def_readonly("velocity", &hlt::Ship::velocity)
            .def_readonly("weapon_cooldown", &hlt::Ship::weapon_cooldown)
            .def_readonly("docking_status", &hlt::Ship::docking_status)
            .def_readonly("docking_progress", &hlt::Ship::docking_progress)
            .def_readonly("docked_planet", &hlt::Ship::docked_planet);

    py::class_<hlt::Velocity>(m, "Velocity")
            .def_readonly("vel_x", &hlt::Velocity::vel_x)
            .def_readonly("vel_y", &hlt::Velocity::vel_y);

    py::enum_<hlt::DockingStatus>(m, "DockingStatus")
            .value("Undocked", hlt::DockingStatus::Undocked)
            .value("Docking", hlt::DockingStatus::Docking)
            .value("Docked", hlt::DockingStatus::Docked)
            .value("Undocking", hlt::DockingStatus::Undocking)
            .export_values();

    py::class_<hlt::Map>(m, "Map")
            .def_readonly("ships", &hlt::Map::ships)
            .def_readonly("planets", &hlt::Map::planets)
            .def_readonly("map_width", &hlt::Map::map_width)
            .def_readonly("map_height", &hlt::Map::map_height);

    py::class_<Halite>(m, "Halite")
            .def(py::init([](unsigned short width_, unsigned short height_, unsigned int seed_, const std::vector<std::string> players_) {
                return new Halite(width_, height_, seed_, players_);
            }))
            .def("do_move", &Halite::do_move)
            .def("step", &Halite::step)
            .def("finish", &Halite::finish)
            .def("game_ended", &Halite::game_ended)
            .def("save_replay", &Halite::save_replay)
            .def("get_name", &Halite::get_name)
            .def("get_constants", &Halite::get_constants);


}