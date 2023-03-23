
// AM With Error
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


// Amplitude Modulation III
// Here we create an amplitude modulation wave and modify using a GUI. There is a wave creating a error function in the value
(

var w, carrfreqslider, modfreqslider, gainslider, synth;

w=Window("Amplitude Modulation", Rect(100, 400, 400, 300));
w.view.decorator = FlowLayout(w.view.bounds);

//Reminder: SinOsc.ar(freq: 440.0, phase: 0.0, mul: 1.0, add: 0.0)
synth= {arg carrfreq=80, modfreq=80, gain=0.25, carrerror=0, moderror=0.0;
	SinOsc.ar((carrfreq*  carrerror),0,gain) * SinOsc.ar(modfreq*moderror,0 ,0.25, 0.25);
		}.scope;

carrfreqslider= EZSlider(w, 300@50, "carrfreq", ControlSpec(50, 80, 'linear', 1, 65), {|ez|  synth.set(\carrfreq, ez.value)});
w.view.decorator.nextLine;

modfreqslider= EZSlider(w, 300@50, "modfreq", ControlSpec(0, 200, 'linear', 1, 65), {|ez|  synth.set(\modfreq, ez.value)});
w.view.decorator.nextLine;

gainslider= EZSlider(w, 300@50, "carr error freq", ControlSpec(0.5, 2, 'linear', 0.05, 0.5), {|ez|  synth.set(\carrerror, ez.value)});
w.view.decorator.nextLine;

modfreqslider= EZSlider(w, 300@50, "mod error freq", ControlSpec(0.5, 2, 'linear', 0.05, 1), {|ez|  synth.set(\moderror, ez.value)});
w.view.decorator.nextLine;

w.front;

)
