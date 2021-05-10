//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#ifndef VIEW_H_DA1814B52922481FB135CC8EEBB4841E
#define VIEW_H_DA1814B52922481FB135CC8EEBB4841E

#include <filesystem>

namespace fs = std::filesystem;

class view {
 public:
  virtual void set_dir(const fs::path &root) = 0;
  virtual std::ostream *get_log() = 0;
};

#endif //VIEW_H_DA1814B52922481FB135CC8EEBB4841E
