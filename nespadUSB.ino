#include "HID.h"
#include "Keyboard.h"

#define NUM_BUTTONS 8

void setup() {
  Serial1.begin(2000000);
  Serial.begin(2000000);
  Keyboard.begin();
}

int convertButtonIndexToKey(int index)
{
  switch(index)
  {
    case 0:
      return 97; // a
    case 1:
      return 98; // b
    case 2:
      return 32; // Space
    case 3:
      return KEY_RETURN;
   case 4:
      return KEY_UP_ARROW;
    case 5:
      return KEY_DOWN_ARROW;
    case 6:
      return KEY_LEFT_ARROW;
    case 7:
      return KEY_RIGHT_ARROW;
    default:
      return -1;
  }
}

void loop() {
  if (Serial1.available() > 0)
  {
    int buttonRegister = Serial1.read();
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
      boolean isPressed = bitRead(buttonRegister, i);
      int key = convertButtonIndexToKey(i);
      if (isPressed)
        Keyboard.press(key);
      else
        Keyboard.release(key);
    }
  }
}
