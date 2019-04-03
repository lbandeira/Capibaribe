void F_RPM(){
  QntBlocos = RPM/1000;
  int i;
       for(i = 0; i < QntBlocos; i++){
          lcd.setCursor(i,1);
          lcd.write(4);
       }
}
