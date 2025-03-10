/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

 /************************************
  * ANGLE : NORMALIZE
  ************************************/
double Angle::normalize(double radians) const
{
   double normalizedAngle = fmod(radians, 2 * M_PI);
   return (normalizedAngle >= 0) ? normalizedAngle : (normalizedAngle + 2 * M_PI);
}



