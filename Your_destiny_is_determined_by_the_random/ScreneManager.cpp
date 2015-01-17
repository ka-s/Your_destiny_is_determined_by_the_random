#include "ScreneManager.h"

using namespace std;
using namespace boost;

// ---------------- �O���[�o���ϐ� ----------------
namespace{
    // �T�C�R���𓊂���t���O
    dynamic_bitset<> flag_dice(1);
    // �T�C�R���̌���
    int dice_result;
    // ���݂̃}�X
    int now_position = 0;

    // -------- �����_������ --------
    // �����_���f�o�C�X���擾
    random_device rd;
    // �����Z���k�c�C�X�^�[
    random::mt19937 mt(rd());
    // �T�C�R�����`
    random::uniform_int_distribution<> dice(1, 6);
}

// �R���X�g���N�^
ScreneManager::ScreneManager(){
    // �T�C�R���p�t�H���g�쐬
    f_dice = Font(16);
}

// �f�X�g���N�^
ScreneManager::~ScreneManager(){

}

// �X�V���\�b�h
void ScreneManager::update(){

    // Z�L�[�������ꂽ�Ȃ��
    if (Input::KeyZ.clicked){
        // �T�C�R���𓊂���t���O���I��
        flag_dice.set(0);
        // �T�C�R���̒l���擾
        dice_result = dice(mt);
        // �R�}��i�߂�
        now_position += dice_result;
    }

}

// �`�惁�\�b�h
void ScreneManager::draw(){

    // �T�C�R���𓊂���t���O���I���Ȃ�
    if (flag_dice.test(0)){
        // �T�C�R����`��
        f_dice(dice_result).draw();
        // ���݂̃}�X��`��
        f_dice(now_position).draw({ 0, 18 });
    }
    else{
        // �ŏ��̃��b�Z�[�W��`��
        f_dice(L"Please press Z key").draw();
    }

}
