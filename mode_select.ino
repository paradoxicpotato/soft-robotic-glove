void mode_select(){
  Serial.println("Which mode would you like the glove to operate in?");
  Serial.println("1. Full hand");
  Serial.println("2. Sequential");
  Serial.println("3. Pinching");
  Serial.println("4. Individual");

  while (Serial.available() == 0){
    // Wait for user input before continuing
  }

  mode = Serial.parseInt();
}