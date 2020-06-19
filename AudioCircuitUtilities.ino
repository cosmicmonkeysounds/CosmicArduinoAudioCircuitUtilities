/**
 *  The root of it all! Pretty barren. 
*/

#define LED_DATA        A4
#define LED_CLOCK       A5

#define BYPASS_BTN      13
#define SECOND_BTN      12

#define GAIN_POT        A0
#define VOLUME_POT      A1
#define BLEND_POT       A2
#define STABILITY_POT   A3

#include "CosmicMap.h"
#include "CosmicList.h"
#include "CircuitElement.h"
#include "Potentiometer.h"
#include "Pushbutton.h"
#include "Rotary.h"
#include "Context.h"

//Rotary* rotaryTest = new Rotary( 3, 4, 2, 5, "test" );

//Context* cxt = new Context();

CosmicMap<Rotary>* rotMap = new CosmicMap<Rotary>;
Rotary* rotaryTest = new Rotary( 3, 4, 2, 5, "test" );

//CosmicMap<CircuitElement>* hash = new CosmicMap<CircuitElement>;
//const char* g = "gain";
//CircuitElement* gain = new CircuitElement(g);

//CosmicMap<Potentiometer>* potHash = new CosmicMap<Potentiometer>;
//Potentiometer* gainPot = new Potentiometer( A0, "Gain", [](int x) -> int { return log10(x/100.0 + 1.0) * 1000.0; } );

//CosmicList<PushButton>* buttonList = new CosmicList<PushButton>;
//PushButton* bypassButton = new PushButton( 13, "bypass" );



void setup()
{
    Serial.begin(9600);
    rotMap->insert( rotaryTest );
    Serial.println("check check");
//    hash->insert(gain);
//    potHash->insert(gainPot);

}

void loop()
{ 
//    hash->printAll();
//    Serial.println( gainPot->label );
//    potHash->returnNode(gainPot->label)->update();
//    Serial.print("In value: "); Serial.print(potHash->returnNode(gainPot->label)->currentValue);
//    Serial.print(" Out value: "); Serial.println(potHash->returnNode(gainPot->label)->getValue());
//
//    bypassButton->update();
//

//    Rotary* t = rotMap->returnNode("test");
//    rotMap->returnNode("test")->update();
//    Serial.println(t->counter);
//
//    switch( rotaryTest->pushButton.state )
//    {
//        case 1:
//          Serial.println("Single Click");
//          break;
//        case 2:
//          Serial.println("Single Hold");
//          break;
//        case 3:
//          Serial.println("Double Click");
//          break;
//        case 4:
//          Serial.println("Double Hold");
//          break; 
//        case 5: 
//          Serial.println("Released");
//          break;              
//    }
    
}
