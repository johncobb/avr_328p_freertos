

## Building a AVR based FreeRTOS application (blinky)
This project walks you through the process building a FreeRTOS based AVR application to toggle a LED on the ATMega328p microcontroller. The FreeRTOS kernel is developed by leading chip manufacturers to provide a Real Time Operating System for microtrollers and microprocessors. Refer to your microcontroller's datasheet to determine optiomal memory footprint and stack size.

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
As you can see adding FreeRTOS support is pretty straight forward. FreeRTOS will allow you to program your microcontroller more like a computer using threads and task isolation. The tradeoff is more disciplined memory management of your threads. These skills only add to your ability to design more efficient code.


#### References:
https://github.com/osx-cross/homebrew-avr

http://www.linuxandubuntu.com/home/setting-up-avr-gcc-toolchain-and-avrdude-to-program-an-avr-development-board-in-ubuntu