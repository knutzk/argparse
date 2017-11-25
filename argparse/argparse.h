#ifndef ARGPARSE_H_
#define ARGPARSE_H_

#include <string>

class ArgumentParser {
 public:
  ArgumentParser();

  void addArgument(const std::string& name, const std::string& help, bool optional);

  void parse(int argc, char** argv);
};

#endif  // ARGPARSE_H_
