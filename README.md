# headfixedArduino
a set of arduino files to control input output on a headfixed styrofoam setup.

##How to:

1) Upload template_mouse_styrofoam_sensor.ino to an Arduino Due.
2) Open up the Serial Monitor.

You will see the following:
```bash
******************************************************
PLEASE INITIALIZE:
type anything into the console and press start
******************************************************
```
3) Send any signal on the serial monitor to start the experiment.

4) Move the styrofoamball and you will se the CSV generated movement data.
```bash
91296,0,0,99,-1,3
91306,0,0,99,-1,2
91316,0,0,99,-2,1
91326,0,0,99,-3,4
91336,0,0,99,-2,6
91346,0,0,99,-1,9
91356,0,0,99,-1,11
91366,0,0,99,1,15
91376,0,0,99,4,17
91386,0,0,99,6,19
91396,0,0,99,7,23
91410,0,0,99,8,26
91429,0,0,99,15,44
91450,0,0,99,20,56
91471,0,0,99,26,77
91492,0,0,99,29,82
91512,0,0,99,30,83
91533,0,0,99,30,78
91554,0,0,99,29,81
91575,0,0,99,25,65
91596,0,0,99,18,44
```

