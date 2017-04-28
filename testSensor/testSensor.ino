

#include <StandardCplusplus.h>

#include <vector>


using namespace std;

int sensor1 = 2;
int sensor2 = 3;
bool checkIn = false;
bool checkIn1 = false;

vector<int> val;

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  maClick();
//  delay(1000);
}
void maClick() {
  int num = digitalRead(sensor1);
  int num1 = digitalRead(sensor2);


  //
  if (num == 0 && checkIn == false ) {
    val.push_back(1);
    checkIn = true;
  }
  if (num1 == 0 && checkIn1 == false) {
    val.push_back(2);
    checkIn1 = true;
  }
  //
  if (val[0] == 1 && val[1] == 2) {
    Serial.println("+1");
    delay(5000);
  } else if (val[0] == 2 && val[1] == 1) {
    
    Serial.println("-1");
    delay(5000);
  }
  Serial.print("val[0] :");
  Serial.println(val[0]);
  Serial.print("val[1] :");
  Serial.println(val[1]);
  Serial.println("------------------");
  Serial.print("size :");
  Serial.println(val.size());

  if (checkIn == true && checkIn1 == true) {
    checkIn = false;
    checkIn1 = false;
  }


  if (val.size() >= 2) {
    val[0]=0;
    val[1]=0;
    val.erase(val.begin(),val.begin()+2);
  }


}

