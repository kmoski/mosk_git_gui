//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#include "wx_view.h"

wx_view::wx_view() {
  frame = new wx_main_frame;
  frame->Show();
}
wx_view::~wx_view() {
  delete log;
}
void wx_view::set_dir(const fs::path &root) {
  frame->set_dir(root);
}
std::ostream *wx_view::get_log() {
  log = new std::ostream(frame->get_log_buf());
  return log;
}
