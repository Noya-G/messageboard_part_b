#pragma once
#include <string>
#include "Direction.hpp"
#include <iostream>
#include <map>
#define INITILIZE_SIZE 0

struct default_value{
    char c='_';
};


namespace ariel {
    class Board {
        std::map<unsigned int,std::map<unsigned int,default_value>> board;
        unsigned int min_row, min_column;
        unsigned int max_row, max_column;
    public:
        Board();
        ~Board();
        void post(unsigned int row, unsigned int column, Direction direction, const std::string &message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}
