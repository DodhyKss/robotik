String stringOne;
String data[3];
int x=0;
int y=0;
int z=0;

void setup() {
 Serial.begin(115200);
 Serial.setTimeout(1);
}

void loop() {
  bacaDataCam();
  Serial.print(data[1]);
  x = data[0].toInt();
  y = data[1].toInt();
  z = data[2].toInt();
  stringOne="";
  data[0]="";
  data[1]="";
  data[2]="";
}

void bacaDataCam(){
    if(Serial.available()>0){
      delay(10);
      stringOne = Serial.readString();
      int q = 0;
      for(int i=0;i<stringOne.length();i++){
        if(stringOne[i] == '#'){
          q = i;
          break;
        } else {
          data[0] = data[0] + stringOne[i]; 
        }
        
      }
      for(int j=q+1;j<stringOne.length();j++){
        if(stringOne[j] == '@'){
          q = j;
          break;
        } else {
          data[1] = data[1] + stringOne[j]; 
        }
        
      }
      for(int k=q+1;k<stringOne.length();k++){
        if(stringOne[k] == '$'){
          break;
        } else {
          data[2] = data[2] + stringOne[k];
        }
      }
      q = 0;
  }
}
