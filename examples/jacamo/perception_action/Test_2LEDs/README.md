# Example: agent acting and perceiving the environment

This example simulates an embedded agent that (i) perceives the environment through the simulated sensors plugged in an Raspberry Pi Pico and (ii) acts upon this environment.

The agent is equipped with an Raspberry Pi Pico which has two led plugged to. Pressing a button the agent must change the state of the corresponding LED.

The agent has a perception "light_state(S)" (where S=1 means led on; S=0 means led off). The repertory of actions of the agent includes the action lightOn and lightOff that turns the led on end off respectively.


### Running the example
1. Check the serial port which the Raspberry Pi Pico is connected to.

1.1 In Debian based systems:
        
1.1.1 Before to connect the Raspberry Pi Pico, type ls /dev/ttyUSB*

                1.1.2 Connect the Raspberry Pi Pico and type ls /dev/ttyUSB* again. The new listed value is the serial port.

1. Make sure you are permitted to write in the serial port which the Raspberry Pi Pico is connected to.

1.1 In Unix systems, use sudo chmod a+rw /dev/{SERIAL_NAME} to enable writing in serial

(e.g. sudo chmod a+rw /dev/ttyUSB0)

1. Load the program [read_char](arduino/lights/lights.ino) to an Raspberry Pi Pico
1. In a terminal, type ```./gradlew run -q --console=plain ```
