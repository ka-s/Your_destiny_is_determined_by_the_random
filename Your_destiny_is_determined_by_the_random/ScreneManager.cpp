#include "ScreneManager.h"

using namespace std;
using namespace boost;

namespace{
    // 定数
    const int GOAL_POSITION = 64;

    // 変数
    dynamic_bitset<> flag_dice(1);
    int dice_result;
    int now_position;
    int now_turn;

    // 乱数
    random_device rd;
    random::mt19937 mt(rd());
    random::uniform_int_distribution<> dice(1, 6);
}

ScreneManager::ScreneManager(){
    // 生成
    player = boost::shared_ptr<Player>(new Player());

    // フォント
    f_dice = Font(16);

    // 初期化
    now_position = 0;
    now_turn = 0;
}

ScreneManager::~ScreneManager(){

}

void ScreneManager::update(){

    throw_dice();
    update_player_data();

}

int ScreneManager::draw(){
    
    // クリア時描画
    if (is_clear()){
        f_dice(
            L"ゴール！",
            L"\nかかったターン数：", now_turn
            ).draw();
        return 0;
    }

    // 通常描画
    if (flag_dice.test(0)){
        f_dice(
            L"現在", now_turn, L"ターン目",
            L"\nサイコロ：", dice_result, 
            L"\n現在", player->get_progress(), L"マス目", 
            L"\nゴールまであと", get_last_goal(player->get_progress()), L"マス").draw();
    }
    else{
        f_dice(L"Please press Z key").draw();
    }

    return 0;
}


int ScreneManager::throw_dice(){

    if (Input::KeyZ.clicked){
        if (is_clear()){
            ScreneManager();

            return 0;
        }

        flag_dice.set(0);
        dice_result = dice(mt);
        now_position += dice_result;
        now_turn += 1;
    }

    return 0;
}

void ScreneManager::update_player_data(){

    player->set_progress(now_position);

}

int ScreneManager::get_last_goal(int now_prg){
    return GOAL_POSITION - now_prg;
}

bool ScreneManager::is_clear(){

    if (get_last_goal(player->get_progress()) < 1){
        return true;
    }
    return false;

}
