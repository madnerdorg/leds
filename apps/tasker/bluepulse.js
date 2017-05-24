ip="192.168.0.140";
port=42001;


bluepulse = "load;255;160;255;143;2;0;0;160;255;116;2;0;0;";
police = "load;255;0;255;255;4;0;1;160;255;255;4;1;70;";
fire = "load;123;32;255;41;2;0;0;32;255;129;2;0;0;";
off = "/off";

leds = new WebSocket("ws://"+ip+":"+port);
leds.onopen = send;

function send(){
	leds.send(bluepulse);
}
