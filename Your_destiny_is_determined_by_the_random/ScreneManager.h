#pragma once

#include <Siv3D.hpp>
#include <boost/random.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/shared_ptr.hpp>
#include "Player.h"

// ================================
//  ��ʊǗ��N���X
// ================================
class ScreneManager{
private:
    // �v���C���[
    boost::shared_ptr<Player> player;

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
    void draw();

    // �T�C�R���𓊂��郁�\�b�h
    void throw_dice();
    // �v���C���[�����X�V���郁�\�b�h
    void update_player_data();
};
