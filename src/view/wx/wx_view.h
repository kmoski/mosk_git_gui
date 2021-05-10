//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#ifndef WX_VIEW_H_A49DB0588DFE4241A60ED8C41F675481
#define WX_VIEW_H_A49DB0588DFE4241A60ED8C41F675481

#include "../view.h"
#include "wx_main_frame.h"

class wx_view : public view {
 protected:
  wx_main_frame *frame;

  std::ostream *log = nullptr;
 public:
  wx_view();
  ~wx_view();
  void set_dir(const fs::path &root) override;
  std::ostream *get_log() override;
};

#endif //WX_VIEW_H_A49DB0588DFE4241A60ED8C41F675481
