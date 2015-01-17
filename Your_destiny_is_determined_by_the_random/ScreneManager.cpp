#include "ScreneManager.h"

using namespace std;
using namespace boost;

namespace{
    dynamic_bitset<> flag_dice(1);
    int dice_result;
    int now_position = 0;

    random_device rd;
    random::mt19937 mt(rd());
    random::uniform_int_distribution<> dice(1, 6);
}

ScreneManager::ScreneManager(){
    player = boost::shared_ptr<Player>(new Player());

    f_dice = Font(16);
}

ScreneManager::~ScreneManager(){

}

void ScreneManager::update(){

    throw_dice();

    update_player_data();

}

void ScreneManager::draw(){

    if (flag_dice.test(0)){
        f_dice(dice_result).draw();
        f_dice(player->get_progress()).draw({ 0, 18 });
    }
    else{
        f_dice(L"Please press Z key").draw();
    }

}


void ScreneManager::throw_dice(){

    if (Input::KeyZ.clicked){
        flag_dice.set(0);
        dice_result = dice(mt);
        now_position += dice_result;
    }

}

void ScreneManager::update_player_data(){

    player->set_progress(now_position);

}
