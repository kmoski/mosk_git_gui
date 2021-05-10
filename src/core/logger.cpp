//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#include <iostream>
#include "logger.h"

logger *logger::instance = nullptr;
logger::logger()
    : log_stream(&std::cout) {}
logger &logger::get() {
  if (instance == nullptr) {
    instance = new logger;
  }
  return *instance;
}
void logger::set_ostream(std::ostream *out) {
  instance->log_stream = out;
}
std::ostream &logger::get_log() {
  return *(instance->log_stream);
}
