#include <SPI.h>
#include <Ethernet.h>

////////FUNCION FILES//////////////////////


///////////////////////////////////////////

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "apps.capsonic.com";    // name address for Google (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 0, 177);
IPAddress myDns(192, 168, 0, 1);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

// Variables to measure the speed
unsigned long beginMicros, endMicros;
unsigned long byteCount = 0;
bool printWebData = false;  // set to false for better speed measurement

String OP="Ard-01";
String Value="11111";
String Status="Test";
int PartsProd=0;

String PostData = "{\"OP\": \""+OP+"\", \"Value\": "+Value+", \"Status\": \""+Status+"\",\"PartsProduced\": "+PartsProd+"}";
//String PostData = "{\"OP\": \""+OP+"\", \"Value\": "+Value+", \"Status\": \""+Status+"\"}";
String UrlPath_q="/Production/Sample?OP="+OP+"&Value="+Value+"&Status="+Status;
String UrlPath="/Production/Sample";

///////////////////////////////////////////////////////////////////////////
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 12;      // the number of the LED pin
const int ConLed = 12;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState= HIGH;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
////////////////////////////////////////////////////////////////////

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete


void setup() {

///////////////////////////////////////////////////

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);

///////////////////////////////////////////////////
  
  StartFunc(); // SetUps Serial Com 
  delay(1000); // 1 Sec to boot the Ethernet shield
  SetUpEthernetShield(); //SetUps Ethernet Shield
  inputString.reserve(200);
  //PostDataFunc(); //Post Data to the server
  //beginMicros = micros();
}

void loop() {

//    PostDataFunc();
//    delay(5);
    
    PostTrigger();
if (stringComplete) {
    Serial.print(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
    
    CommandParser();
  }

//ShowResults();
//  
//    while (true) 
//    {
//      delay(1);
//    }
}
