const int Led_R_pin = 9;
const int Led_G_pin = 10;
const int Led_B_pin = 11;
const int microphone_pin = 7;

int actualColour = 0;

void setup() 
{
  pinMode(Led_R_pin, OUTPUT);
  pinMode(Led_G_pin, OUTPUT);
  pinMode(Led_B_pin, OUTPUT);
}

void loop() 
{
  bool microphone = digitalRead(microphone_pin);  
  if (microphone)
  {
    actualColour++;
  }

  if (actualColour > 5)
  {
    actualColour = 0;
  }
  
  switch(actualColour)
  {
    case 0: setColor(255, 0, 0);  // red
            break;
    case 1: setColor(0, 255, 0);  // green
            break;
    case 2: setColor(0, 0, 255);  // blue
            break;
    case 3: setColor(255, 255, 0);  // yellow
            break;
    case 4: setColor(255, 0, 255);  // purple
            break;
    case 5: setColor(0, 255, 255);  // aqua
            break;
  }

  if (!microphone)
  {
    setColor(0, 0, 0);
  }

  delay(1);
}

void setColor(int red, int green, int blue)
{  
  analogWrite(Led_R_pin, red);
  analogWrite(Led_G_pin, green);
  analogWrite(Led_B_pin, blue);  
}
