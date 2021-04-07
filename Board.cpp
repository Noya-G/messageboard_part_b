#include "Board.hpp"


namespace ariel {

    Board::~Board() {
        this->board.erase(this->board.begin(),this->board.end());
    }
    
    Board::Board(){
        //begin indexes.
        min_row=INITILIZE_SIZE;
        min_column=INITILIZE_SIZE;
        //end indexes.
        max_row=INITILIZE_SIZE;
        max_column=INITILIZE_SIZE;
    }

    void Board::post(unsigned int row, unsigned int column, Direction direction, const std::string &message)
    {
        unsigned int msg_len=message.length();


        switch (direction)
        {
            case Direction::Horizontal:

                //---------check & update board max size-----------
                if(this->max_row<row){
                        this->max_row=row;
                }
                if(this->max_column<(column+msg_len)){
                        this->max_column=column+msg_len;
                }

                //---------check & update board min size-----------
                if (this->min_column>column){
                        this->min_column=column;
                }
                if (this->min_row>row){
                        this->min_row=row;
                }

                //----------post the message-----------------------
                for(unsigned int i=0 ;i<msg_len;i++){ // write the message
                    this->board[row][column].c = message[i];
                    column++;
                }
                break;
            
            case Direction::Vertical:

                //---------check & update board max size-----------
                if (this->max_row<(row+msg_len)){
                        this->max_row=row+msg_len;
                }
                if (this->max_column<column){
                        this->max_column=column;
                }

                //---------check & update board min size-----------
                if (this->min_column>column){
                        this->min_column=column;
                }
                if (this->min_row>row){
                        this->min_row=row;
                }

                //----------post the message-----------------------
                for(unsigned int i=0 ;i<msg_len;i++){
                    this->board[row][column].c = message[i];
                    row++;
                }
                break;
            }
    }

    std::string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) 
    {
        std::string ans;
        unsigned int row_index = row;
        unsigned int column_index= column;

        //-------------------------------------------------
        // --------------------get the meassge-------------
        //-------------------------------------------------
        switch (direction)
        {
        case Direction::Horizontal:
            for(unsigned int i=0; i<length; i++){
                ans += this->board[row][column_index].c;
                column_index++;
            }
            break;
        
        case Direction::Vertical:
            for(unsigned int i=0; i<length; i++){
                ans += this->board[row_index][column].c;
                row_index++;
            }
            break;
        }
        return ans;
    }

    void Board::show()
    {
        std::string ans;

        //-------------------------------------------------
        //---------------stream out the board---------------
        //-------------------------------------------------
        for (uint i = this->min_row; i < this->max_row; i++) {
            for (uint j = this->min_column; j < this->max_column; j++) {
                ans += this->board[i][j].c;
            }
             ans += "\n";
        }
        std::cout <<ans;
    }

}
