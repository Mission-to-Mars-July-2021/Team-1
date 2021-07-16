int const reverse_left_motor = 12;
int const forward_left_motor = 11;
int const enable_left_motor = 10;
int const enable_right_motor = 9;
int const reverse_right_motor = 8;
int const forward_right_motor = 7;

const int LEFT_FEEDBACK = 3;
const int RIGHT_FEEDBACK = 2;


volatile int leftcounter = 0;
volatile int rightcounter = 0;

int leftMotorSpeed = 150;
int rightMotorSpeed = 150;

void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  pinMode(reverse_left_motor, OUTPUT); 
  pinMode(forward_left_motor, OUTPUT);
  pinMode(LEFT_FEEDBACK, INPUT);
  pinMode(RIGHT_FEEDBACK, INPUT);
  pinMode(enable_left_motor, OUTPUT);
  pinMode(enable_right_motor, OUTPUT);
  pinMode(reverse_right_motor, OUTPUT);
  pinMode(forward_right_motor, OUTPUT);
  forwards_rover_without_delay();
  SetLeftMotor(100);
  SetRightMotor(100);
}

void loop()
{

  for(int i  = 0; i < 4; i++) {
    forwards_rover(1500);
    stop_rover(500);
    turn_left_rover(710);
    stop_rover(500);
  }
  for(int i  = 0; i < 4; i++) {
    forwards_rover(1500);
    stop_rover(500);
    turn_right_rover(790);
    stop_rover(500);
  
  
  }
  
  
  stop_rover(500000); //ok
}



void straight_line() {
  forwards_rover_variable_speed();
  
  if(leftcounter > rightcounter){
  rightMotorSpeed = 255;
    leftMotorSpeed = 100;
    
  } 
  else if(leftcounter < rightcounter){
  leftMotorSpeed = 255;
    rightMotorSpeed = 100;
  } 
  else{
  leftMotorSpeed = 150;
    rightMotorSpeed = 150;
  }
  
  if(millis() >= 10000) {
    stop_rover(100000);
  }
  
  delay(100);
  
}


void SetLeftMotor(int speed) {
  analogWrite(enable_left_motor, speed);
  //analogWrite(forward_left_motor, speed);
}

void SetRightMotor(int speed) {
  analogWrite(enable_right_motor, speed);
  //analogWrite(forward_right_motor, speed);
}

void distancemeasurement() {
  forwards_rover(0);
  //Serial.print("Left Counter ");
  //Serial.println(leftcounter);
  
  //Serial.print("Right Counter ");
  //Serial.println(rightcounter);
  
  if(leftcounter >=870){
    Serial.println("Stop called");
    stop_rover(100000000);
  }

}
void stop_rover(int length) {
  digitalWrite(enable_left_motor, LOW);
  digitalWrite(enable_right_motor, LOW);
  digitalWrite(forward_left_motor, LOW);
  digitalWrite(forward_right_motor, LOW);
  digitalWrite(reverse_left_motor, LOW);
  digitalWrite(reverse_right_motor, LOW);

  delay(length); 
}
void stop_rover_after(int length, int duration) {
  delay(length);
  stop_rover(duration);
}

void reverse_rover(int duration) {
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(reverse_left_motor, HIGH);
  digitalWrite(reverse_right_motor, HIGH);
  delay(duration);
}  
void turn_left_rover(int duration) {
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(reverse_left_motor, HIGH); // on
  digitalWrite(reverse_right_motor, LOW);
  digitalWrite(forward_left_motor, LOW);
  digitalWrite(forward_right_motor, HIGH); // on
  delay(duration);
}  

void turn_right_rover(int duration) {
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(reverse_left_motor, LOW); // on
  digitalWrite(reverse_right_motor, HIGH);
  digitalWrite(forward_left_motor, HIGH);
  digitalWrite(forward_right_motor, LOW); // on
  delay(duration);
}  

void forwards_rover(int timedelay){
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(forward_left_motor, HIGH);
  digitalWrite(forward_right_motor, HIGH);
  delay(timedelay);
}

void forwards_rover_without_delay(){
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(forward_left_motor, HIGH);
  digitalWrite(forward_right_motor, HIGH);
}

void forwards_rover_variable_speed(){
  analogWrite(enable_left_motor, leftMotorSpeed);
  analogWrite(enable_right_motor, rightMotorSpeed);
  digitalWrite(forward_left_motor, HIGH);
  digitalWrite(forward_right_motor, HIGH);
}

void LeftMotorISR(){
  
  leftcounter++;
}

void RightMotorISR(){
  rightcounter++;
}  
