// C++ code
//
// Arduino UNO - Lab Sistemas Computacionais
const int btn = 2; 
const int red = 6;
const int yellow = 4;
const int green = 3; 

void light(int, unsigned long);
void restart_lights();

unsigned long lastButtonCheck = 0;
const unsigned long buttonCheckInterval = 100; 

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();

  light(red, 15000);
  light(yellow, 5000);
  light(green, 15000);
  light(yellow, 5000);
  
  // Verifica o botão a cada intervalo definido
  if (currentMillis - lastButtonCheck >= buttonCheckInterval) {
    lastButtonCheck = currentMillis;
    // Verifica se o botão foi pressionado
    if (digitalRead(btn) == LOW) {
      restart_lights(); 
    }
  }

  
}

void light(int btnled, unsigned long time) {
    if (btnled == red) {
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      delay(time);
    } else if (btnled == yellow) {
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(yellow, HIGH);
      delay(time);
    } else if (btnled == green) {
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      delay(time);
    }
  
}

void restart_lights() {
  light(red, 10000);
  light(yellow, 5000);
  light(green, 15000);
  light(yellow, 5000);
}
