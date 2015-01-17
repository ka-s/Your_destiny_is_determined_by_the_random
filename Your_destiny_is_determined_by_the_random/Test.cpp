// ================================================================
//  メインシーンのテスト
// ================================================================
#include <Siv3D.hpp>
#include <random>
#include <bitset>

using namespace std;

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
    Window::Resize(1024, 768);
    // ウィンドウを中心にセット
    Window::Centering();

    // ---------------- ランダム生成 ----------------
    // ランダムデバイスを取得
    random_device rd;
    // メルセンヌツイスター
    mt19937 mt(rd());
    // サイコロを定義
    uniform_int_distribution<int> dice(1, 6);

    // ---------------- 変数 ----------------
    // サイコロのフォント
    Font f_dice(16);
    // サイコロを投げるフラグ
    bitset<1> flag_dice;
    // サイコロの結果
    int dice_result;

    while (System::Update()){

        // Zキーが押されたならば
        if (Input::KeyZ.clicked){
            // サイコロを投げるフラグをオン
            flag_dice.at(0) = true;
            // サイコロの値を取得
            dice_result = dice(mt);
        }

        // サイコロを投げるフラグがオンなら
        if (flag_dice.at(0)){
            // サイコロを描画
            f_dice(dice_result).draw();
        }
        else{
            // 最初のメッセージを描画
            f_dice(L"Please press Z key").draw();
        }

    }
}
