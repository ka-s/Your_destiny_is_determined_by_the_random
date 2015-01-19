// ================================================================
//  ���C���V�[���̃e�X�g
// ================================================================
#include <Siv3D.hpp>
#include <boost/shared_ptr.hpp>
#include "ScreneManager.h"

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
    Window::Resize(1024, 576);
    // �E�B���h�E�𒆐S�ɃZ�b�g
    Window::Centering();

    // ---------------- �ϐ� ----------------
    // ��ʊǗ��N���X�̃|�C���^
    boost::shared_ptr<ScreneManager> screne_manager(new ScreneManager());

    // ---------------- ���C�����[�v ----------------
    while (System::Update()){
        // �X�V
        screne_manager->update();

        // �`��
        screne_manager->draw();
    }
}
