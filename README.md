# PWM-SYSFS-NANOPC-T2
INTERFACING PWM WITH NANONPC-T2 WITH nanopi2-v4.4.y using Sysfs Interface

This Document Describes How to Interface PWM (Pulse Width Modulation) with NanoPC-T2.

Here I have Interfaced buzzer with the NanoPC-T2.

Pin Descriptions are as Follows.


PIN Number                    Pin Description

23 	                          GPIOD1/PWM0 	
25                          	GPIOC13/PWM1 	
27 	                          GPIOC14/PWM2 	

we use the generic sysfs PWM framework to give access to PWMs from userspace.

sysfs Path are as Follows.

PWM0 ----> /sys/class/pwm/pwmchip0/
PWM1 ----> /sys/class/pwm/pwmchip1/
PWM2 ----> /sys/class/pwm/pwmchip2/

Here I am Going to Connect  Buzzer with  PWM0

Step 1 : Export PWM channel for user control.

cd /sys/class/pwm/pwmchip0
echo 0 > export

Step 2 : Select the period of PWM signal. Value is in nanoseconds.

echo 1000000 > pwm0/period

Step 3 : Select the duty cycle. Value is in nanoseconds and must be less than the period.

echo 250000  > pwm0/duty_cycle

Step 4 : Enable/disable the PWM signal.

echo 1 > pwm0/enable

Possible values:

    1: Enable
    0: Disable

Have a Fun with Buzzer.

User Space Application C source code for pwm using sysyfs.
