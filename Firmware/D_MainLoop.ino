void loop() 
{
    //define flow for beatsin
rsin = beatsin88( 190, 0, 255);  // 60 bpm
gsin = beatsin88( 210, 0, 255);  // 42 bpm
bsin = beatsin88( 200, 0, 255);  // 23 bpm

//Check for Input
  input();

//Programm selection based on IR Remote Keys  
  while(menu == 183841485){ //Red Key
        Dots1();
      break;
  }   
  while(menu == 183870045){ // Green Key
        Dots2();
      break;
  }   
  while(menu == 183853725){ //Yellow Key
        SlowMandala3();
      break;
  }
   while(menu == 183886365){ //Blue Key
        ledsHeartbeatRandomColor(100, 80, 20);
    break;
   }
   while (menu == 183873615){ //1 button
        juggle();
   break;
   }
   while (menu == 183857295){ //2 button
        SlowMandala2();
   break;
   }
   while (menu == 183889935){ //3 button
        SlowMandala3();
   break;
   }
   while(menu == 183874125){ //Photo key
        Mandala8();
   break;
   }
   while (menu == 183850665){ //Rotate key 
       sineflow();
   break;
   }
   while (menu == 183890445){ //vtext ... button
        wettersimu();
   break;
   }
   while (menu == 183834345){ //vtext x button
        explosion(NUM_LEDS, 20, 150, 20);
   break;
   }
   while (menu == 183866985){  //vtext i button
      rainbow(); 
   break;
   }   
   while (menu == 183842250){ //swivel key
      rainbow2(80, 2, 9, 2, 2);
      rainbow2(80, 2, 8, 3, 2);
      rainbow2(80, 2, 7, 1, 8);
      rainbow2(80, 2, 6, 0, 16);
   break;
   }
   while (menu == 183891465){ //<- -> key
      byte hue = (millis()/100)%255;
      byte sat = (millis()/100)%255;
      int duration = (millis()/100)%255;
      larsonScanner(NUM_LEDS, hue, sat, duration);
   break;
   }
   while (menu == 183854745){ //-_ key
      byte rainbowWidth = 40;
      byte sat = (millis()/100)%255;
      int duration = (millis()/100)%255;
      implosion(NUM_LEDS, rainbowWidth, sat, duration);
   break;
   }
   while (menu == 183887895){ //Power button
       //  sinelon();
       AutoRun();
       // Comment AutoRun out and test examples seperately here
       //Dots2();
       // For discovering parameters of examples I reccomend to
       // tinker with a renamed copy ...
   break;
   }
   while (menu == 183881775){ //Mute button
       if (go==1) {shift_out_data(); go=0;}    
   break;
   }
if (go==1) {shift_out_data(); go=0;} 
}

