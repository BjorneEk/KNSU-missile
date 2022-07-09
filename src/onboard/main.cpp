
////////////////////////////////////////////////////////////////////////////
///                                                                      ///
///        @author Gustaf Franzén :: https://github.com/BjorneEk;        ///
///        @author Emil Wallbom   :: https://github.com/XXXXXXXX;        ///
///              https://github.com/BjorneEk/KNSU-missile                ///
///                                                                      ///
////////////////////////////////////////////////////////////////////////////

#include "rocket.h"

#define XSERVO_PIN 9
#define YSERVO_PIN 9
#define ET_APOGEE 7000
#define ET_BURN 5000

Rocket rocket(XSERVO_PIN, YSERVO_PIN, ET_APOGEE, ET_BURN,0.0, 90.0, 90.0);

void setup()
{
  rocket.init();
}


void loop()
{
  rocket.update(millis(), 0, 90.0, 90.0);
}
