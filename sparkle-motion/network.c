// network stuff

/*
  Web client

 This sketch connects to a website (http://www.google.com)
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe, based on work by Adrian McEwen

 */

#include <Ethernet.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,6,5,4,3,7);

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:

IPAddress server(10,48,101,15);  

// char server[] = "www.google.com";    // name address for Google (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(10, 48, 101, 9);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {

  lcd.begin(16, 2);
  lcd.clear();

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    lcd.print("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  lcd.print("connecting...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    lcd.print("connected");
    // Make a HTTP request:
    client.println("GET /search?q=arduino HTTP/1.1");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    lcd.print("connection failed");
  }

  lcd.print("moving on");
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    lcd.print(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    lcd.print("disconnecting.");
    client.stop();

    // do nothing forevermore:
    while (true);
  }
}
