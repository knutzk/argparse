#include "argparse/argument.h"

namespace Argparse {
Argument::Argument(const std::string& name,
                   const std::string& help)
  : name_(name), help_(help) {
  // content here
}
}  // namespace Argparse
