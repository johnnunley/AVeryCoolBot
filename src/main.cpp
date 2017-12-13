/*
 
This file is part of AVCB.

AVCB is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

AVCB is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with AVCB.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "version.h"
#include "action.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

std::string getCoefficient(int i) {
  if (i == 1)
    return "";
  std::stringstream s;
  if (i < 0)
    s << -i;
  else
    s << i;
  return s.str();
}

result_t testAction(int a, int b, int c) {
  double sqrtTerm = std::pow(b,2) - (4*a*c);
  sqrtTerm = std::sqrt(sqrtTerm);
  double result1 = (0-b)+sqrtTerm;
  double result2 = (0-b)-sqrtTerm;
  result1 /= (2*a);
  result2 /= (2*a);
  std::cout << getCoefficient(a) << "x^2 " << (b > 0 ? "+ " : "- ") << getCoefficient(b) << "x " << (c > 0 ? "+ " : "- ") << (c != 1 ? getCoefficient(c) : "1") << " = " << result1 << " or " << result2 << std::endl;
  return NO_RESULT;
}

int main(int argc, char **argv) {
  std::cout << "You are running AVCB version " << getVersion() << std::endl;
  action myAction = &testAction;
  myAction(1,-6,9);
  return 0;
}
