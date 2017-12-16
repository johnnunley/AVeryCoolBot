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

#ifndef IRRELEVANT_VARIABLE
#define IRRELEVANT_VARIABLE -1

#include "sequence.h"

class Variable {
public:
  bool isRelevant;
  int sequenceIndex;
  int inputIndex;
  Variable(bool,int,int);
  double getValue(Sequence);
};

#endif
