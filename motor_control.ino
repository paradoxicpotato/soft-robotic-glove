void motor_control(){

  motor1.run(FORWARD);
  switch(mode){
    case 1:
      motor1.setSpeed(PWM4);
      read_pressure();
      full_hand();

    case 2:
      sequential();
  }
}