

## Building an AVR application to communicate with the USART peripheral
This project walks you through the process building an AVR application to exercise the usart peripheral on the ATMega328p microcontroller. The USART peripheral can be used to interface with many different types of sensors, modems, ic(s), and microcontrollers. Refer to your microcontroller's datasheet to determine optiomal baud rate to ensure maximum data rate and minimal error rate.

### Prerequisites:

### Installing avr-gcc

Installing avr-gcc on MacOS w/Brew
```console
brew tap osx-cross/avr
brew install avr-gcc
```
verify installation
```console
avr-gcc --version
```

### Installing Avrdude on MacOS w/Brew
```console
brew install avrdude
or
brew install avrdude --with-usb
```
verify installation
```console
avrdude -v
```

### The code
The vLEDFlashTask code below is the body of the thread that FreeRTOS will execute from the call stack. The for loop simply toggles the LED port on and off once per second. 

```c++
void vLEDFlashTask(void *pvParms)
{
	vLEDInit();
	portTickType xLastWakeTime;
	const portTickType xFrequency = 1000;
	xLastWakeTime = xTaskGetTickCount();

	for(;;) {
		vLEDToggle();
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}
```

### Initialize LED
The code below initializes the led port and prepares for use. 

```c++
void vLEDInit(void)
{
	DDRB |= _BV(PB5);
}
```

### Toggle LED
Much like the blinky code we wrote in avr_328p_blinky, the following method is called from the FreeRTOS vLEDFlashTask thread to toggle the LED on and off.

```c++
void vLEDToggle(void)
{
	PORTB ^= _BV(PB5);
}
```

### Compiling the code
To compile the source code we need to create a Makefile to autmoate the process. Makefiles allow us to place all build/clean/flash commands into one easy to use file. Each microcontroller has a unique set of parameters prior to compiling and deploying. These commands are listed a the top of the Makefile and are easily changed.

Below is a snippet of Makefile parametes that would be changed to target your project.
```console
# parameters (make changes accordingly)
# project name
PRJ = main
# avr mcu
MCU = atmega328p
# mcu clock frequency
CLK = 8000000
# avr programmer (and port if necessary)
# e.g. PRG = usbtiny -or- PRG = arduino -P /dev/tty.usbmodem411
PRG = usbtiny
```

Now that your Makefile is complete issue the make from the command start the build process.

```console
make
```


### Loading the code
Now that we compiled the code we can deploy to our microcontroller.

```console
make flash
```


### Summary
As you can see adding USART peripherals is pretty straight forward. USART will open up a whole new world of communication possibilities for your microcontroller project. Make sure to read the datasheet of the peripheral you are working with to ensure voltage levels are within spec. You may have to add addtional logic level shifting circuitry to your design. This may sound complex at first but in many cases is pretty straight forward. Google is your friend.


#### References:
https://github.com/osx-cross/homebrew-avr

http://www.linuxandubuntu.com/home/setting-up-avr-gcc-toolchain-and-avrdude-to-program-an-avr-development-board-in-ubuntu