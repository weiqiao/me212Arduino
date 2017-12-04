#include <SoftwareServo.h>

SoftwareServo servo1;

void setup()
{
  servo1.attach(2);
  //servo1.setMaximumPulse(2200);
}

void loop()
{
  static int value = 0;
  static char CurrentServo = 0;
  servo1.write(0);
  SoftwareServo::refresh();
  
}
