//
// Copyright (c) 2021 kmosk. All rights reserved.
//
#include "core/core.h"

void application_main() {
  core::get().on_start_app();
}

#ifdef VIEW_WX
#include <wx/app.h>

class App : public wxApp {
 public:
  bool OnInit() final;
};
bool App::OnInit() {
  application_main();
  return true;
}
wxIMPLEMENT_APP(App);
#else
int main() {
  application_main();
}
#endif
