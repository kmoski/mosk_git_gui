//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#include "wx_main_frame.h"
#include "../../core/core.h"

wx_main_frame::wx_main_frame()
    : main_frame(nullptr) {}
void wx_main_frame::on_change_dir(wxFileDirPickerEvent &event) {
  core::get().on_change_dir(event.GetPath().ToStdString());
}
void wx_main_frame::on_remote_update(wxCommandEvent &event) {
  core::get().on_remote_update();
}
void wx_main_frame::on_reset(wxCommandEvent &event) {
  core::get().on_reset();
}
void wx_main_frame::on_clean(wxCommandEvent &event) {
  core::get().on_clean();
}
void wx_main_frame::on_pull(wxCommandEvent &event) {
  core::get().on_pull();
}
void wx_main_frame::on_push(wxCommandEvent &event) {
  core::get().on_push();
}
void wx_main_frame::on_run(wxCommandEvent &event) {
  core::get().on_run(command->GetLineText(0).ToStdString());
}
void wx_main_frame::set_dir(const fs::path &root) {
  dir_picker->SetDirName(wxFileName(root.string()));
}
std::streambuf *wx_main_frame::get_log_buf() {
  return terminal_view;
}
