#ifndef ARGPARSE_H_
#define ARGPARSE_H_

#include "argument.h"

#include <memory>
#include <string>
#include <vector>

class ArgumentParser {
 public:
  ArgumentParser();

  void addArgument(const std::string& name, const std::string& help, bool optional);

  void parse(int argc, char** argv);

 protected:
  std::vector<std::unique_ptr<Argument> > arguments_;
};

#endif  // ARGPARSE_H_
