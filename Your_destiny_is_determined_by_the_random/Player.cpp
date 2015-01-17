#include "Player.h"

Player::Player(){
    pos = { 0, 0, 0 };
    progress = 1;
}

Player::~Player(){

}

Pos Player::get_pos(){
    return pos;
}

int Player::get_progress(){
    return progress;
}

void Player::set_pos(Pos new_pos){
    pos = new_pos;
}

void Player::set_progress(int new_progress){
    progress = new_progress;
}
