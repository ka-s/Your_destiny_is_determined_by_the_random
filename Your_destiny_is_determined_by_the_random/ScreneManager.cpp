#include "ScreneManager.h"

using namespace std;
using namespace boost;

namespace{
    const int GOAL_POSITION = 64;

    dynamic_bitset<> flag_dice(1);
    int dice_result;
    int now_position;
    int now_turn;

    random_device rd;
    random::mt19937 mt(rd());
    random::uniform_int_distribution<> dice(1, 6);
}

ScreneManager::ScreneManager(){
    player = boost::shared_ptr<Player>(new Player());

    f_dice = Font(16);

    now_position = 0;
    now_turn = 0;
}

ScreneManager::~ScreneManager(){

}

void ScreneManager::update(){

    throw_dice();
    update_player_data();

}

void ScreneManager::draw(){

    if (flag_dice.test(0)){
        f_dice(
            L"現在", now_turn, L"ターン目",
            L"\nサイコロ：", dice_result, 
            L"\n現在", player->get_progress(), L"マス目", 
            L"\nゴールまであと", GOAL_POSITION - player->get_progress(), L"マス").draw();
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
        now_turn += 1;
    }

}

void ScreneManager::update_player_data(){

    player->set_progress(now_position);

}
