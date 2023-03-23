
// Amplitude Modulation I
// Client:
// Author: Daniel Shor
// Revision Table:
// 220505 - Initial Edit

// Run From Here Down__________________________________________

// Initial Server Boot

(
s.boot;
Server.killAll;
FreqScope.new
)

//Amplitude Modulation
// Here we create an amplitude modulation wave, and can then modify using a mouse.

(
{
	var carrier, modulator, carrfreq, modfreq;

	carrfreq= MouseX.kr(1,500,'linear');
	modfreq= MouseY.kr(1,500,'linear');

	carrier= SinOsc.ar(carrfreq,0,0.5);
	modulator= SinOsc.ar(modfreq,0,0.25, 0.25);
	carrier*modulator;

}.scope

)


