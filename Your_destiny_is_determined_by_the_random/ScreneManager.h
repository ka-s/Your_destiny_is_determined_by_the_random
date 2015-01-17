#pragma once

#include <Siv3D.hpp>
#include <boost/random.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <boost/foreach.hpp>
#include "Player.h"

// ================================
//  ��ʊǗ��N���X
// ================================
class ScreneManager{
private:
    // �v���C���[
    boost::array<boost::shared_ptr<Player>, 2> player;

    // �T�C�R���̃t�H���g
    Font f_dice;

public:
    // �R���X�g���N�^
    ScreneManager();
    // �f�X�g���N�^
    ~ScreneManager();

    // �X�V���\�b�h
    void update();
    // �`�惁�\�b�h
    int draw();

    // �T�C�R���𓊂��郁�\�b�h
    int throw_dice();
    // �v���C���[�����X�V���郁�\�b�h
    void update_player_data();

    // �S�[���܂ł��Ƃǂꂭ�炢���v�Z���郁�\�b�h
    int get_last_goal(int now_prg);
    // �S�[�����胁�\�b�h
    bool is_clear();
};
