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
#include <iostream>
using namespace std;

VariableManager::VariableManager(UnexecutedSequence *u, Variable v, double sc) : us(u), variable(v), top(0.0), lastScore(sc), initialScore(sc), direction(1), stage(0) { 
  bottom = variable.getValue(us);
}

bool VariableManager::isRelevant() { return variable.isRelevant; }

void VariableManager::updateVar() {
  variable.setValue(us,top);
}



void VariableManager::step() {
  score_t score;
  if (stage == 0) {
    //cout << "Stage 0, Direction: " << direction << endl;
    top = bottom + direction; 
    updateVar();
    score = us->execute().score;
    //cout << "Top: " << top << ", Bottom: " << bottom << endl;
    //cout << "Score: " << score << endl;
    //cout << "Last Score: " << lastScore << endl;
    if (direction == 1) {  
      if (score > lastScore) {
        stage = 1;
      }
      else direction = -1;
    }
    else {
      if (score > lastScore) {
        stage = 1;
      }
      else {
          top = lastScore;
          bottom = score;
          stage = 2;
      }
    }   
  }
  else if (stage == 1) {
    //cout << "Stage 1, ";
    //double placeholder = top;
    top = top + direction; 
    bottom = bottom + direction;
    //cout << "Top : " << top << ", Bottom: " << bottom << endl;
    updateVar();
    score = us->execute().score;
    //cout << "Score: " << score << endl;
    //cout << "Last Score: " << lastScore << endl;
    if (score < lastScore) { stage = 2;
      double placeholder = top; 
      top = bottom;
      bottom = placeholder;
    }
  }
  else if (stage == 2) {
    //cout << "Stage 2, ";
    //double highest = (top > bottom ? top : bottom);
    //cout << "Pre-Top: " << top << endl;
    //double lowest = (highest == top ? bottom : top);
    double lastTop = top;
    top = (top + bottom) / 2;
   
    //cout << "Top: " << lastTop << ", Bottom: " << bottom << ", Val1: " << top << endl;
    updateVar();
    score = us->execute().score;
    //cout << "Score: " << score << endl;
    //cout << "Last Score: " << lastScore << endl;
    
    if (score >= lastScore) {
      bottom = top;
      top = lastTop;
    }
     //cout << "Top: " << top << ", Bottom: " << bottom endl;
  }
  lastScore = score;
}
