# arduino-traffic-density-lane-divider

### Steps to compile and burn the program:-
1. Save the Program
2. Use the tick button on the upper left corner to compile
3. Connect the Arduino to the computer
4. Go to Port and select COM in which Arduino is connected.
5. Use the arrow button to upload the program to Arduino

Now the Arduino is ready to be assembled with the rest of the circuit.


### Connections:-
1. The Arduino and bread board are bought together
2. The IR transmitters and receivers are placed such that their LED’s are directly facing
each other.
3. The transistors are placed such that their base are connected to each of the IR
receivers. The collectors of all three are shorted and given a +5V supply. The
emmiters are connected to the input port pins of the Arduino. Here we have directly
connected them to Vcc of Arduino as we require them to be continuously ON.
4. The IR receivers have their positive terminals connected to the base of their respective
transistors. The negative terminals are all grounded.
5. The IR transmitters have their positive terminals connected to the output port pin of
the Arduino meant for them. Here they are A0 and A2. The negative terminals of all
three are grounded.
6. The Red, Orange and Green LEDs are connected at output port pins 2,3 and 4
respectively.
7. Port pins 8,9,10 and 11 are connected to the 4 input ports of one L293D IC.
8. The stepper motors are connected to the 4 output pins of their respective L293D IC
Driver Circuits.
9. 4 terminals of L293D are Ground – 4,5,12 and 13.
10. Pins 1, 9 and 16 of the L293D ICs are connected to +5V.
11. Pin 8 of the ICs are given the supply voltage required for the motor. Here it is 24V.

### Working:-
1. The power supply is set using DMM then switched on.
2. The Green Led starts glowing.
3. The red and orange leds do not show any output, neither do the stepper motors.
4. The IR transmitters start transmitting.
5. Since there is a barrier to reflect the transmitter’s rays, the receivers output is high.
6. Thus the transistors are switched on and input ports A0 and A2 are high.
7. The ports 8,9,10,11 are given outputs 00 to do nothing.
8. Since the cars are continuously moving when there is not much traffic, Atleast twice
in every 10 seconds the receiver’s output goes low and it does not receive anything
from the transmitter(since there is no barrier)
9. This infinitely continues until the receiver receives continuously for more than 10
seconds.
10. If that happens then the whole circuit is initiated.
11. First the green Led goes off
12. Orange Led comes on for a second or so.
13. Red LED starts glowing.
14. After a few seconds, the output ports from 8 to 11 are given values to rotate the
motors in opposite directions (one clockwise and the other counter-clockwise).
15. After the completion of one full rotation, The red led stops glowing and green led
glows again. Output ports 8 to 11 again given 00.
16. Now this will be in an infinite loop until all three receivers don’t receive inputs. Then
a delay of one second is given and this condition is checked again
17. This is repeated thrice (about 3 seconds).
18. If anytime any of the input ports go high, it goes back to the infinite loop.
19. If for all three seconds all three input ports are low, the green led stops glowing
20. The orange led glows for a second
21. The Red LED starts glowing
22. After a few seconds, the output ports 8 to 11 are given values to rotate the motors in
opposite directions (one clockwise and the other counter-clockwise). This time they
are both given opposite of what they were given before.
23. After the completion of one full rotation, the red led stops glowing and green led
glows again. Output ports 8 to 11 are again given 00.
24. Again it goes into infinite loop till all input ports are high for more than 10 seconds
continuously.
25. And so the circuit continues to operate
