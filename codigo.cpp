#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int celsius;
int l;
String c;
String s;


void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode( A0, INPUT);
  pinMode( 10, OUTPUT);//vermelho
  pinMode( 13, OUTPUT);//verde
}

void loop()
{
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  c = celsius;
  l=0;
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(c+" c");
  
  if(celsius < 60){	
    lcd.setCursor(1, 1);
    lcd.print("Status ativo");
    digitalWrite(10, LOW);
    digitalWrite(13, HIGH);
  }else{
    lcd.setCursor(1, 1);
    lcd.print("Status offline");
    digitalWrite(13, LOW);
    digitalWrite(10, HIGH);
  };
  delay(5000);
  while(l<5){
    s = l+1;
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Prox. Teste:");
    lcd.setCursor(1,1);
  	lcd.print(s+"s");
    delay(1000);
    l=l+1;
  }
}
