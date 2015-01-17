#pragma once

#include <Siv3D.hpp>
#include <boost/random.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <boost/foreach.hpp>
#include "Player.h"

// ================================
//  画面管理クラス
// ================================
class ScreneManager{
private:
    // プレイヤー
    boost::array<boost::shared_ptr<Player>, 2> player;

    // サイコロのフォント
    Font f_dice;

    // サイコロを投げるメソッド
    int throw_dice();
    // プレイヤー情報を更新するメソッド
    void update_player_data();
    // プレイヤー1人のサイコロを投げるメソッド
    void move_on_one_player_dice(int now_turn);

    // ゴールまであとどれくらいか計算するメソッド
    int get_last_goal(int now_prg);
    // ゴール判定メソッド
    bool is_clear();

public:
    // コンストラクタ
    ScreneManager();
    // デストラクタ
    ~ScreneManager();

    // 更新メソッド
    void update();
    // 描画メソッド
    int draw();
};
