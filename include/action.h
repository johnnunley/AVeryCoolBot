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

#ifndef AVCB_ACTION
#define AVCB_ACTION

#include "score.h"
#include <vector>

typedef score_t (*action)(double,double,double);
typedef std::vector<action> ActionList;

#endif
