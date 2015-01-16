// ================================================================
//  Game make test
// ================================================================
#include <Siv3D.hpp>
#include <random>

using namespace std;

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
    uniform_int_distribution<int> dice(0, 6);

    // Make the dice font
    Font f_dice(16);

    while (System::Update()){

        // Draw the dice
        f_dice(dice(mt)).draw();

    }
}
