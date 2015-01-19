// ================================================================
//  メインシーンのテスト
// ================================================================
#include <Siv3D.hpp>
#include <boost/shared_ptr.hpp>
#include "ScreneManager.h"

using namespace std;
using namespace boost;

// --------------------------------
//  メイン関数
// --------------------------------
void Main(){
    // ---------------- ウィンドウ情報 ----------------
    // 背景色
    Graphics::SetBackground(Palette::Black);
    // ウィンドウタイトル
    Window::SetTitle(L"Game make test");
    // ウィンドウサイズ
    Window::Resize(1024, 576);
    // ウィンドウを中心にセット
    Window::Centering();

    // ---------------- 変数 ----------------
    // 画面管理クラスのポインタ
    boost::shared_ptr<ScreneManager> screne_manager(new ScreneManager());

    // ---------------- メインループ ----------------
    while (System::Update()){
        // 更新
        screne_manager->update();

        // 描画
        screne_manager->draw();
    }
}
