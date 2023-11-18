int red1=3;
int green1=2;
int red2=5;
int green2=4;
int red3=7;
int green3=6;
int red4=9;
int green4=8;

void setup() {
  Serial.begin(9600);
  pinMode(red1,OUTPUT);
  pinMode(green1,OUTPUT);
  pinMode(red2,OUTPUT);
  pinMode(green2,OUTPUT);
  pinMode(red3,OUTPUT);
  pinMode(green3,OUTPUT);
  pinMode(red4,OUTPUT);
  pinMode(green4,OUTPUT);
}

void loop() {
  initial_position();
}

void serial_event(){
  if(Serial.available() > 0){
    String data = Serial.readString();
    Serial.println(data);    
    char e = data[0];   
    Serial.println(e);       
    if(e == 'A'){
        road1(3);
    }
    else if(e == 'B'){
        road2(3);      
    }
    else if(e == 'C'){
        road3(3);      
    }
    else if(e == 'D'){
        road4(3);      
    }
    else{
      int r1 = data[0]-48;  
      int r2 = data[1]-48;
      int r3 = data[2]-48;
      int r4 = data[3]-48;

      int a, i, j, k, m;
      char b;
      int num[] = {r1, r2, r3, r4};
      char rd[] = "ABCD";

      for (i = 0; i < 4; ++i){
        for (j = i + 1; j < 4; ++j){
          if (num[i] < num[j]){
              a = num[i];
              b = rd[i];
              num[i] = num[j];
              rd[i] = rd[j];
              num[j] = a;
              rd[j] = b;
          }
        }
      }
      
      for(k=0; k<4;k++){
      Serial.print(rd[k]);
      Serial.print(num[k]);
      }
      Serial.println("");
      for(m=0; m<4;m++){
        if(rd[m] == 'A'){
          road1(num[m]);
        }
        if(rd[m] == 'B'){
          road2(num[m]);
        }
        if(rd[m] == 'C'){
          road3(num[m]);
        }
        if(rd[m] == 'D'){
          road4(num[m]);
        }
      }  
    }     
  }          
}

void initial_position(){
  road1(1);
  road2(1);
  road3(1);
  road4(1);  
}

void road1(int C)
{
  digitalWrite(red1,LOW);
  digitalWrite(green1,HIGH);
  digitalWrite(red2,HIGH);
  digitalWrite(green2,LOW);
  digitalWrite(red3,HIGH);
  digitalWrite(green3,LOW);
  digitalWrite(red4,HIGH);
  digitalWrite(green4,LOW); 
  delay(C*1000);
  serial_event();   
}

void road2(int C)
{
  digitalWrite(red1,HIGH);
  digitalWrite(green1,LOW);
  digitalWrite(red2,LOW);
  digitalWrite(green2,HIGH);
  digitalWrite(red3,HIGH);
  digitalWrite(green3,LOW);
  digitalWrite(red4,HIGH);
  digitalWrite(green4,LOW); 
  delay(C*1000);   
  serial_event(); 
}

void road3(int C)
{
  digitalWrite(red1,HIGH);
  digitalWrite(green1,LOW);
  digitalWrite(red2,HIGH);
  digitalWrite(green2,LOW);
  digitalWrite(red3,LOW);
  digitalWrite(green3,HIGH);
  digitalWrite(red4,HIGH);
  digitalWrite(green4,LOW); 
  delay(C*1000);  
  serial_event();  
}

void road4(int C)
{
  digitalWrite(red1,HIGH);
  digitalWrite(green1,LOW);
  digitalWrite(red2,HIGH);
  digitalWrite(green2,LOW);
  digitalWrite(red3,HIGH);
  digitalWrite(green3,LOW);
  digitalWrite(red4,LOW);
  digitalWrite(green4,HIGH); 
  delay(C*1000);
  serial_event();    
}