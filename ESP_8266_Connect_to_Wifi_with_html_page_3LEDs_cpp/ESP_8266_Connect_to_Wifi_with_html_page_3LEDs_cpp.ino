//******************************
//This works if the board and client(browser are connecte to same wifi network
*********************************
//Include built in wifi lib
#include <ESP8266WiFi.h>

const char* ssid = "Eng Otieno - R";    //  Your Wi-Fi Name
const char* password = "5Aim95AnRgb";   // Wi-Fi Password

int RedLED = D0;
int OrangeLED = D1;
int GreenLED = D2;

WiFiServer server(80);

void setup()

{

  Serial.begin(115200); //Default Baudrate
  pinMode(RedLED, OUTPUT);
  pinMode(OrangeLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);

  digitalWrite(RedLED, LOW);
  digitalWrite(OrangeLED, LOW);
  digitalWrite(GreenLED, LOW);
  Serial.print("Connecting to the Newtork");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) //while board not connected to wifi
  {
    delay(500);
    Serial.print("Trying to connect to WiFi.......");
  }

  Serial.println("WiFi connected.....");
  server.begin();  // Starts the Server
  Serial.println("Server started.......");
  Serial.print("WiFi Network IP Address: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Paste this URL on browser to control the LEDs: http://"); // Will print IP address in URL format
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()

{

  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");

  while(!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  int value = LOW;

  if(request.indexOf("/RedLED=ON") != -1)
  {
    digitalWrite(RedLED, HIGH); // Turn LED ON
    digitalWrite(OrangeLED, LOW);    
    digitalWrite(GreenLED, LOW);    
    value = HIGH;
  }

 
  if(request.indexOf("/RedLED=OFF") != -1)
  {

    digitalWrite(RedLED, LOW); // Turn LED OFF
    digitalWrite(OrangeLED, LOW);
    digitalWrite(GreenLED, LOW);
    value = LOW;

  }


  // Control OrangeLED
  if(request.indexOf("/OrangeLED=ON") != -1)
  {
    digitalWrite(RedLED, LOW); // Turn LED ON
    digitalWrite(OrangeLED, HIGH);    
    digitalWrite(GreenLED, LOW);    
    value = HIGH;
  }

  if(request.indexOf("/OrangeLED=OFF") != -1)
  {

    digitalWrite(RedLED, LOW); // Turn LED OFF
    digitalWrite(OrangeLED, LOW);
    digitalWrite(GreenLED, LOW);
    value = LOW;

  }

// Control GreenLED
  if(request.indexOf("/GreenLED=ON") != -1)
  {
    digitalWrite(RedLED, LOW); // Turn LED ON
    digitalWrite(OrangeLED, LOW);    
    digitalWrite(GreenLED, HIGH);    
    value = HIGH;
  }
 
  if(request.indexOf("/GreenLED=OFF") != -1)
  {

    digitalWrite(RedLED, LOW); // Turn LED OFF
    digitalWrite(OrangeLED, LOW);
    digitalWrite(GreenLED, LOW);
    value = LOW;

  }
 

//*------------------HTML Page Code---------------------*//
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  //html code to Control Red LED 
  client.println("<html>");
  client.print(" CONTROL RedLED: ");
  if(value == HIGH)
  {
    client.print("ON");  }
  else
  {
    client.print("OFF");
  }
   client.println("<br><br>");
  client.println("<a href=\"/RedLED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/RedLED=OFF\"\"><button>OFF</button></a><br />"); 
  client.println("</html>");
  delay(1);

//  html code to control Oranage LED
  client.println("<html>");
  client.print(" CONTROL OrangeLED: ");  
  if(value == HIGH)
  {
    client.print("ON");  }
  else
  {
    client.print("OFF");
  }

  client.println("<br><br>");
  client.println("<a href=\"/OrnageLED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/OrnageLED=OFF\"\"><button>OFF</button></a><br />");  
  client.println("</html>");
  delay(1);

//  html code to control Green LED
  client.println("<html>");
  client.print(" CONTROL GreenLED: ");  
  if(value == HIGH)
  {
    client.print("ON");  }
  else
  {
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("<a href=\"/GreenLED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/GreenLED=OFF\"\"><button>OFF</button></a><br />");  
  client.println("</html>");
  delay(1);

  Serial.println("Client disonnected");
  Serial.println("");
}



// //Include built in wifi lib
// #include <ESP8266WiFi.h>

// const char* ssid = "Eng Otieno - R";    //  Your Wi-Fi Name
// const char* password = "5Aim95AnRgb";   // Wi-Fi Password

// int RedLED = D0;
// int OrangeLED = D1;
// int GreenLED = D2;

// WiFiServer server(80);

// void setup()

// {

//   Serial.begin(115200); //Default Baudrate
//   pinMode(RedLED, OUTPUT);
//   pinMode(OrangeLED, OUTPUT);
//   pinMode(GreenLED, OUTPUT);

//   digitalWrite(RedLED, LOW);
//   digitalWrite(OrangeLED, LOW);
//   digitalWrite(GreenLED, LOW);
//   Serial.print("Connecting to the Newtork");

//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) //while board not connected to wifi
//   {
//     delay(500);
//     Serial.print("Trying to connect to WiFi.......");
//   }

//   Serial.println("WiFi connected.....");
//   server.begin();  // Starts the Server
//   Serial.println("Server started.......");
//   Serial.print("WiFi Network IP Address: "); // will IP address on Serial Monitor
//   Serial.println(WiFi.localIP());
//   Serial.print("Paste this URL on browser to control the LEDs: http://"); // Will print IP address in URL format
//   Serial.print(WiFi.localIP());
//   Serial.println("/");
// }

// void loop()

// {

//   WiFiClient client = server.available();
//   if (!client)
//   {
//     return;
//   }
//   Serial.println("Waiting for new client");

//   while(!client.available())
//   {
//     delay(1);
//   }
//   String request = client.readStringUntil('\r');
//   Serial.println(request);
//   client.flush();
//   int value = LOW;

//   if(request.indexOf("/RedLED=ON") != -1)
//   {
//     digitalWrite(RedLED, HIGH); // Turn LED ON
//     digitalWrite(OrangeLED, LOW);    
//     digitalWrite(GreenLED, LOW);    
//     value = HIGH;
//   }

 
//   if(request.indexOf("/RedLED=OFF") != -1)
//   {

//     digitalWrite(RedLED, LOW); // Turn LED OFF
//     // digitalWrite(OrangeLED, LOW);
//     // digitalWrite(GreenLED, LOW);
//     value = LOW;

//   }


//   // Control OrangeLED
//   if(request.indexOf("/OrangeLED=ON") != -1)
//   {
//     digitalWrite(RedLED, LOW); // Turn LED ON
//     digitalWrite(OrangeLED, HIGH);    
//     digitalWrite(GreenLED, LOW);    
//     value = HIGH;
//   }

//   if(request.indexOf("/OrangeLED=OFF") != -1)
//   {

//     // digitalWrite(RedLED, LOW); // Turn LED OFF
//     digitalWrite(OrangeLED, LOW);
//     // digitalWrite(GreenLED, LOW);
//     value = LOW;

//   }

// // Control GreenLED
//   if(request.indexOf("/GreenLED=ON") != -1)
//   {
//     digitalWrite(RedLED, LOW); // Turn LED ON
//     digitalWrite(OrangeLED, LOW);    
//     digitalWrite(GreenLED, HIGH);    
//     value = HIGH;
//   }
 
//   if(request.indexOf("/GreenLED=OFF") != -1)
//   {

//     // digitalWrite(RedLED, LOW); // Turn LED OFF
//     // digitalWrite(OrangeLED, LOW);
//     digitalWrite(GreenLED, LOW);
//     value = LOW;

//   }
//   char LED = RedLED, OrangeLED, GreenLED;
//   // char LED;
 

// //*------------------HTML Page Code---------------------*//
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("");
//   client.println("<!DOCTYPE HTML>");
  
//   // for (LED in LEDs)
//   // {
//   //html code to Control Red LED 
//   if (LED == RedLED)
//   {
//     client.println("<html>");
//     client.print(" CONTROL RedLED: ");
//     if(value == HIGH)
//     {
//       client.print("ON");  }
//     else
//     {
//       client.print("OFF");
//     }
//     client.println("<br><br>");
//     client.println("<a href=\"/RedLED=ON\"\"><button>ON</button></a>");
//     client.println("<a href=\"/RedLED=OFF\"\"><button>OFF</button></a><br />"); 
//     client.println("</html>");
//     delay(1);
//   }
//  //  html code to control Oranage LED
//   if (LED == OrangeLED)
//   {
//     client.println("<html>");
//     client.print(" CONTROL OrangeLED: ");  
//     if(value == HIGH)
//     {
//       client.print("ON");  }
//     else
//     {
//       client.print("OFF");
//     }
//     client.println("<br><br>");
//     client.println("<a href=\"/OrnageLED=ON\"\"><button>ON</button></a>");
//     client.println("<a href=\"/OrnageLED=OFF\"\"><button>OFF</button></a><br />");  
//     client.println("</html>");
//     delay(1);
//   }
//   //  html code to control Green LED
//   if (LED == GreenLED)
//   {
//     client.println("<html>");
//     client.print(" CONTROL GreenLED: ");  
//     if(value == HIGH)
//     {
//       client.print("ON");  }
//     else
//     {
//       client.print("OFF");
//     }
//     client.println("<br><br>");
//     client.println("<a href=\"/GreenLED=ON\"\"><button>ON</button></a>");
//     client.println("<a href=\"/GreenLED=OFF\"\"><button>OFF</button></a><br />");  
//     client.println("</html>");
//     delay(1);
//   }

//   Serial.println("Client disonnected");
//   Serial.println("");
// }

 
 