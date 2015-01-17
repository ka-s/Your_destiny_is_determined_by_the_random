#include "ScreneManager.h"

using namespace std;
using namespace boost;

namespace{
    // �萔
    const int GOAL_POSITION = 64;

    // �ϐ�
    // TODO : �v���C���[�l���ɂ���
    dynamic_bitset<> flag_dice(2);
    boost::array<int, PLAYER_NUM> dice_result;
    boost::array<int, PLAYER_NUM> now_position;
    int now_turn;

    // ����
    random_device rd;
    random::mt19937 mt(rd());
    random::uniform_int_distribution<> dice(1, 6);
}

// --------------------------------
//  �R���X�g���N�^
// --------------------------------
ScreneManager::ScreneManager(){
    // ����
    for (int i = 0; i < PLAYER_NUM; ++i){
        player.at(i) = boost::shared_ptr<Player>(new Player());
    }

    // �t�H���g
    f_dice = Font(16);

    // ������
    for(int i = 0; i < PLAYER_NUM; ++i){
        now_position.at(i) = 0;
        dice_result.at(i) = 0;
    }
    now_turn = 0;
}

// --------------------------------
//  �f�X�g���N�^
// --------------------------------
ScreneManager::~ScreneManager(){

}

// --------------------------------
//  �X�V
// --------------------------------
void ScreneManager::update(){

    throw_dice();
    update_player_data();

}

// --------------------------------
//  �`��
// --------------------------------
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
    for (int i = 0; i < PLAYER_NUM; ++i){
        if (flag_dice.test(0)){
            f_dice(
                L"����", now_turn, L"�^�[����",
                L"\n�T�C�R���F", dice_result.at(i),
                L"\n����", player.at(i)->get_progress(), L"�}�X��",
                L"\n�S�[���܂ł���", get_last_goal(player.at(i)->get_progress()), L"�}�X").draw({ 300 * i, 0 });
        }
        else{
            f_dice(L"Please press Z key").draw();
        }
    }

    return 0;
}

// --------------------------------
//  �T�C�R���𓊂���
// --------------------------------
int ScreneManager::throw_dice(){
    static int dice_count = 0;

    if (Input::KeyZ.clicked){
        if (is_clear()){
            ScreneManager();
            dice_count = 0;

            return 0;
        }

        int who_turn = dice_count % PLAYER_NUM;
        switch (who_turn){
        case 0:
            // TODO : ���\�b�h��
            move_on_one_player_dice(who_turn);
            now_turn += 1;
            break;
        case 1:
            move_on_one_player_dice(who_turn);
            break;
        }

        dice_count++;
    }

    return 0;
}

// --------------------------------
//  �v���C���[���X�V
// --------------------------------
void ScreneManager::update_player_data(){

    for (int i = 0; i < PLAYER_NUM; ++i){
        player.at(i)->set_progress(now_position.at(i));
    }

}

// --------------------------------
//  �v���C���[���Ƃ̏���
// --------------------------------
void ScreneManager::move_on_one_player_dice(int now_turn){
    flag_dice.set(now_turn);
    dice_result.at(now_turn) = dice(mt);
    now_position.at(now_turn) += dice_result.at(now_turn);
}


// --------------------------------
//  �S�[���܂ł��Ƃǂꂭ�炢���v�Z
// --------------------------------
int ScreneManager::get_last_goal(int now_prg){
    return GOAL_POSITION - now_prg;
}

// --------------------------------
//  �S�[������
// --------------------------------
bool ScreneManager::is_clear(){

    for (int i = 0; i < PLAYER_NUM; ++i){
        if (get_last_goal(player.at(i)->get_progress()) < 1){
            return true;
        }
    }

    return false;

}
