void full_hand(){
  unsigned long currentMillis = millis();

  const long interval = 10000;

  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    Serial.println(currentMillis);
    Serial.println(press_state);
      if(press_state == 1){
        press_state = 0;
      }

      else{
        press_state = 1;
      }

  }

  if(press_state == 1){
    
        digitalWrite(SolValve8, LOW);
        digitalWrite(SolValve7, HIGH);

        digitalWrite(SolValve2, HIGH);
        digitalWrite(SolValve3, HIGH);
        digitalWrite(SolValve4, HIGH);
        digitalWrite(SolValve5, HIGH);
        digitalWrite(SolValve6, HIGH);
  }

  else{
      digitalWrite(SolValve8, HIGH);
      digitalWrite(SolValve7, LOW);

      digitalWrite(SolValve1, HIGH);
      digitalWrite(SolValve2, HIGH);
      digitalWrite(SolValve3, HIGH);
      digitalWrite(SolValve4, HIGH);
      digitalWrite(SolValve5, HIGH);
      digitalWrite(SolValve6, HIGH);
  }

}