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

#ifndef AVCB_BOT
#define AVCB_BOT

#include "varmanager.h"

class AVCB {
private:
  UnexecutedSequence *sequenceTemplate;
  std::vector<VariableManager> varmanagers;
  int stepIndex;
  int runIndex;
  std::vector<double> varAdjustmentScores;
 
  int stage;
  std::vector<int> orderOfActions;
  std::vector<int> shuffledOrder;
public:
  AVCB(UnexecutedSequence *,std::vector<bool>,std::vector<double>);
  void step();
};

#endif
