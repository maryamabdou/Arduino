// C++ code
//
#define led 13
String setpassword = "";
String password = "";
String truepass = "";
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Set your password");  
  while (Serial.available()==0){}
      setpassword = Serial.readString(); //take the password from user
  Serial.println(setpassword);
  
  Serial.println("Enter your password");  
  while (Serial.available()==0){}
     password = Serial.readString(); //take the first try from user
  Serial.println(password);
}

void loop()
{
  for(int i=0;i<setpassword.length();i++){
    if(isalpha(setpassword[i])){ 
      if(setpassword[i]>='a' && setpassword[i]<='z'){ //if password is lower case
         char c = (((setpassword[i]-'a')+1)%26)+'a';
         truepass+=c; //change the password and put it in truepass
      }
      else if(setpassword[i]>='A' && setpassword[i]<='Z'){ //if password is upper case
         char c = (((setpassword[i]-'A')+1)%26)+'A';
         truepass+=c;
      }
    }
    else if(isdigit(setpassword[i])){ //if password is digit
      char c = (((setpassword[i]-'0')+1)%10)+'0';
      truepass+=c;
    }
  }
  if(password.equals(truepass)){ //led is turned on if password is correct
     digitalWrite(13,HIGH);
     delay(3000);
     digitalWrite(13,LOW);
  }
  else{
    for(int j=0;j<3;j++){ //led blinks if password is wrong
     digitalWrite(13, HIGH);
     delay(500);                       
     digitalWrite(13, LOW);   
     delay(500);
    }
  }
  setpassword=password;
  truepass="";
  Serial.println("Enter password again"); 
  while (Serial.available()==0){}
     password = Serial.readString(); //take the second try from user
  Serial.println(password);
}