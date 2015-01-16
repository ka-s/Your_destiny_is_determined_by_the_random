// ================================================================
//  Game make test
// ================================================================
# include <Siv3D.hpp>

void Main(){

    // Background color
    Graphics::SetBackground(Palette::White);
    // Window title
    Window::SetTitle(L"Game make test");
    // Window size
    Window::Resize(1024, 768);
    // Window set center
    Window::Centering();

    while (System::Update()){

    }
}
