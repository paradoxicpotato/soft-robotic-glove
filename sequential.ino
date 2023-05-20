void sequential(){
  digitalWrite(SolValve7, HIGH);
  for(int i = 0; i<5; i++){

    switch(i){
      case 0:
        while(Pressure0 < Setpoint0){
          motor1.run(PWM0);
          digitalWrite(SolValve6, HIGH);
          read_pressure();
        }
      case 1:
        while(Pressure1 < Setpoint1){
          motor1.run(PWM1);
          digitalWrite(SolValve5, HIGH);
          read_pressure();
        }
      case 2:
        while(Pressure2 < Setpoint2){
          motor1.run(PWM2);
          digitalWrite(SolValve4, HIGH);
          read_pressure();
        }
      case 3:
        while(Pressure3 < Setpoint3){
          motor1.run(PWM3);
          digitalWrite(SolValve3, HIGH);
          read_pressure();
        }
      case 4:
        while(Pressure4 < Setpoint4){
          motor1.run(PWM4);
          digitalWrite(SolValve2, HIGH);
          read_pressure();
        }

    }
  }

  motor1.run(PWM4);
  read_pressure();
}