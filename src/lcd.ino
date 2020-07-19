#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int freqUp = 6;
const int freqDown = 7;
const int depthUp = 8;
const int depthDown = 9;
int frequency = 10;
int depth = 1;
String pumps = " squeezes/min";
String inches = " inches";
int delayTime = 2000;

void setup() {
    lcd.begin(16, 2);
    lcd.print("Ventilator");
    pinMode(freqUp, INPUT);
    pinMode(freqDown, INPUT);
    pinMode(depthUp, INPUT);
    pinMode(depthDown, INPUT);
   
    Serial.begin(9600);
   
}

void loop() {
    //increase frequency
    if(digitalRead(freqUp)){
        lcd.clear();
        frequency += 1;
        if(frequency > 30){
            frequency -= 1;
            lcd.setCursor(0, 0);
            lcd.print("Frequency");
            lcd.setCursor(0, 1);
            lcd.print("Too High!");
        }
        else{
            lcd.setCursor(0, 0);
            lcd.print("Frequency:");
            lcd.setCursor(0, 1);
            String temp = frequency + pumps;
            lcd.print(temp);
        }
        delay(delayTime);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ventilator");
    }
    //decrease frequency
    if(digitalRead(freqDown)){
        lcd.clear();
        frequency -= 1;
        if(frequency < 10){
            frequency += 1;
            lcd.setCursor(0, 0);
            lcd.print("Frequency");
            lcd.setCursor(0, 1);
            lcd.print("Too Low!");
        }
        else{
            lcd.setCursor(0, 0);
            lcd.print("Frequency:");
            lcd.setCursor(0, 1);
            String temp = frequency + pumps;
            lcd.print(temp);
        }
        delay(delayTime);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ventilator");
    }
    //increase depth
    if(digitalRead(depthUp)){
        lcd.clear();
        depth += 1;
        if(depth > 10){
            depth -= 1;
            lcd.setCursor(0, 0);
            lcd.print("Depth");
            lcd.setCursor(0, 1);
            lcd.print("Too High!");
        }
        else{
            lcd.setCursor(0, 0);
            lcd.print("Depth:");
            lcd.setCursor(0, 1);
            String temp = depth + inches;
            lcd.print(temp);
        }
        delay(delayTime);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ventilator");
    }
    //decrease depth
    if(digitalRead(depthDown)){
        lcd.clear();
        depth -= 1;
        if(depth < 1){
            depth += 1;
            lcd.setCursor(0, 0);
            lcd.print("Depth:");
            lcd.setCursor(0, 1);
            lcd.print("Too Low!");
        }
        else{
            lcd.setCursor(0, 0);
            lcd.print("Depth:");
            lcd.setCursor(0, 1);
            String temp = depth + inches;
            lcd.print(temp);
        }
        delay(delayTime);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ventilator");
    }
    delay(100);
}


