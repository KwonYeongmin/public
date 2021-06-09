#pragma once
#ifndef TV_H_
#define TV_H_

class Remote;

class Tv
{
	friend class Remote;
public :
	enum { off, on };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD};
	

	Tv(int s = off, int mc = 125) :state(s),volume(5),maxchannel(mc),channel(2),mode(Cable),input(TV){}
	void onoff() { state = (state == on) ? off : on; }
	bool ison() const { return state == on; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; };
	void set_input() { input = (input == TV) ? DVD : TV; }
	void setting() const;

	//추가
	void n_mode_(Remote &r);// { r.n_mode = (r.n_mode == r.NORMAL) ? r.TALK : r.NORMAL; }

private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;

	
};
class Remote
{
	friend class Tv;
private:
	int mode;

	//추가
	int n_mode;
	enum { NORMAL, TALK };
public:
	
	Remote(int m = Tv::TV,int n_m=NORMAL) :mode(m),n_mode(n_m) {}
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv & t) { return t.voldown(); }
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) { t.chanup(); }
	void chandown(Tv & t) { t.chandown(); }
	void set_chan(Tv & t, int c) { t.channel = c; }
	void set_mode(Tv & t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }

	//추가
	void set_n_mode(Tv & t) { t.n_mode_(*this); }
	void Print();
};


#endif // !TV_H_



