// C++ code
//
const int btn = 8;
const int red = 6;
const int yellow = 4;
const int green = 2;
bool estado_btn = 0;

void light(int, int);
void btn_press();

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(btn) == LOW) 
  {
    estado_btn = !estado_btn;
    digitalWrite(red, estado_btn);
    while (digitalRead(btn) == LOW);
    delay(10000);
    light(yellow, 5000);
  	light(green, 15000);
  	light(yellow, 5000);
  }
  
  
}

void light(int btnled, int time){
 
  if(btnled == red){
	digitalWrite(red, HIGH);
 	digitalWrite(yellow, LOW);
  	digitalWrite(green, LOW);
    delay(time);
  }  
  else if(btnled == yellow){
	digitalWrite(red, LOW);
 	digitalWrite(yellow, HIGH);
  	digitalWrite(green, LOW);
    delay(time);
  }
  else if(btnled == green){
	digitalWrite(red, LOW);
 	digitalWrite(yellow, LOW);
  	digitalWrite(green, HIGH);
    delay(time);
  }
}

void btn_press(){
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(10000);
  light(yellow, 5000);
  light(green, 15000);
  loop();
}
