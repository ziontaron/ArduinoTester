#include <SPI.h>
#include <Ethernet.h>

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
bool printWebData = true;  // set to false for better speed measurement

String OP="Ard-01";
String Value="11111";
String Status="Test";

String PostData = "{\"OP\": \""+OP+"\", \"Value\": "+Value+", \"Status\": \""+Status+"\"}";
String UrlPath_q="/Production/Sample?OP="+OP+"&Value="+Value+"&Status="+Status;
String UrlPath="/Production/Sample";

void setup() {
  StartFunc(); // SetUps Serial Com 
  delay(1000); // 1 Sec to boot the Thernet shield
  SetUpEthernetShield(); //SetUps Ethernet Shield
  PostDataFunc(); //Post Data to the server
  //beginMicros = micros();
}

void loop() {

ShowResults();
  
//  // if there are incoming bytes available
//  // from the server, read them and print them:
//  int len = client.available();
//  if (len > 0) {
//    byte buffer[80];
//    if (len > 80) len = 80;
//    client.read(buffer, len);
//    if (printWebData) {
//      Serial.write(buffer, len); // show in the serial monitor (slows some boards)
//    }
//    byteCount = byteCount + len;
//  }
//
//  // if the server's disconnected, stop the client:
//  if (!client.connected())
//  {
//    endMicros = micros();
//    Serial.println();
//    Serial.println("disconnecting.");
//    client.stop();
//    Serial.print("Received ");
//    Serial.print(byteCount);
//    Serial.print(" bytes in ");
//    float seconds = (float)(endMicros - beginMicros) / 1000000.0;
//    Serial.print(seconds, 4);
//    float rate = (float)byteCount / seconds / 1000.0;
//    Serial.print(", rate = ");
//    Serial.print(rate);
//    Serial.print(" kbytes/second");
//    Serial.println();
//    
//    while (true) {
//      delay(1);
//    }
  }
}
