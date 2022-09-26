//Tahir Can Yıldız 180201025
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#define button1 11
#define button2 10
#define button3 9
#define button4 8
#define button5 7
#define button6 6
bool read;
int button1stt=-1;
int button2stt=-1;
int button3stt=-1;
int button4stt=-1;
int button5stt=-1;
int button6stt=-1;
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
byte _5, _10, _20, _50, _100;
byte kop, yik, kur, cil;
int bakiye, bakiyetemp;
char str[10];
bool mode;
bool para;
void setup() {
lcd.begin(16, 2);
Serial.begin(9600);
pinMode(button1, INPUT); 
pinMode(button2, INPUT);
pinMode(button3, INPUT);
pinMode(button4, INPUT);
pinMode(button5, INPUT);
pinMode(button6, INPUT);
lcd.write("Hosgeldiniz...");
delay(1000);
lcd.clear();
lcd.write("Bakiye giriniz...");
delay(1000);
bakiyeyazdir();

 //KASA BİLGİSİ
  EEPROM.write(0, 0); // 5 TL
  EEPROM.write(1, 0); // 10 TL
  EEPROM.write(2, 0); // 20 TL
  EEPROM.write(3, 0); // 50 TL
  EEPROM.write(4, 0); // 100 TL

  /*HİZMET BİLGİLERİ*///////////////////////

  //KÖPÜKLEME
  EEPROM.write(5, 1); // KÖPÜKLEME ID
  EEPROM.write(6, 30); // KALAN HİZMET
  EEPROM.write(7, 15); // HİZMET FİYATI

  //YIKAMA
  EEPROM.write(8, 2); // YIKAMA ID
  EEPROM.write(9, 50); // KALAN HİZMET
  EEPROM.write(10, 10); // HİZMET FİYATI

  //KURULAMA
  EEPROM.write(11, 3); // KURULAMA ID
  EEPROM.write(12, 100); // KALAN HİZMET
  EEPROM.write(13, 5); // HİZMET FİYATI

  //CİLALAMA
  EEPROM.write(14, 4); // CİLALAMA ID
  EEPROM.write(15, 20); // KALAN HİZMET
  EEPROM.write(16, 50); // HİZMET FİYATI

  Serial.println("----- KASADAKI PARA -----");
  Serial.print("5TL  :");Serial.println(EEPROM.read(0));
  Serial.print("10TL :");Serial.println(EEPROM.read(1));
  Serial.print("20TL :");Serial.println(EEPROM.read(2));
  Serial.print("50TL :");Serial.println(EEPROM.read(3));
  Serial.print("100TL :");Serial.println(EEPROM.read(4));
  Serial.println("----- HIZMET BILGISI  -----");
  Serial.print("Kopukleme :");Serial.println(EEPROM.read(6));
  Serial.print("Yikama    :");Serial.println(EEPROM.read(9));
  Serial.print("Kurulama  :");Serial.println(EEPROM.read(12));
  Serial.print("Cilalama  :");Serial.println(EEPROM.read(15));
 
}
void loop() {

    read=digitalRead(button1);
     if(read)
     {
        if(button1stt == -1)
          button1func();
        else if(button1stt != read)
          button1func();
    }
    button1stt = read;
    read=digitalRead(button2);
    if(read)
    {
        if(button2stt == -1)
          button2func();
        else if(button2stt != read)
          button2func();
    }
    button2stt = read;
    read=digitalRead(button3);
    if(read)
    {
        if(button3stt == -1)
          button3func();
        else if(button3stt != read)
          button3func();
    }
    button3stt = read;
    read=digitalRead(button4);
    if(read)
    {
        if(button4stt == -1)
          button4func();
        else if(button4stt != read)
          button4func();
    }
    button4stt = read;
    read=digitalRead(button5);
    if(read)
    {
        if(button5stt == -1)
          button5func();
        else if(button5stt != read)
          button5func();
    }
    button5stt = read;
    read=digitalRead(button6);
    if(read)
    {
        if(button6stt == -1)
          button6func();
        else if(button6stt != read)
          button6func();
    }
    button6stt = read;
}



void button1func()
{
  if(para) return;
  if(!mode)
  {
    Serial.println("buton1 basıldı");
   _5++; 
    bakiye+=5;
    bakiyeyazdir();
  }
  else
  {
    lcd.clear();
    Serial.println("buton1 basildi");
    if(EEPROM.read(6)==0)
      lcd.write("Yetersiz Malzeme");
    else if(bakiyetemp < 15)
      lcd.write("Yetersiz Bakiye");
    else {
      kop++;
      tostring(str, kop);
      EEPROM.write(6, EEPROM.read(6)-1);
      lcd.write("Kopukleme: ");
      lcd.write(str);
      bakiyetemp-=EEPROM.read(7);
      lcd.setCursor(0,1);
      lcd.write("Bakiye: ");
      tostring(str, bakiyetemp);
      lcd.write(str);
    }    
  }
}
void button2func()
{
  if(para) return;
  if(!mode)
  {
    Serial.println("buton2 basıldı");
  _10++;
  bakiye+=10;
  bakiyeyazdir();
  }
  else
  {
    lcd.clear();
    Serial.println("buton2 basıldı");
    if(EEPROM.read(9)==0)
      lcd.write("Yetersiz Malzeme");
    else if(bakiyetemp < 10)
      lcd.write("Yetersiz Bakiye");
      else{
    yik++;
    tostring(str, yik);
    EEPROM.write(9, EEPROM.read(9)-1);
    lcd.clear();
    lcd.write("Yikama: ");
    lcd.write(str);
    bakiyetemp-=EEPROM.read(10);
      lcd.setCursor(0,1);
      lcd.write("Bakiye: ");
      tostring(str, bakiyetemp);
      lcd.write(str);
      }
  }
}
void button3func()
{
  if(para) return;
  if(!mode)
  {
    Serial.println("buton3 basıldı");
    _20++;    
  bakiye+=20;
  bakiyeyazdir();
  }
    else
  {
    lcd.clear();
    Serial.println("buton3 basıldı");
    if(EEPROM.read(12)==0)
      lcd.write("Yetersiz Malzeme");
    else if(bakiyetemp < 5)
      lcd.write("Yetersiz Bakiye");
      else{
    kur++;
    tostring(str, kur);
        EEPROM.write(12, EEPROM.read(12)-1);
    lcd.clear();
    lcd.write("Kurulama: ");
    lcd.write(str);
    bakiyetemp-=EEPROM.read(13);
      lcd.setCursor(0,1);
      lcd.write("Bakiye: ");
      tostring(str, bakiyetemp);
      lcd.write(str);
  }
  }
}
void button4func()
{if(para) return;
 if(!mode)
  {
    Serial.println("buton4 basıldı");
   _50++;    
  bakiye+=50;
  bakiyeyazdir();
  }
  else
  {
    lcd.clear();
    Serial.println("buton4 basıldı");  
    if(EEPROM.read(15)==0)
      lcd.write("Yetersiz Malzeme");
    else if(bakiyetemp < 50)
      lcd.write("Yetersiz Bakiye");
      else{
    cil++;
    tostring(str, cil);
    EEPROM.write(15, EEPROM.read(15)-1);
    lcd.clear();
    lcd.write("Cilalama: ");
    lcd.write(str);
    bakiyetemp-=EEPROM.read(16);
      lcd.setCursor(0,1);
      lcd.write("Bakiye: ");
      tostring(str, bakiyetemp);
      lcd.write(str);
  }
  }
}
void button5func()
{
  if(para) return;
  if(!mode)
  {
    Serial.println("buton5 basıldı");
    _100++;   
  bakiye+=100;
  bakiyeyazdir();
  }
  else
  {
    lcd.clear();
    Serial.println("buton5 basıldı");
    lcd.write("Yapiliyor...");
    delay(2000);
    lcd.clear();
    int rnd = random(1,5);
    if(rnd==2)
    {
      EEPROM.write(6, EEPROM.read(6)+kop);
      EEPROM.write(9, EEPROM.read(9)+yik);
      EEPROM.write(12, EEPROM.read(12)+kur);
      EEPROM.write(15, EEPROM.read(15)+cil);
      kop=yik=kur=cil=0;
      bakiye=0;
      mode=0;
      lcd.clear();
      lcd.write("Para sikisti.");
      delay(1000);
      para=1;
    }
    else
    {
      lcd.clear();
      lcd.write("islemleriniz");
      lcd.setCursor(0,1);
      lcd.write("yapildi");
      delay(1500);
      para=0;
      bakiye=bakiyetemp;
      bakiyeyazdir();
      delay(1000);
      int paraustu=bakiye;
      int ust100=0,ust50=0,ust20=0,ust10=0,ust5=0;
    while(paraustu>0)
    {
     if(paraustu/100>0)
      {
        if(EEPROM.read(4)>0){ust100++;paraustu-=100; EEPROM.write(4,EEPROM.read(4)-1);} 
        else if(EEPROM.read(3)>0){ust50++;paraustu-=50;EEPROM.write(3,EEPROM.read(3)-1);}
        else if(EEPROM.read(2)>0){ust20++;paraustu-=20;EEPROM.write(2,EEPROM.read(2)-1);}   
        else if(EEPROM.read(1)>0){ust10++;paraustu-=10;EEPROM.write(1,EEPROM.read(1)-1);}   
        else if(EEPROM.read(0)>0){ust5++;paraustu-=5;EEPROM.write(0,EEPROM.read(0)-1);}
        else
      {
        para=1;paraustu=0;
       Serial.println("Yeterli banknot yoktur!!!");
       lcd.clear();
       lcd.write("yeterli banknot");
       lcd.setCursor(0,1);
       lcd.write("yoktur");
       delay(1500);
       lcd.clear();
      lcd.write("Lütfen reset");
       lcd.setCursor(0,1);
       lcd.write("butonuna basiniz");
       delay(1500);       
      }      
      }
      else if(paraustu/50>0)
      {
       if(EEPROM.read(3)>0){ust50++;paraustu-=50;EEPROM.write(3,EEPROM.read(3)-1);} 
       else if(EEPROM.read(2)>0){ust20++;paraustu-=20;EEPROM.write(2,EEPROM.read(2)-1);}   
       else if(EEPROM.read(1)>0){ust10++;paraustu-=10;EEPROM.write(1,EEPROM.read(1)-1);}   
       else if(EEPROM.read(0)>0){ust5++;paraustu-=5;EEPROM.write(0,EEPROM.read(0)-1);} 
       else
      {
      para=1;paraustu=0;
       Serial.println("Yeterli banknot yoktur!!!");
       lcd.clear();
       lcd.write("yeterli banknot");
       lcd.setCursor(0,1);
       lcd.write("yoktur");
       delay(1500);
        lcd.clear();
      lcd.write("Lütfen reset");
       lcd.setCursor(0,1);
       lcd.write("butonuna basiniz");
       delay(1500);
      }    
      }
      else if(paraustu/20>0)
      {
       if(EEPROM.read(2)>0){ust20++;paraustu-=20;EEPROM.write(2,EEPROM.read(2)-1);}      
       else if(EEPROM.read(1)>0){ust10++;paraustu-=10;EEPROM.write(1,EEPROM.read(1)-1);}   
       else if(EEPROM.read(0)>0){ust5++;paraustu-=5;EEPROM.write(0,EEPROM.read(0)-1);}
       else
      {
      para=1;paraustu=0;
       Serial.println("Yeterli banknot yoktur!!!");
       lcd.clear();
       lcd.write("yeterli banknot");
       lcd.setCursor(0,1);
       lcd.write("yoktur");
       delay(1500);
        lcd.clear();
      lcd.write("Lütfen reset");
       lcd.setCursor(0,1);
       lcd.write("butonuna basiniz");
       delay(1500);
      }
      }
       else if(paraustu/10>0)
      {
       if(EEPROM.read(1)>0){ust10++;paraustu-=10;EEPROM.write(1,EEPROM.read(1)-1);}  
       else if(EEPROM.read(0)>0){ust5++;paraustu-=5;EEPROM.write(0,EEPROM.read(0)-1);} 
       else
      {
       para=1;paraustu=0;
       Serial.println("Yeterli banknot yoktur!!!");
       lcd.clear();
       lcd.write("yeterli banknot");
       lcd.setCursor(0,1);
       lcd.write("yoktur");
       delay(1500);
        lcd.clear();
      lcd.write("Lütfen reset");
       lcd.setCursor(0,1);
       lcd.write("butonuna basiniz");
       delay(1500);
      }   
      }
      else if(paraustu/5>0)
      {
       if(EEPROM.read(0)>0){ust5++;paraustu-=5;EEPROM.write(0,EEPROM.read(0)-1);}
       else
      {
      para=1;paraustu=0;
       Serial.println("Yeterli banknot yoktur!!!");
       lcd.clear();
       lcd.write("yeterli banknot");
       lcd.setCursor(0,1);
       lcd.write("yoktur");
       delay(1500);
        lcd.clear();
      lcd.write("Lütfen reset");
       lcd.setCursor(0,1);
       lcd.write("butonuna basiniz");
       delay(1500);
      }
      }
      else
      {
       para=1;paraustu=0;
       Serial.println("Yeterli banknot yoktur!!!");
       lcd.clear();
       lcd.write("yeterli banknot");
       lcd.setCursor(0,1);
       lcd.write("yoktur");
       delay(1500);
        lcd.clear();
      lcd.write("Lütfen reset");
       lcd.setCursor(0,1);
       lcd.write("butonuna basiniz");
       delay(1500);
      }
    }    
      Serial.println("-----PARA USTU -----");
      Serial.print("100TL :");Serial.println(ust100);
      Serial.print("50TL  :"); Serial.println(ust50);
      Serial.print("20TL  :");Serial.println(ust20);
      Serial.print("10TL  :");Serial.println(ust10);
      Serial.print("5TL   :");Serial.println(ust5);
      lcd.clear();
      if(ust100>0)
      {
        lcd.write("100TL :");
        tostring(str,ust100);
        lcd.write(str);
         delay(1000);
      }      
        lcd.clear();
      if(ust50>0)
      {
        lcd.write("50TL :");
        tostring(str,ust50);
        lcd.write(str);
        delay(1000);
      }     
      lcd.clear();
      if(ust20>0)
      {
        lcd.write("20TL :");
        tostring(str,ust20);
        lcd.write(str);
        delay(1000);
      }     
      lcd.clear();
      if(ust10>0)
      {
        lcd.write("10TL :");
        tostring(str,ust10);
        lcd.write(str);
        delay(1000);
      }    
      lcd.clear();
      if(ust5>0)
      {
        lcd.write("5TL :");
        tostring(str,ust5);
        lcd.write(str);
        delay(1000);
      }     
   if(para==0) 
   {  
      lcd.clear();
  Serial.println("----- KASADA KALAN PARA -----");
  Serial.print("5TL :");Serial.println(EEPROM.read(0));
  Serial.print("10TL :");Serial.println(EEPROM.read(1));
  Serial.print("20TL :");Serial.println(EEPROM.read(2));
  Serial.print("50TL :");Serial.println(EEPROM.read(3));
  Serial.print("100TL :");Serial.println(EEPROM.read(4));
  Serial.println("-----  KALAN HIZMET -----");
  Serial.print("Kopukleme :");Serial.println(EEPROM.read(6));
  Serial.print("Yikama :");Serial.println(EEPROM.read(9));
  Serial.print("Kurulama :");Serial.println(EEPROM.read(12));
  Serial.print("Cilalama :");Serial.println(EEPROM.read(15));
  delay(3000);
      kop=yik=kur=cil=0; bakiye=0; mode=0; 
      lcd.clear();
      _5=_10=_20=_50=_100=0;
      lcd.write("Hosgeldiniz...");
      delay(1000);
      lcd.clear();
      lcd.write("Bakiye giriniz...");
      delay(1000);
   }
    }  
  }
}
void button6func()
{   
  if(para)
  {
      EEPROM.write(6, EEPROM.read(6)+kop);
      EEPROM.write(9, EEPROM.read(9)+yik);
      EEPROM.write(12, EEPROM.read(12)+kur);
      EEPROM.write(15, EEPROM.read(15)+cil);
      kop=yik=kur=cil=0;    
      bakiye=0;
      mode=0;
      para=0;
      lcd.clear();
      EEPROM.write(0,EEPROM.read(0)-_5);
      EEPROM.write(1,EEPROM.read(1)-_10);
      EEPROM.write(2,EEPROM.read(2)-_20);
      EEPROM.write(3,EEPROM.read(3)-_50);
      EEPROM.write(4,EEPROM.read(4)-_100);
      _5=_10=_20=_50=_100=0;
      lcd.write("Resetlendi");
      delay(1000);
       lcd.clear();
      lcd.write("Para iade edildi.");
      delay(1000);
       lcd.clear();
      lcd.write("Hosgeldiniz...");
      delay(1000);
      lcd.clear();
      lcd.write("Bakiye giriniz...");
      delay(1000);
      bakiyeyazdir();
  }
  else if(!mode)
    {
      Serial.println("buton6 basıldı");
      EEPROM.write(0,EEPROM.read(0)+_5);
      EEPROM.write(1,EEPROM.read(1)+_10);
      EEPROM.write(2,EEPROM.read(2)+_20);
      EEPROM.write(3,EEPROM.read(3)+_50);
      EEPROM.write(4,EEPROM.read(4)+_100);
      mode=true;
      lcd.clear();
  Serial.println("----- KASADAKI PARA -----");
  Serial.print("5TL :");Serial.println(EEPROM.read(0));
  Serial.print("10TL :");Serial.println(EEPROM.read(1));
  Serial.print("20TL :");Serial.println(EEPROM.read(2));
  Serial.print("50TL :");Serial.println(EEPROM.read(3));
  Serial.print("100TL :");Serial.println(EEPROM.read(4));
    lcd.write("Islem seciniz...");
    delay(2000);  
       lcd.clear();
   lcd.write("1- Kopukleme");
   delay(1500);
      lcd.clear();
   lcd.write("2- Yikama");
   delay(1500);
      lcd.clear();
   lcd.write("3- Kurulama");
   delay(1500);
      lcd.clear();
   lcd.write("4- Cilalama");
   delay(1500);
      lcd.clear();
  lcd.write("Hizmet secin: ");
  bakiyetemp=bakiye;
    }
    else{
      Serial.println("buton6 basıldı");
      EEPROM.write(6, EEPROM.read(6)+kop);
      EEPROM.write(9, EEPROM.read(9)+yik);
      EEPROM.write(12, EEPROM.read(12)+kur);
      EEPROM.write(15, EEPROM.read(15)+cil);
      kop=0;yik=0;kur=0;cil=0;
      lcd.clear();
      lcd.write("Hizmetleriniz");
      lcd.setCursor(0,1);
      lcd.write("Sifirlandi");
      bakiyetemp=bakiye;
    }
}
void tostring(char str[], int num)
{
    int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
void bakiyeyazdir()
{
  lcd.clear();
  lcd.write("Bakiye: ");
  tostring(str, bakiye);
  lcd.write(str);

}
