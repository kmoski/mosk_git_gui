//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#ifndef CORE_H_0B59E32A6F3E4B789D13EF2B72832D7A
#define CORE_H_0B59E32A6F3E4B789D13EF2B72832D7A

#include "../view/view.h"

class core {
 protected:
  core();
  static core *instance;

  view *v;
 public:
  core(core &) = delete;
  void operator=(const core &) = delete;
  static core &get();

  void on_start_app();

  void on_change_dir(const std::string &path);
  void on_remote_update();
  void on_reset();
  void on_clean();
  void on_pull();
  void on_push();
  void on_run(const std::string &cmd);
};

#endif //CORE_H_0B59E32A6F3E4B789D13EF2B72832D7A
