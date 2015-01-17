// ================================================================
//  ���C���V�[���̃e�X�g
// ================================================================
#include <Siv3D.hpp>
#include <boost/random.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/shared_ptr.hpp>

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

    // ---------------- �����_������ ----------------
    // �����_���f�o�C�X���擾
    random_device rd;
    // �����Z���k�c�C�X�^�[
    random::mt19937 mt(rd());
    // �T�C�R�����`
    random::uniform_int_distribution<> dice(1, 6);
}

// ================================
//  ��ʊǗ��N���X
// ================================
class ScreneManager{
private:
    // �T�C�R���̃t�H���g
    Font f_dice;

public:
    // �R���X�g���N�^
    ScreneManager(){
        // �T�C�R���p�t�H���g�쐬
        f_dice = Font(16);
    }
    // �f�X�g���N�^
    ~ScreneManager(){}

    // �X�V���\�b�h
    void update(){
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
    void draw(){
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
};

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

    // ---------------- �ϐ� ----------------
    // ��ʊǗ��|�C���^
    boost::shared_ptr<ScreneManager> screne_manager(new ScreneManager());

    // ---------------- ���C�����[�v ----------------
    while (System::Update()){
        // �X�V
        screne_manager->update();

        // �`��
        screne_manager->draw();
    }
}
