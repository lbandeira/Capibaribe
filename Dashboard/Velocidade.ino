void F_Velocidade(){
  QntBlocos = Velocidade/10;
  int i;
       for(i = 0; i < QntBlocos; i++){
          lcd.setCursor(i,0);
          lcd.write(1);
       }
}
