#ifndef ARGPARSE_PARSER_H_
#define ARGPARSE_PARSER_H_

#include "argparse/argument.h"

#include <memory>
#include <string>
#include <vector>

namespace Argparse {
class Parser {
 public:
  Parser();

  void addArgument(const std::string& name,
                   const std::string& help);

  const Argument* getArgument(const std::string& name) const;

  Argument* getArgument(const std::string& name);

  const std::vector<const Argument*> getArguments() const;

  void parse(int argc, char** argv);

  virtual std::string retrieve(const std::string& name) const;

 protected:
  std::string print_usage() const;
  std::vector<std::unique_ptr<Argument> > arguments_;
  std::string prog_name_;
};
}  // namespace Argparse

#endif  // ARGPARSE_PARSER_H_
