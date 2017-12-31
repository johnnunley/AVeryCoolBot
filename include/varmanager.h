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

#ifndef AVCB_VARMANAGER
#define AVCB_VARMANAGER

#include "variable.h"

// notes:
// 0 = determining direction
// 1 = determining ceiling
// 2 = determining correction

class VariableManager {
public:
  Variable variable;
  UnexecutedSequence *us;
  int stage;
  double bottom;
  double top;
  double lastScore;
  double initialScore;
  int direction;
  VariableManager(UnexecutedSequence *,Variable,double);
  bool isRelevant();
  void updateVar();
  void step(); 
};

#endif
