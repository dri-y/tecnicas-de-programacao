#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
Adafruit_LiquidCrystal lcd(0);
Servo sv;
const int L[4]={4,5,6,7},C[4]={8,9,10,11},FC=13;
const char K[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
int pos=0,tent=0,a=0,p=0;
char senha[7]="ABC123",dig[7];
bool abrir=false,alt=false;

char lerTecla(){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)digitalWrite(L[j],LOW);
    digitalWrite(L[i],HIGH);
    for(int j=0;j<4;j++)if(digitalRead(C[j])){while(digitalRead(C[j]));return K[i][j];}
  }
  return 0;
}
void msg(const char*s,int l){lcd.clear();lcd.setCursor(0,l);lcd.print(s);}
void redraw(const char*t,char*b,int n){
  lcd.clear();lcd.setCursor(0,0);lcd.print(t);lcd.setCursor(5,1);
  for(int i=0;i<n;i++)lcd.print(b[i]);
}
void tela(){msg("A-Abrir cofre",0);lcd.setCursor(0,1);lcd.print("B-Alterar senha");abrir=alt=false;a=0;p=0;}
void reset1(){msg("Digite a senha:",0);lcd.setCursor(5,1);a=0;}
void resetN(){msg("Nova Senha:",0);lcd.setCursor(5,1);p=0;}
void incorreta(){msg("Senha Incorreta",0);delay(1500);msg("Tente novamente",1);delay(1500);reset1();tent++;}
void alarme(){msg("    ALARME",0);for(int v=0;v<10;v++)for(int f=500;f<2000;f++){tone(3,f);delayMicroseconds(600);}noTone(3);}
void correta(){
  msg("Senha Correta",0);delay(800);
  for(pos=0;pos<=90;pos++){sv.write(pos);delay(15);}
  lcd.setCursor(0,1);lcd.print("Cofre Aberto");
  while(digitalRead(FC)==LOW)delay(50);
  msg("Trancando...",0);delay(800);
  for(pos=90;pos>=0;pos--){sv.write(pos);delay(15);}
  msg("Cofre Trancado",0);delay(1500);tela();
}

void setup(){
  lcd.begin(16,2);lcd.setBacklight(HIGH);
  for(int i=0;i<4;i++){pinMode(L[i],OUTPUT);pinMode(C[i],INPUT);}
  pinMode(FC,INPUT);sv.attach(12);sv.write(0);
  tela();
}

void inserir(char*buf,int&n,const char*tit){
  char k=lerTecla();if(!k)return;
  if(k=='*'){if(n>0){n--;redraw(tit,buf,n);}return;}
  if(k=='#')return;
  if(n<6){buf[n++]=k;lcd.print(k);}
}

void loop(){
  if(!abrir && !alt){
    char k=lerTecla();
    if(k=='A'){abrir=true;reset1();}
    else if(k=='B'){alt=true;reset1();}
    return;
  }
  if(abrir){
    if(a<6){inserir(dig,a,"Digite a senha:");return;}
    char k=lerTecla();
    if(k=='#'){
      bool ok=true;
      for(int i=0;i<6;i++)if(senha[i]!=dig[i]){ok=false;break;}
      if(ok){tent=0;correta();}
      else{tent++;if(tent>=3){alarme();tela();tent=0;}else incorreta();}
    }else if(k=='*'){a--;redraw("Digite a senha:",dig,a);}
    return;
  }
  if(alt){
    if(a<6){inserir(dig,a,"Digite a senha:");return;}
    if(a==6){
      char k=lerTecla();
      if(k=='#'){
        bool ok=true;
        for(int i=0;i<6;i++)if(senha[i]!=dig[i]){ok=false;break;}
        if(ok){tent=0;a=7;msg("Senha Correta",0);delay(1200);resetN();}
        else{tent++;if(tent>=3){alarme();tela();tent=0;}else incorreta();}
      }else if(k=='*'){a--;redraw("Digite a senha:",dig,a);}
      return;
    }
    if(p<6){inserir(senha,p,"Nova Senha:");return;}
    char k=lerTecla();
    if(k=='#'){senha[6]=0;msg("Senha alterada",0);lcd.setCursor(0,1);lcd.print("com sucesso");delay(2000);tela();}
    else if(k=='*'){p--;redraw("Nova Senha:",senha,p);}
  }
}
