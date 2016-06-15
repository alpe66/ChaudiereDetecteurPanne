int ldrE = 0;             //analog pin to which LDR is connected
int ldrE_value = 0;        //variable to store LDR values
int ldrB = 1;             //analog pin to which LDR is connected
int ldrB_value = 0;        //variable to store LDR values
int diff = 0;
// #include <VirtualWire.h>
 #include <ServoTimer2.h>
// #include <Servo.h>
const int SendDataPin = 10;      // the number of the Data pin
const int ReceDataPin = 11;      // the number of the Data pin
const char *msg = "Derangement"; // Tableau qui contient notre message
int IncomeMsg = 0;
// #include <wiring.h>

// #include <wire.h>

// Servo myServo;
 ServoTimer2 myServo;  // create a servo object
 myServo.attach(9);

void setup()
{
//  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);   //start te serial monitor

  pinMode(SendDataPin, OUTPUT);
  pinMode(ReceDataPin, INPUT);
/*  vw_setup(2000);     // initialisation de la librairie VirtualWire à 2000 bauds
  vw_set_tx_pin(SendDataPin);
  vw_set_rx_pin(ReceDataPin);
*/  
    myServo.write(90);
}  
void loop(){

  ldrE_value = analogRead(ldrE);          //reads the LDR values
  ldrB_value = analogRead(ldrB);          //reads the LDR values
  diff = ldrE_value - ldrB_value;
  IncomeMsg = digitalRead(ReceDataPin);
  if (IncomeMsg == 0) 
  {
    Serial.println("Probleme Chauffage");
          Serial.print("***** ");
      Serial.println(IncomeMsg);

 //    IncomeMsg = 0;
  }
  else
  {
      Serial.print("***** ");
      Serial.println(IncomeMsg);
    
  }  
  if (diff > 100)
  {
    myServo.write(40);
//    myServo.refresh();
    delay(500);
    myServo.write(90);
    delay(500);
//    myServo::refresh();
//    diff = 0;
    msg=("TELCHA;DETCHA;DERANGEMENT DE LA CHAUDIERE");
//    vw_send((uint8_t *)msg, strlen(msg)); // On envoie le message
    Serial.println(msg);
//    vw_wait_tx(); // On attend la fin de l'envoi
    Serial.println("Difference plus grande que 100");

  }
//  }
  
  Serial.println(ldrE_value);                 //prints the LDR values to serial monitor
  Serial.println(ldrB_value);              //prints the LDR values to serial monitor
  Serial.print("Difference : ");
  Serial.println(diff);                 //prints the LDR values to serial monitor
    delay(500);                  //wait
}

