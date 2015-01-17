#include "ScreneManager.h"

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

    // -------- ランダム生成 --------
    // ランダムデバイスを取得
    random_device rd;
    // メルセンヌツイスター
    random::mt19937 mt(rd());
    // サイコロを定義
    random::uniform_int_distribution<> dice(1, 6);
}

// コンストラクタ
ScreneManager::ScreneManager(){
    // サイコロ用フォント作成
    f_dice = Font(16);
}

// デストラクタ
ScreneManager::~ScreneManager(){

}

// 更新メソッド
void ScreneManager::update(){

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
void ScreneManager::draw(){

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
