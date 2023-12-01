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
  
  light(red, 15000);
  light(yellow, 5000);
  light(green, 15000);
  light(yellow, 5000);
}

void light(int btnled, unsigned long time) {
  
    if (btnled == red) {
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      for (int i = 0; i < time; i += 1000) {
        // Verifica o botão a cada intervalo definido
        if (digitalRead(btn) == LOW) {
          restart_lights(); 
          break;
        }
        delay(1000);
      } 
    } else if (btnled == yellow) {
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(yellow, HIGH);
      for (int i = 0; i < time; i += 1000) {
        // Verifica o botão a cada intervalo definido
        if (digitalRead(btn) == LOW) {
          restart_lights(); 
          break;
        }
        delay(1000);
      } 
    } else if (btnled == green) {
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      for (int i = 0; i < time; i += 1000) {
        // Verifica o botão a cada intervalo definido
        if (digitalRead(btn) == LOW) {
          restart_lights(); 
          break;
        }
        delay(1000);
      } 
    }
}


void restart_lights() {
  light(red, 10000);
  light(yellow, 5000);
  light(green, 15000);
  light(yellow, 5000);
}
