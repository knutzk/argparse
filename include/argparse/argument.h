#ifndef ARGPARSE_ARGUMENT_H_
#define ARGPARSE_ARGUMENT_H_

#include <string>

class Argument {
 public:
  Argument(const std::string& name,
           const std::string& help);

  inline auto getDefaultValue() const { return def_value_; }
  inline auto getName() const { return name_; }
  inline auto getHelpMessage() const { return help_; }
  inline auto getValue() const { return value_; }

  inline void setDefaultValue(const std::string& value) { def_value_ = value; }

  inline void setValue(const std::string& value) { value_ = value; }

 protected:
  const std::string name_;
  const std::string help_;
  std::string value_{""};
  std::string def_value_{""};
};

#endif  // ARGPARSE_ARGUMENT_H_
