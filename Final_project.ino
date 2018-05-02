const int led1 =9;
const int led2 =2;
const int led3 =3;
const int led4 =4;
const int button1 =5;
const int button2 =6;
const int button3 =7;
const int button4 =8;
int sound = 11;
 int button_mode1, button_mode2, button_mode3, button_mode4;
long randnum;
int t= 2000;
int arr[100];
int arr1[100];
int game_lvl =4;
int final_lvl =16;
void setup() {
  // put your setup code here, to run once:
 
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(button3, INPUT);
pinMode(button4, INPUT);
pinMode(sound, OUTPUT);
Serial.begin(9600);
randomSeed(analogRead(0));


  
}
//turns on a random led by using the random function to generate a
//random number accociated with an LED.
void play_seq(int j){
  for(int i = 0; i<j;i++){
  
  randnum= random(1,5);
 delay(t);
  Serial.println(randnum);
 
    if(randnum ==1){
  digitalWrite(led1,HIGH);
  tone(sound, 1000);
  delay(t-1500);
  noTone(sound);
  digitalWrite(led1,LOW);
  }

  if(randnum ==2){
  digitalWrite(led2,HIGH);
  tone(sound, 2000);
  delay(t-1500);
  noTone(sound);
  digitalWrite(led2,LOW);
  }
  
  if(randnum ==3){
  digitalWrite(led3,HIGH); 
  tone(sound, 3000);
  delay(t-1500);
  noTone(sound);
  digitalWrite(led3,LOW);
  }
  
  if(randnum ==4){
  digitalWrite(led4,HIGH); 
  tone(sound, 4000);
  delay(t-1500);
  noTone(sound);
  digitalWrite(led4,LOW);
  }
  arr[i] = randnum;
}
}
// This function flashes the lights in sequence when the player 
//guesses all the sequences right.
void win(){
  digitalWrite(led1,HIGH);
  delay(500);
  digitalWrite(led2,HIGH);
  delay(500);
  digitalWrite(led3,HIGH);
  delay(500);
  digitalWrite(led4,HIGH);
  delay(500);

 digitalWrite(led1,LOW);
 digitalWrite(led2,LOW);
 digitalWrite(led3,LOW);
 digitalWrite(led4,LOW);
}
// this is a lose functio that flashes all the lights
//and plays a long tone if someone loses 
void lose(){
  for(int i=0; i<5; i++){
   digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);
   digitalWrite(led4,HIGH);
   tone(sound, 1433);
   delay(500);
 digitalWrite(led1,LOW);
 digitalWrite(led2,LOW);
 digitalWrite(led3,LOW);
 digitalWrite(led4,LOW);
  }
}


int guess_seq(){
 int x =0;
 button_mode1= digitalRead(button1);
button_mode2= digitalRead(button2);
button_mode3= digitalRead(button3);
button_mode4= digitalRead(button4);
  if(button_mode1==HIGH){
    digitalWrite(led1, HIGH);
     
    x=1;
   tone(sound, 1000);
 
  }
  else{
    digitalWrite(led1,LOW);
  }
  
  if(button_mode2==HIGH){
    digitalWrite(led2, HIGH);

     x=2;
  tone(sound, 2000);

   
  }
  else{
    digitalWrite(led2,LOW);
  }
  
  if(button_mode3==HIGH){
    digitalWrite(led3, HIGH);
     
        x=3;
    tone(sound, 3000);

  }
  else{
    digitalWrite(led3,LOW);
  }
  
if(button_mode4==HIGH){
    digitalWrite(led4, HIGH);
   
       x=4;
    tone(sound, 4000);
  }
  else{
    digitalWrite(led4,LOW);
  }

   
  return x;
  
 
}
// this function makes time for the LED to go off.
int check(){
  int b =0;
  if( digitalRead(led1)==HIGH){
    b=1;
  }
  if( digitalRead(led2)==HIGH){
    b=1;
  }
   if( digitalRead(led3)==HIGH){
    b=1;
  }
   if( digitalRead(led4)==HIGH){
    b=1;
  }
  return b;
}

void loop() {
  // put your main code here, to run repeatedly:
int a;
// the first for loop is for the level the person is on.
for(int k =0; k< final_lvl;k++){
  
  play_seq(game_lvl+k);
  delay(1000);
// this second for loop is for the player to guess the sequence 
for(int i =0; i < game_lvl+k;i++){
while(guess_seq()==0){
  
}

a =guess_seq();
 while(check()==1){
delay(500);
noTone(sound);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);

}

if(a == arr[i]){
  Serial.println("you are Right");
  

}
else{
  Serial.println("you are Wrong");
  lose();
  exit(0);
}
}
win();
if(k%2 ==0){
  t-50;
  speeds();
}

 }
 
}

void speeds(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

