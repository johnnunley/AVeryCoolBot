/*
 * =====================================================================================
 *
 *       Filename:  input.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/15/2017 05:15:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  J.T. Nunley (JaydomStudios), jtnunley01@gmail.com
 *   Organization:  JaydomStudios
 *
 * =====================================================================================
 */

#include "input.h"

Input::Input(double c_a, double c_b, double c_c) : a(c_a), b(c_b), c(c_c) { }

Input::Input() : Input(0,0,0) { }
