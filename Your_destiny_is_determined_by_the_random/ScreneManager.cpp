#include "ScreneManager.h"

using namespace std;
using namespace boost;

namespace{
    // �萔
    const int GOAL_POSITION = 64;

    // �ϐ�
    dynamic_bitset<> flag_dice(1);
    int dice_result;
    int now_position;
    int now_turn;

    // ����
    random_device rd;
    random::mt19937 mt(rd());
    random::uniform_int_distribution<> dice(1, 6);
}

ScreneManager::ScreneManager(){
    // ����
    player = boost::shared_ptr<Player>(new Player());

    // �t�H���g
    f_dice = Font(16);

    // ������
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
    
    // �N���A���`��
    if (is_clear()){
        f_dice(
            L"�S�[���I",
            L"\n���������^�[�����F", now_turn
            ).draw();
        return 0;
    }

    // �ʏ�`��
    if (flag_dice.test(0)){
        f_dice(
            L"����", now_turn, L"�^�[����",
            L"\n�T�C�R���F", dice_result, 
            L"\n����", player->get_progress(), L"�}�X��", 
            L"\n�S�[���܂ł���", get_last_goal(player->get_progress()), L"�}�X").draw();
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
