//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#ifndef WX_MAIN_FRAME_H_657F867D1F804370B293BC49C004C8B5
#define WX_MAIN_FRAME_H_657F867D1F804370B293BC49C004C8B5

#include <filesystem>
#include "gen/gen_view.h"

namespace fs = std::filesystem;

class wx_main_frame : public main_frame {
 protected:
  void on_change_dir(wxFileDirPickerEvent &event) override;
  void on_remote_update(wxCommandEvent &event) override;
  void on_reset(wxCommandEvent &event) override;
  void on_clean(wxCommandEvent &event) override;
  void on_pull(wxCommandEvent &event) override;
  void on_push(wxCommandEvent &event) override;
  void on_run(wxCommandEvent &event) override;
 public:
  wx_main_frame();

  void set_dir(const fs::path &root);
  std::streambuf *get_log_buf();
};

#endif //WX_MAIN_FRAME_H_657F867D1F804370B293BC49C004C8B5
