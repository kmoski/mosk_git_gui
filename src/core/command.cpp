//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include "command.h"
#include "logger.h"

void command::run(const char* cmd) {
  std::array<char, 128> buffer{};
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    to_log << buffer.data();
  }
}
// TODO(kmosk): Replace popen and pclose with _popen and _pclose for Windows.
