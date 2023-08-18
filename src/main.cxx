#include <memory>
#include <string>
 
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp" 
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/util/ref.hpp"

using namespace std;
 
int main() {
  using namespace ftxui;
 
  string codeinput;
 
  Component input_code = Input(&codeinput, "ex: print(\"Hello world \")");
 
 
  auto component = Container::Vertical({
    input_code,
  });
 
  auto renderer = Renderer(component, [&] {
    return vbox({
               hbox(text(">> "), input_code->Render()),
           }) |
           border;
  });
 
  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
}