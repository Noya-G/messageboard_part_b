#include "Board.hpp"

int main() {

    ariel::Board board;
    ariel::board.post(0,0, Direction::Horizontal, "system  programmig b ex 2 part b");
    ariel::board.post(0,1, Direction::Horizontal, "Ariel University");
    ariel::board.post(0,2, Direction::Horizontal, "this code was writen by Noya Gendelman");
    ariel::board.show();

    return 0;
}
