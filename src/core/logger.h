//
// Copyright (c) 2021 kmosk. All rights reserved.
//

#ifndef LOGGER_H_03A9737A783E442588F0836B5D8B246C
#define LOGGER_H_03A9737A783E442588F0836B5D8B246C

#include <ostream>

#define to_log logger::get_log()

 class logger : public std::ostream {
 protected:
  logger();
  static logger *instance;

  std::ostream *log_stream;
 public:
  logger(logger &) = delete;
  void operator=(const logger &) = delete;
  static logger &get();

  static std::ostream &get_log();
  static void set_ostream(std::ostream *out);
};

#endif //LOGGER_H_03A9737A783E442588F0836B5D8B246C
