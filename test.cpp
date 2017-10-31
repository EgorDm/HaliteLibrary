//
// Created by egordm on 31-10-2017.
//

#include <hlt.hpp>
#include "Halite.hpp"


bool quiet_output =
        false; //Need to be passed to a bunch of classes; extern is cleaner.

bool always_log =
        false; //Flag to always log game state (regardless of whether bots are error-ing out)

int main(int argc, char **argv) {
    std::vector<std::string> players = {"Orion", "Proxima"};
    auto game = new Halite(300, 200, 123, players);

    std::cout << game->getMap().ships.at(0).at(0).location << std::endl;

    hlt::Move move{};
    move.type = hlt::MoveType::Thrust;
    move.shipId = 0;
    move.move.thrust.thrust = 7;
    move.move.thrust.angle = 0;
    hlt::entity_map<hlt::Move> moves;
    moves[0] = move;
    game->do_move(0, moves);

    game->step();
    std::cout << game->getMap().ships.at(0).at(0).location << std::endl;
}