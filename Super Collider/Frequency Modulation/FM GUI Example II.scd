
// FM Example
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

)
	//Freqeuncy Modulation
(

var w, carrfreqslider, modfreqslider, moddepthslider, synth;

w=Window("frequency modulation", Rect(100, 400, 400, 300));
w.view.decorator = FlowLayout(w.view.bounds);

synth= {arg carrfreq=440, modfreq=1, moddepth=0.01;
	SinOsc.ar(carrfreq + (moddepth*SinOsc.ar(modfreq)),0,0.25);
}.scope;

carrfreqslider= EZSlider(w, 300@50, "carrfreq", ControlSpec(1, 500, 'linear', 1, 65), {|ez|  synth.set(\carrfreq, ez.value)});
w.view.decorator.nextLine;

modfreqslider= EZSlider(w, 300@50, "modfreq", ControlSpec(1, 500, 'linear', 1, 65), {|ez|  synth.set(\modfreq, ez.value)});
w.view.decorator.nextLine;

moddepthslider= EZSlider(w, 300@50, "moddepth", ControlSpec(0.01, 5000, 'exponential', 0.01, 0.01), {|ez|  synth.set(\moddepth, ez.value)});
w.front;

)
