#pragma once

#include <Siv3D.hpp>
#include <boost/random.hpp>
#include <boost/dynamic_bitset.hpp>

// ================================
//  ��ʊǗ��N���X
// ================================
class ScreneManager{
private:
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
};
