void StartFunc()
{
   Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
//
// 
// //////////////////////////////////////////////
//
//  ///start the Ethernet connection:
//  Serial.println("Initialize Ethernet with DHCP:");
//  if (Ethernet.begin(mac) == 0)
//  {
//    Serial.println("Failed to configure Ethernet using DHCP");
//    // Check for Ethernet hardware present
//    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
//      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
//      while (true) {
//        delay(1); // do nothing, no point running without Ethernet hardware
//      }
//    }
//    if (Ethernet.linkStatus() == LinkOFF) {
//      Serial.println("Ethernet cable is not connected.");
//    }
//    // try to congifure using IP address instead of DHCP:
//    Ethernet.begin(mac, ip, myDns);
//  }
//  else
//  {
//    Serial.print("  DHCP assigned IP ");
//    Serial.println(Ethernet.localIP());
//  }
//  // give the Ethernet shield a second to initialize:
//  delay(1000);
//
//  Serial.print("connecting to ");
//  Serial.print(server);
//  Serial.println("...");

///////////POST/////////////

//   PostDataFunc();
    
//////////////////////////////

  
//  beginMicros = micros();
  }

  
