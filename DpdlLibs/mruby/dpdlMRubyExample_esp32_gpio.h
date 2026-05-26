# File: mruby/dpdlMRubyExample_esp32_pgio.h
#
# Example: Sample dpdl code that make use of an 'embedded code section' in mruby (Lightweight Ruby)
#			to simply blink a LED on a ESP32 MCU.
#			The 'mruby' code make use of the gem mruby-esp32-gpio (https://github.com/mruby-esp32/mruby-esp32-gpio)
#			to acces GPIO ports
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("dpdl example that is running on a ESP32 MCU..")

int i
for(i < 10000)
	println("iter $i")
	i=i+1
endfor

println("blinking a LED via 'mruby' and a gem lib...")

>>mruby(async)

	led = ESP32::GPIO_NUM_2
	ESP32::GPIO::pinMode(led, ESP32::GPIO::OUTPUT)

	loop {
	  ESP32::GPIO::digitalWrite(led, ESP32::GPIO::HIGH)
	  ESP32::System.delay(1000)
	  ESP32::GPIO::digitalWrite(led, ESP32::GPIO::LOW)
	  ESP32::System.delay(1000)
	}
<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing ESP32 led blinking code")

prinltn("the LED is blinking now...")

while(true)
	print(".")
	sleep(3000)
endwhile
