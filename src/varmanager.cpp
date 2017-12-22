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

#include "varmanager.h"

VariableManager::VariableManager(UnexecutedSequence u, Variable v, double di, double d2) : us(u), variable(v), bottom(d), top(0.0), lastScore(d2), direction(1) { }

bool VariableManager::isRelevant() { return variable.isRelevant; }

void VariableManager::updateVar() {
  variable.setValue(us,top);
}

void VariableManager::step() {
  int score;
  if (stage == 0) {
    if (direction == 1) {
      top = bottom + direction; 
      updateVar();
      score = us.execute();
      if (score > lastScore) {
        stage = 1;
      }
      else direction = -1;
    }
    
  }
  lastScore = score;
}
