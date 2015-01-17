// ================================================================
//  メインシーンのテスト
// ================================================================
#include <Siv3D.hpp>
#include <boost/random.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

// ---------------- グローバル変数 ----------------
namespace{
    // サイコロを投げるフラグ
    dynamic_bitset<> flag_dice(1);
    // サイコロの結果
    int dice_result;
    // 現在のマス
    int now_position = 0;

    // ---------------- ランダム生成 ----------------
    // ランダムデバイスを取得
    random_device rd;
    // メルセンヌツイスター
    random::mt19937 mt(rd());
    // サイコロを定義
    random::uniform_int_distribution<> dice(1, 6);
}

// ================================
//  画面管理クラス
// ================================
class ScreneManager{
private:
    // サイコロのフォント
    Font f_dice;

public:
    // コンストラクタ
    ScreneManager(){
        // サイコロ用フォント作成
        f_dice = Font(16);
    }
    // デストラクタ
    ~ScreneManager(){}

    // 更新メソッド
    void update(){
        // Zキーが押されたならば
        if (Input::KeyZ.clicked){
            // サイコロを投げるフラグをオン
            flag_dice.set(0);
            // サイコロの値を取得
            dice_result = dice(mt);
            // コマを進める
            now_position += dice_result;
        }
    }

    // 描画メソッド
    void draw(){
        // サイコロを投げるフラグがオンなら
        if (flag_dice.test(0)){
            // サイコロを描画
            f_dice(dice_result).draw();
            // 現在のマスを描画
            f_dice(now_position).draw({ 0, 18 });
        }
        else{
            // 最初のメッセージを描画
            f_dice(L"Please press Z key").draw();
        }
    }
};

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

    // ---------------- 変数 ----------------
    // 画面管理ポインタ
    boost::shared_ptr<ScreneManager> screne_manager(new ScreneManager());

    // ---------------- メインループ ----------------
    while (System::Update()){
        // 更新
        screne_manager->update();

        // 描画
        screne_manager->draw();
    }
}
