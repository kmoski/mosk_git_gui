//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#include <filesystem>
#include "core.h"
#include "command.h"
#include "logger.h"

#ifdef VIEW_WX
#include "../view/wx/wx_view.h"
#endif

namespace fs = std::filesystem;

core *core::instance = nullptr;
core::core() {
#ifdef VIEW_WX
  v = new wx_view;
#endif

  logger::get().set_ostream(v->get_log());
}
core &core::get() {
  if (instance == nullptr) {
    instance = new core;
  }
  return *instance;
}
void core::on_start_app() {
  v->set_dir(fs::current_path());
}
void core::on_change_dir(const std::string &path) {
  fs::current_path(path);
}
void core::on_remote_update() {
  command::run("git remote update --prune");
}
void core::on_reset() {
  command::run("git reset --hard HEAD");
}
void core::on_clean() {
  command::run("git clean -ffdx");
}
void core::on_pull() {
  command::run("git pull");
}
void core::on_push() {
  command::run("git push");
}
void core::on_run(const std::string &cmd) {
  command::run(("git " + cmd).c_str());
}
