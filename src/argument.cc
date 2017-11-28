#include "argument.h"

Argument::Argument(const std::string& name,
                   const std::string& help)
  : name_(name), help_(help) {
  // content here
}

OptionalArgument::OptionalArgument(const std::string& name,
                                   const std::string& help,
                                   const std::string& def_value)
  : Argument(name, help), def_value_(def_value) {
  // content here
}
