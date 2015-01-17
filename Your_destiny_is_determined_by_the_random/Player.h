#pragma once

#include <Siv3D.hpp>
#include "Const.h"

// ================================
//  �v���C���[�N���X
// ================================
class Player{
private:
    // ���W
    Pos pos;
    // ���݂̃}�X
    int progress;

public:
    // �R���X�g���N�^
    Player();
    // �f�X�g���N�^
    ~Player();

    // �擾���\�b�h
    Pos get_pos();
    int get_progress();

    // �ݒ胁�\�b�h
    void set_pos(Pos new_pos);
    void set_progress(int new_progress);
};
