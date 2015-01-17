#pragma once

#include <Siv3D.hpp>
#include <boost/random.hpp>
#include <boost/dynamic_bitset.hpp>

// ================================
//  画面管理クラス
// ================================
class ScreneManager{
private:
    // サイコロのフォント
    Font f_dice;

public:
    // コンストラクタ
    ScreneManager();
    // デストラクタ
    ~ScreneManager();

    // 更新メソッド
    void update();
    // 描画メソッド
    void draw();
};
