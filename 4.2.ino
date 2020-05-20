#include <Keypad.h>
#include "SevSeg.h"
SevSeg sevseg;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'F','E','D','C'} , {'B','3','6','9'},
  {'A','2','5','8'} , {'0','1','4','7'}
};

byte rowPins[ROWS]={5,4,3,2};
byte colPins[COLS]={10,9,8,7};
Keypad keypad =
  Keypad (makeKeymap(keys),rowPins,colPins,ROWS,COLS);
void setup() {
 Serial.begin(9600);
 byte numDigits = 1;
 byte digitPins[] = {6};
 byte segmentPins[]={11,12,13,14,15,16,17};
 sevseg.begin(COMMON_CATHODE , numDigits , digitPins , segmentPins);

}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key);
    if(key >= '0' && key <= '9')
    sevseg.setNumber(key - '0',1);
  }
 sevseg.refreshDisplay();
}
