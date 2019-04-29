 void SetUpEthernetShield()
 {

 // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0)
  {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1); // do nothing, no point running without Ethernet hardware
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip, myDns);
  }
  else
  {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  
  }

//  void PostDataFunc()
//  {
//    Serial.println("Entered in Func");
//    // if you get a connection, report back via serial:
//      if (client.connect(server, 80))
//      {
//        Serial.print("connected to ");
//        Serial.println(client.remoteIP());
//        // Make a HTTP request:
//        client.println("POST "+UrlPath+" HTTP/1.1");
//        //client.println("POST "+UrlPath_q+" HTTP/1.1");
//        Serial.println("POST "+UrlPath);
//        client.println("Host: apps.capsonic.com");
//        client.println("Connection: close");
//        //client.println("Content-Type: application/x-www-form-urlencoded;");
//        client.println("Content-Type: application/json");    
//        client.println("Accept: application/json");
//        client.print("Content-Length: ");
//        client.println(PostData.length());
//        client.println();
//        client.println(PostData);
//      }
//      else
//      {
//        // if you didn't get a connection to the server:
//        Serial.println("connection failed");
//      }
//    }
