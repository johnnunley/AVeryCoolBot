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

#include "sequence.h"

Sequence::Sequence(ActionList a, InputList i) : actions(a), inputs(i) { }

UnexecutedSequence::UnexecutedSequence(ActionList a, InputList i) : Sequence(a,i) {
}

ExecutedSequence::ExecutedSequence(ActionList a, InputList i, score_t s) : Sequence(a,i), score(s) {

}

ExecutedSequence::ExecutedSequence(UnexecutedSequence us, score_t s) : ExecutedSequence(us.actions,us.inputs,s) { }

UnexecutedSequence ExecutedSequence::getTemplate() { return UnexecutedSequence(actions,inputs); }

ExecutedSequence UnexecutedSequence::execute() {
  score_t score = 0;
  for (int i = 0; i < actions.size(); i++) {
    action method = actions[i];
    Input input = inputs[i];
    score += method(input.a,input.b,input.c);
  }
  return ExecutedSequence(actions,inputs,score);
}
