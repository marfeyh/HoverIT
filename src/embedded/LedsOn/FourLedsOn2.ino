int ledPin1 = 2;
int ledPin2 = 4;
int ledPin3 = 7;
int ledPin4 = 8;
int timer1 = 10000;
int timer2 = 7500;
int timer3 = 5000;

void setup()
{
  pinMode(ledPin1, OUTPUT);
   pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
     pinMode(ledPin4, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  delay(timer1);
  digitalWrite(ledPin1,LOW);
  delay(timer2);
  digitalWrite(ledPin2,LOW);
  delay(timer3);
  digitalWrite(ledPin3,LOW);
  delay(timer2);
} 
 
