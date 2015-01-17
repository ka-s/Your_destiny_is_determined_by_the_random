// ================================================================
//  ���C���V�[���̃e�X�g
// ================================================================
#include <Siv3D.hpp>
#include <boost/random.hpp>
#include <boost/dynamic_bitset.hpp>

using namespace std;
using namespace boost;

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
    random::mt19937 mt(rd());
    // �T�C�R�����`
    random::uniform_int_distribution<> dice(1, 6);

    // ---------------- �ϐ� ----------------
    // �T�C�R���̃t�H���g
    Font f_dice(16);
    // �T�C�R���𓊂���t���O
    dynamic_bitset<> flag_dice(1);
    // �T�C�R���̌���
    int dice_result;
    // ���݂̃}�X
    int now_position = 0;

    // ---------------- ���C�����[�v ----------------
    while (System::Update()){

        // Z�L�[�������ꂽ�Ȃ��
        if (Input::KeyZ.clicked){
            // �T�C�R���𓊂���t���O���I��
            flag_dice.set(0);
            // �T�C�R���̒l���擾
            dice_result = dice(mt);
            // �R�}��i�߂�
            now_position += dice_result;
        }

        // �T�C�R���𓊂���t���O���I���Ȃ�
        if (flag_dice.test(0)){
            // �T�C�R����`��
            f_dice(dice_result).draw();
            // ���݂̃}�X��`��
            f_dice(now_position).draw({0, 18});
        }
        else{
            // �ŏ��̃��b�Z�[�W��`��
            f_dice(L"Please press Z key").draw();
        }

    }
}
