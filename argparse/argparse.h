#ifndef ARGPARSE_H_
#define ARGPARSE_H_

#include "argument.h"

#include <memory>
#include <string>
#include <vector>

class ArgumentParser {
 public:
  ArgumentParser();

  void addArgument(const std::string& name,
                   const std::string& help,
                   const std::string& def_value = "");

  const Argument* getArgument(const std::string& name) const;

  const std::vector<const Argument*> getArguments() const;

  void parse(int argc, char** argv);

  virtual std::string retrieve(const std::string& name) const;

 protected:
  std::vector<std::unique_ptr<Argument> > arguments_;
};

#endif  // ARGPARSE_H_
