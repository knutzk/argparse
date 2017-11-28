#ifndef ARGUMENT_H_
#define ARGUMENT_H_

#include <string>

class Argument {
 public:
  Argument(const std::string& name,
           const std::string& help);

  inline auto getName() const { return name_; }
  inline auto getHelpMessage() const { return help_; }
  inline auto getValue() const { return value_; }

  void setDefaultValue(const std::string& value);

  inline void setValue(const std::string& value) { value_ = value; }

 protected:
  const std::string name_;
  const std::string help_;
  std::string value_{""};
  std::string def_value_{""};
};

#endif  // ARGUMENT_H_
