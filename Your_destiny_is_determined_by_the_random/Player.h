#pragma once

#include <Siv3D.hpp>
#include "Const.h"

// ================================
//  プレイヤークラス
// ================================
class Player{
private:
    // 座標
    Pos pos;
    // 現在のマス
    int progress;

public:
    // コンストラクタ
    Player();
    // デストラクタ
    ~Player();

    // 取得メソッド
    Pos get_pos();
    int get_progress();

    // 設定メソッド
    void set_pos(Pos new_pos);
    void set_progress(int new_progress);
};
