#include "argument.h"

Argument::Argument(const std::string& name,
                   const std::string& help)
  : name_(name), help_(help) {
  // content here
}

void Argument::setDefaultValue(const std::string& def_value) {
  def_value_ = def_value;
  value_ = def_value;
}
