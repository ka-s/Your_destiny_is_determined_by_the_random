#include "ScreneManager.h"

using namespace std;
using namespace boost;

namespace{
    // 定数
    const int GOAL_POSITION = 64;

    // 変数
    // TODO : プレイヤー人数にする
    dynamic_bitset<> flag_dice(2);
    boost::array<int, PLAYER_NUM> dice_result;
    boost::array<int, PLAYER_NUM> now_position;
    int now_turn;

    // 乱数
    random_device rd;
    random::mt19937 mt(rd());
    random::uniform_int_distribution<> dice(1, 6);
}

// --------------------------------
//  コンストラクタ
// --------------------------------
ScreneManager::ScreneManager(){
    // 生成
    for (int i = 0; i < PLAYER_NUM; ++i){
        player.at(i) = boost::shared_ptr<Player>(new Player());
    }

    // フォント
    f_dice = Font(16);

    // 初期化
    for(int i = 0; i < PLAYER_NUM; ++i){
        now_position.at(i) = 0;
        dice_result.at(i) = 0;
    }
    now_turn = 0;
}

// --------------------------------
//  デストラクタ
// --------------------------------
ScreneManager::~ScreneManager(){

}

// --------------------------------
//  更新
// --------------------------------
void ScreneManager::update(){

    throw_dice();
    update_player_data();

}

// --------------------------------
//  描画
// --------------------------------
int ScreneManager::draw(){

    // クリア時描画
    if (is_clear()){
        f_dice(
            L"ゴール！",
            L"\nかかったターン数：", now_turn
            ).draw();
        return 0;
    }

    // 通常描画
    for (int i = 0; i < PLAYER_NUM; ++i){
        if (flag_dice.test(0)){
            f_dice(
                L"現在", now_turn, L"ターン目",
                L"\nサイコロ：", dice_result.at(i),
                L"\n現在", player.at(i)->get_progress(), L"マス目",
                L"\nゴールまであと", get_last_goal(player.at(i)->get_progress()), L"マス").draw({ 300 * i, 0 });
        }
        else{
            f_dice(L"Please press Z key").draw();
        }
    }

    return 0;
}

// --------------------------------
//  サイコロを投げる
// --------------------------------
int ScreneManager::throw_dice(){
    static int dice_count = 0;

    if (Input::KeyZ.clicked){
        if (is_clear()){
            ScreneManager();
            dice_count = 0;

            return 0;
        }

        int who_turn = dice_count % PLAYER_NUM;
        switch (who_turn){
        case 0:
            // TODO : メソッド化
            move_on_one_player_dice(who_turn);
            now_turn += 1;
            break;
        case 1:
            move_on_one_player_dice(who_turn);
            break;
        }

        dice_count++;
    }

    return 0;
}

// --------------------------------
//  プレイヤー情報更新
// --------------------------------
void ScreneManager::update_player_data(){

    for (int i = 0; i < PLAYER_NUM; ++i){
        player.at(i)->set_progress(now_position.at(i));
    }

}

// --------------------------------
//  プレイヤーごとの処理
// --------------------------------
void ScreneManager::move_on_one_player_dice(int now_turn){
    flag_dice.set(now_turn);
    dice_result.at(now_turn) = dice(mt);
    now_position.at(now_turn) += dice_result.at(now_turn);
}


// --------------------------------
//  ゴールまであとどれくらいか計算
// --------------------------------
int ScreneManager::get_last_goal(int now_prg){
    return GOAL_POSITION - now_prg;
}

// --------------------------------
//  ゴール判定
// --------------------------------
bool ScreneManager::is_clear(){

    for (int i = 0; i < PLAYER_NUM; ++i){
        if (get_last_goal(player.at(i)->get_progress()) < 1){
            return true;
        }
    }

    return false;

}
