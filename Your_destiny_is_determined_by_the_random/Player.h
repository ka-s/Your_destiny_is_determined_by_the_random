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

};
