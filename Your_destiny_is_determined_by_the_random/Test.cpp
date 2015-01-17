// ================================================================
//  ���C���V�[���̃e�X�g
// ================================================================
#include <Siv3D.hpp>
#include <random>
#include <bitset>

using namespace std;

// --------------------------------
//  ���C���֐�
// --------------------------------
void Main(){

    // ---------------- �E�B���h�E��� ----------------
    // �w�i�F
    Graphics::SetBackground(Palette::Black);
    // �E�B���h�E�^�C�g��
    Window::SetTitle(L"Game make test");
    // �E�B���h�E�T�C�Y
    Window::Resize(1024, 768);
    // �E�B���h�E�𒆐S�ɃZ�b�g
    Window::Centering();

    // ---------------- �����_������ ----------------
    // �����_���f�o�C�X���擾
    random_device rd;
    // �����Z���k�c�C�X�^�[
    mt19937 mt(rd());
    // �T�C�R�����`
    uniform_int_distribution<int> dice(1, 6);

    // ---------------- �ϐ� ----------------
    // �T�C�R���̃t�H���g
    Font f_dice(16);
    // �T�C�R���𓊂���t���O
    bitset<1> flag_dice;
    // �T�C�R���̌���
    int dice_result;

    while (System::Update()){

        // Z�L�[�������ꂽ�Ȃ��
        if (Input::KeyZ.clicked){
            // �T�C�R���𓊂���t���O���I��
            flag_dice.at(0) = true;
            // �T�C�R���̒l���擾
            dice_result = dice(mt);
        }

        // �T�C�R���𓊂���t���O���I���Ȃ�
        if (flag_dice.at(0)){
            // �T�C�R����`��
            f_dice(dice_result).draw();
        }
        else{
            // �ŏ��̃��b�Z�[�W��`��
            f_dice(L"Please press Z key").draw();
        }

    }
}
