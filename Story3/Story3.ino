int const reverse_left_motor = 12;
int const forward_left_motor = 11;
int const enable_left_motor = 10;
int const enable_right_motor = 9;
int const reverse_right_motor = 8;
int const forward_right_motor = 7;

void setup()
{
  pinMode(reverse_left_motor, OUTPUT); 
  pinMode(forward_left_motor, OUTPUT);
  pinMode(enable_left_motor, OUTPUT);
  pinMode(enable_right_motor, OUTPUT);
  pinMode(reverse_right_motor, OUTPUT);
  pinMode(forward_right_motor, OUTPUT);
}

void loop()
{
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(forward_left_motor, HIGH);
  digitalWrite(forward_right_motor, HIGH);
  delay(5000);
  digitalWrite(enable_left_motor, LOW);
  digitalWrite(enable_right_motor, LOW);
  digitalWrite(forward_left_motor, LOW);
  digitalWrite(forward_right_motor, LOW);
  delay(1000);
  digitalWrite(enable_left_motor, HIGH);
  digitalWrite(enable_right_motor, HIGH);
  digitalWrite(reverse_left_motor, HIGH);
  digitalWrite(reverse_right_motor, HIGH);
  delay(2000);
  digitalWrite(enable_left_motor, LOW);
  digitalWrite(enable_right_motor, LOW);
  digitalWrite(reverse_left_motor, LOW);
  digitalWrite(reverse_right_motor, LOW);
}
