# define trig 9
# define echo 10
# define Speed 11
int motor;
long duration;
int distance;
void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);;
  pinMode(Speed,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  Serial.println(distance);
  if(distance<200 || distance>2){
  motor=map(distance,3,199,8000,2000);
  analogWrite(Speed,motor);
  }else
  {analogWrite(Speed,0);}
}