#include <SoftwareSerial.h> // Library required for communication.
#include <DHT.h>;           // Library required for the DHT11 sensor.


String flag;                // Variable to listen to the signal coming from the Bluetooth module.


int relay1 = 4;             // Pin for relay number 1.
int relay2 = 5;             // Pin for relay number 2.
int relay3 = 6;             // Pin for relay number 3.
float hum;                  // Humidity variable.
float temp;                 // Temperature variable.




SoftwareSerial blue(10,11); // TX / RX pins of the Bluetooth module.
#define LDR 3               // Pin used by the LDR.
#define DHTPIN 7            // Pin used by the DHT11.
#define DHTTYPE DHT11       // Definition of the DHT sensor type.
DHT dht(DHTPIN, DHTTYPE);   // Creating the DHT sensor object.


void setup() {              // Setup function.
  Serial.begin(9600);       // Serial monitor baud rate definition.
  blue.begin(9600);         // Bluetooth module baud rate definition.
  dht.begin();              // Start command for the DHT11 sensor.
  pinMode(relay1, OUTPUT);  // Operating mode definition for relay number 1.
  pinMode(relay2, OUTPUT);  // Operating mode definition for relay number 2. 
  pinMode(relay3, OUTPUT);  // Operating mode definition for relay number 3.
}


void loop() {                         // Loop and operation function.
   int ldr = analogRead(A0);          // LDR sensor pin definition.
   while (Serial.available()) {       // Listening to the Bluetooth sensor.
    delay(3);  
    char c = Serial.read();
    flag += c; 
  }
  
  if (flag == "1 ON")                 // Operating condition for relay number 1.
  {
    digitalWrite(relay1, HIGH);       // Operation command for relay number 1.
    Serial.println("\nRELAY 1 ON");   // Writing the status information to the serial monitor. 
    delay(2000);
    hum = dht.readHumidity();         // Reading the humidity value.
    temp = dht.readTemperature();     // Reading the temperature value.
    Serial.print("Humidity: ");       // Printing the humidity label.
    Serial.print(hum);                // Humidity value.
    Serial.print(" %, Temperature: ");// Printing the temperature label.
    Serial.print(temp);               // Temperature value.
    Serial.print(" Celsius");         // Temperature unit.
    blue.print("RELAY 1 ON ");        // Writing info to the device connected via Bluetooth.
    blue.print("Humidity: ");         // Printing the humidity label.
    blue.print(hum);                  // Humidity value.
    blue.print(" %, Temperature: ");  // Printing the temperature label.
    blue.print(temp);                 // Temperature value.
    blue.println(" Celsius \n");      // Temperature unit.
  }
  
  if (ldr < 850)                  // Operating condition for relay number 1 based on LDR data.
  {                 
    digitalWrite(relay1, HIGH);
    Serial.println("\nRELAY 1 ON");
    delay(10000);
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temperature: ");
    Serial.print(temp);
    Serial.print(" Celsius");
    Serial.print("Ambient Light is Insufficient.");
    blue.print("RELAY 1 ON ");
    blue.print("Humidity: ");
    blue.print(hum);
    blue.print(" %, Temperature: ");
    blue.print(temp);
    blue.println(" Celsius \n");
    blue.print("Ambient Light is Insufficient.");
  }
  
  if (flag == "1 OFF")                 // Closing condition for relay number 1.
  {
    digitalWrite(relay1, LOW);         // Shut down command for relay number 1.
    Serial.println("\nRELAY 1 OFF");   // Writing the status information to the serial monitor. 
    delay(2000);
    hum = dht.readHumidity();         // Reading the humidity value.
    temp = dht.readTemperature();     // Reading the temperature value.
    Serial.print("Humidity: ");       // Printing the humidity label.
    Serial.print(hum);                // Humidity value.
    Serial.print(" %, Temperature: ");// Printing the temperature label.
    Serial.print(temp);               // Temperature value.
    Serial.print(" Celsius");         // Temperature unit.
    blue.print("RELAY 1 OFF ");       // Writing info to the device connected via Bluetooth.
    blue.print("Humidity: ");         // Printing the humidity label.
    blue.print(hum);                  // Humidity value.
    blue.print(" %, Temperature: ");  // Printing the temperature label.
    blue.print(temp);                 // Temperature value.
    blue.println(" Celsius \n");      // Temperature unit.
  }
  
    if (ldr > 900)        // Closing condition for relay number 1 based on LDR data.
    {                 
    digitalWrite(relay1, LOW);
    Serial.println("\nRELAY 1 OFF");
    delay(10000);
    hum = dht.readHumidity();                   // Reading the humidity value.
    temp = dht.readTemperature();               // Reading the temperature value.
    Serial.print("Humidity: ");                      // Printing the humidity label.
    Serial.print(hum);                          // Humidity value.
    Serial.print(" %, Temperature: ");             // Printing the temperature label.
    Serial.print(temp);                         // Temperature value.
    Serial.print(" Celsius");                   // Temperature unit.
    Serial.print("Ambient Light is Sufficient.");  // Writing ambient lighting info to the serial monitor.
    blue.print("RELAY 1 OFF ");                 // Writing info to the device connected via Bluetooth.
    blue.print("Humidity: ");                        // Printing the humidity label.
    blue.print(hum);                            // Humidity value.
    blue.print(" %, Temperature: ");               // Printing the temperature label.
    blue.print(temp);                           // Temperature value.
    blue.println(" Celsius \n");                // Temperature unit.
    blue.print("Ambient Light is Sufficient.");    // Writing ambient lighting info to the device connected via Bluetooth.
  }
  
  if (flag == "2 ON")                 // Operating condition for relay number 2.     
  {
    digitalWrite(relay2, HIGH);
    Serial.println("\nRELAY 2 ON");
    delay(2000);
    hum = dht.readHumidity();         // Reading the humidity value.
    temp = dht.readTemperature();     // Reading the temperature value.
    Serial.print("Humidity: ");            // Printing the humidity label.
    Serial.print(hum);                // Humidity value.
    Serial.print(" %, Temperature: ");   // Printing the temperature label.
    Serial.print(temp);               // Temperature value.
    Serial.print(" Celsius");         // Temperature unit.
    blue.print("RELAY 2 ON ");        // Writing info to the device connected via Bluetooth.
    blue.print("Humidity: ");              // Printing the humidity label.
    blue.print(hum);                  // Humidity value.
    blue.print(" %, Temperature: ");     // Printing the temperature label.
    blue.print(temp);                 // Temperature value.
    blue.println(" Celsius \n");      // Temperature unit.
  }
  
  if (flag == "2 OFF")                 // Closing condition for relay number 2.
  {
    digitalWrite(relay2, LOW);
    Serial.println("\nRELAY 2 OFF");
    delay(2000);
    hum = dht.readHumidity();         // Reading the humidity value.
    temp = dht.readTemperature();     // Reading the temperature value.
    Serial.print("Humidity: ");            // Printing the humidity label.
    Serial.print(hum);                // Humidity value.
    Serial.print(" %, Temperature: ");   // Printing the temperature label.
    Serial.print(temp);               // Temperature value.
    Serial.print(" Celsius");         // Temperature unit.
    blue.print("RELAY 2 OFF ");        // Writing info to the device connected via Bluetooth.
    blue.print("Humidity: ");              // Printing the humidity label.
    blue.print(hum);                  // Humidity value.
    blue.print(" %, Temperature: ");     // Printing the temperature label.
    blue.print(temp);                 // Temperature value.
    blue.println(" Celsius \n");      // Temperature unit.
  }
  
  if (flag == "3 ON")                 // Operating condition for relay number 3.     
  {
    digitalWrite(relay3, HIGH);
    Serial.println("\nRELAY 3 ON");
    delay(2000);
    hum = dht.readHumidity();         // Reading the humidity value.
    temp = dht.readTemperature();     // Reading the temperature value.
    Serial.print("Humidity: ");            // Printing the humidity label.
    Serial.print(hum);                // Humidity value.
    Serial.print(" %, Temperature: ");   // Printing the temperature label.
    Serial.print(temp);               // Temperature value.
    Serial.print(" Celsius");         // Temperature unit.
    blue.print("RELAY 3 ON ");        // Writing info to the device connected via Bluetooth.
    blue.print("Humidity: ");              // Printing the humidity label.
    blue.print(hum);                  // Humidity value.
    blue.print(" %, Temperature: ");     // Printing the temperature label.
    blue.print(temp);                 // Temperature value.
    blue.println(" Celsius \n");      // Temperature unit.
  }
  
  if (flag == "3 OFF")                 // Closing condition for relay number 3.
  {
    digitalWrite(relay3, LOW);
    Serial.println("\nRELAY 3 OFF");
    delay(2000);
    hum = dht.readHumidity();         // Reading the humidity value.
    temp = dht.readTemperature();     // Reading the temperature value.
    Serial.print("Humidity: ");            // Printing the humidity label.
    Serial.print(hum);                // Humidity value.
    Serial.print(" %, Temperature: ");   // Printing the temperature label.
    Serial.print(temp);               // Temperature value.
    Serial.print(" Celsius");         // Temperature unit.
    blue.print("RELAY 3 OFF ");       // Writing info to the device connected via Bluetooth.
    blue.print("Humidity: ");              // Printing the humidity label.
    blue.print(hum);                  // Humidity value.
    blue.print(" %, Temperature: ");     // Printing the temperature label.
    blue.print(temp);                 // Temperature value.
    blue.println(" Celsius \n");      // Temperature unit.
  }


  flag = "";
}


Nour al jawhari 