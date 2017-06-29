/* Leds commands generator */

//Rainbow hue chart
//https://github.com/FastLED/FastLED/wiki/FastLED-HSV-Colors
red = 0;
orange = 32;
yellow = 64;
green = 96;
aqua = 128;
blue = 160;
purple = 192;
pink = 224;

//Animation
stop_anim = 0;
blink_anim = 1;
pulse_anim = 2;
rainbow_anim = 3;
alternate_blink_anim = 4;

//Predefined speed (in ms)
slower = 2000;
slow = 1000;
normal = 100;
fast = 50;
faster = 30;


//Animation
function blink(led,delay){
	return "animation;"+led+";"+blink_anim+";"+delay+";0";
}

function pulse(led){
	return "animation;"+led+";"+pulse_anim+";0;0";
}

function rainbow(led){
	return "animation;"+led+";"+rainbow_anim+";0;0";
}

function alternate_blink(led1,led2,delay){
	return "animation;"+led1+";"+alternate_blink_anim+";0;0";
}

function stop(led){
	return "animation;"+led+";"+stop_anim+";0;0";
}

//Color
function brightness(bright){
	return "brightness;"+bright;
}

function off(led){
	return "color;"+led+";0;0;0";
}

function on(led){
	return "color;"+led+";0;0;255";
}

function color(led,hue){
	return "color;"+led+";"+hue+";255;255";
}

function hsv(led,h,s,v){
	return "color;"+led+";"+h+";"+s+";"+v;
}