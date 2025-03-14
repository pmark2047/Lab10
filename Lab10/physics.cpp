/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    Peyton Markus, William Barr
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/
  
 #include "physics.h"  // for the prototypes
 
 /*********************************************************
 * LINEAR INTERPOLATION
 * From a list of domains and ranges, linear interpolate
 *********************************************************/
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
   if (domain < mapping[0].domain)
   {
      return mapping[0].range;
   }
   
   if (domain > mapping[numMapping - 1].domain)
   {
      return mapping[numMapping - 1].range;
   }
   
   for (int i = 0; i < numMapping; i++)
   {
      if (domain >= mapping[i].domain && domain <= mapping[i + 1].domain)
      {
         if (domain == mapping[i].domain)
         {
            return mapping[i].range;
         }
         
         return linearInterpolation(mapping[i].domain, mapping[i].range, mapping[i + 1].domain, mapping[i + 1].range, domain);
         
      }
   }
   return -99.9;
}

/*********************************************************
 * GRAVITY FROM ALTITUDE
 * Determine gravity coefficient based on the altitude
 *********************************************************/
double gravityFromAltitude(double altitude)
{
   const Mapping mapping[] = {
           {0, 9.807},    // mapping[0]
           {1000, 9.804}, // mapping[1]
           {2000, 9.801}, // mapping[2]
           {3000, 9.797}, // mapping[3]
           {4000, 9.794}, // mapping[4]
           {5000, 9.791}, // mapping[5]
           {6000, 9.788}, // mapping[6]
           {7000, 9.785}, // mapping[7]
           {8000, 9.782}, // mapping[8]
           {9000, 9.779}, // mapping[9]
           {10000, 9.776}, // mapping[10]
           {15000, 9.761}, // mapping[11]
           {20000, 9.745}, // mapping[12]
           {25000, 9.730}, // mapping[13]
           {30000, 9.715}, // mapping[14]
           {40000, 9.684}, // mapping[15]
           {50000, 9.654}, // mapping[16]
           {60000, 9.624}, // mapping[17]
           {70000, 9.594}, // mapping[18]
           {80000, 9.564}  // mapping[19]
       };
   return linearInterpolation(mapping, 20 /*numMapping*/, altitude);
}

/*********************************************************
 * DENSITY FROM ALTITUDE
 * Determine the density of air based on the altitude
 *********************************************************/
double densityFromAltitude(double altitude)
{
   const Mapping mapping[] = {
           {0, 1.2250000},    // mapping[0]
           {1000, 1.1120000}, // mapping[1]
           {2000, 1.0070000}, // mapping[2]
           {3000, 0.9093000}, // mapping[3]
           {4000, 0.8194000}, // mapping[4]
           {5000, 0.7364000}, // mapping[5]
           {6000, 0.6601000}, // mapping[6]
           {7000, 0.5900000}, // mapping[7]
           {8000, 0.5258000}, // mapping[8]
           {9000, 0.4671000}, // mapping[9]
           {10000, 0.4135000}, // mapping[10]
           {15000, 0.1948000}, // mapping[11]
           {20000, 0.0889100}, // mapping[12]
           {25000, 0.0400800}, // mapping[13]
           {30000, 0.0184100}, // mapping[14]
           {40000, 0.0039960}, // mapping[15]
           {50000, 0.0010270}, // mapping[16]
           {60000, 0.0003097}, // mapping[17]
           {70000, 0.0000828}, // mapping[18]
           {80000, 0.0000185}  // mapping[19]
       };
   return linearInterpolation(mapping, 20 /*numMapping*/, altitude);
}

/*********************************************************
 * SPEED OF SOUND FROM ALTITUDE
 * determine the speed of sound for a given altitude.
 ********************************************************/
double speedSoundFromAltitude(double altitude)
{
   return -99.9;
}


/*********************************************************
 * DRAG FROM MACH
 * Determine the drag coefficient for a M795 shell given speed in Mach
 *********************************************************/
double dragFromMach(double speedMach)
{
   return -99.9;
}

