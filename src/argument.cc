#include "argument.h"

Argument::Argument(const std::string& name,
                   const std::string& help)
  : name_(name), help_(help) {
  // content here
}

OptionalArgument::OptionalArgument(const std::string& name,
                                   const std::string& help,
                                   bool def)
  : Argument(name, help), default_(def) {
  // content here
}
