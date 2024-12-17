Most of the code used in the end product was in the Main "Final-Final-Finally" folder 
since that is where the debouncer and button/motor commands where written. The Motor instantiation
was the main issue we had as we used a "Motors.c/h" & "pico_servo.c/h" from Stack Overflow that while altered,
weren't fully compatible with our design.

The brunt of our code that covers the button inputs, switching states, and utilizing the motors is found in the "main.c" file which 
relys on the "sw_in.c/h" passing through the button instantiations to the "Buttons.c/h" files which make them more easily readable.


The PSensor folder was made, and started to use old code we had from past projects, to set up the pressure sensors
and to finalize all of the touchscreen appliances of our machine. It was never fully finished
So it doesn't currently work, and wasn't used beyond the planning phase. 
