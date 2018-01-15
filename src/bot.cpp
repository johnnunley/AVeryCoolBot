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

#include "bot.h"
#include "AVCB_config.h"

AVCB::AVCB(UnexecutedSequence *us,vector<bool> relevancy,vector<double> baseline) : sequenceTemplate(us), stepIndex(0), stage(0) {
  int actionIndex = 0;
  int inputIndex = 0;
  for (int i = 0; i < relevancy.size(); i++) {
    bool b = relevancy[i];
    double d = baseline[i];
    Variable v (b,actionIndex,sequenceIndex);
    if (v.isRelevant) {
      varmanagers.add(VariableManager(us,v,d));
    }
    switch (inputIndex) {
      case 2: inputIndex = 0; actionIndex++; break;
      default: inputIndex++; break;
    }
  }
}

void AVCB::step() {
  if (stage == 0) {
    if (runIndex < varmanagers.size()) {
      if (stepIndex < RUN_CYCLE_COUNT) {
         
        stepIndex++;  
      }
      else {
        stepIndex = 0;
        runIndex++;
      } 
    }
    else {
      stage = 1;
    }
  } 
}
