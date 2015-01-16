// ================================================================
//  Game make test
// ================================================================
#include <Siv3D.hpp>
#include <random>
#include <bitset>

using namespace std;

// --------------------------------
//  Main function
// --------------------------------
void Main(){

    // ---------------- Window status ----------------
    // Background color
    Graphics::SetBackground(Palette::Black);
    // Window title
    Window::SetTitle(L"Game make test");
    // Window size
    Window::Resize(1024, 768);
    // Window set center
    Window::Centering();

    // ---------------- Make the random ----------------
    // Make the random
    random_device rd;
    // Mersenne twister
    mt19937 mt(rd());
    // Make a dice
    uniform_int_distribution<int> dice(1, 6);

    // ---------------- Values ----------------
    // Make the dice font
    Font f_dice(16);
    // Throw the dice flag
    bitset<1> flag_dice;
    // Dice result
    int dice_result;

    while (System::Update()){

        // If pressed Z
        if (Input::KeyZ.clicked){
            // Dice throw flag turn on
            flag_dice.at(0) = true;
            // Get dice random
            dice_result = dice(mt);
        }

        // If dice is throwed
        if (flag_dice.at(0)){
            // Draw the dice
            f_dice(dice_result).draw();
        }
        else{
            // Draw first message
            f_dice(L"Please press Z key").draw();
        }

    }
}
