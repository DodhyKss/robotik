String stringOne; // variabel ini digunakan untuk menyimpan data yang telah diambil dari serial dalam bentuk string
String data[3]; //array ini digunakan untuk menyimpan 3 data yang telah diparsing dalam bentuk string
int x=0; // ketiga data ini x,y,z adalah variabel yang digunakan untuk menyimpan 3 data yang telah diparsing dalam bentuk integer
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
      stringOne = Serial.readString(); // mengambil data dari serial dan disimpan dalam bentuk string
      int q = 0; // variabel ini digunakan sebagai counter
     
     /*ketiga for di bawah digunakan untuk memisahkan data yang telah disimpan di stringOne, misalkan data yang diterima adalah 128#223@543$
     maka tersebut dari index 0,1,2 akan disimpan pada array data[] pada index 0 (pertama) dan begitupun untuk 3 index berikutnya hinggan data[] index 2(ketiga)*/
     
     /*karena data yang dikirim adalah 3 maka untuk memisahkan data tersebut kita menambahkan simbol yaitu #,@ dan $*/
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
