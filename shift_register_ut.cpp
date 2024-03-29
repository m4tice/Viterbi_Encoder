#include "sc_test_framework.h""
#include "shift_register.h"

static const int clock_period = 14;
static const double clock_duty = 0.5;
static const int clock_start = 20;
static const int reg_width = 5;

SC_TEST(shift_register) {
	sc_signal<sc_logic> data_in;
	sc_signal<sc_lv<reg_width> > register_state;
	sc_clock sys_clock("sys_clock", clock_period, clock_duty, clock_start, false);

	SC_TRACE(sys_clock, "sys_clock");
	SC_TRACE(register_state, "register_state");
	SC_TRACE(data_in, "data_in");

	shift_register<reg_width> sregister("ShiftRegister");
	sregister.data_in(data_in);
	sregister.clk(sys_clock);
	sregister.q(register_state);

	data_in = sc_logic('0');
	sc_start(50, SC_NS);
	data_in = sc_logic('1');
	sc_start(100, SC_NS);
	data_in = sc_logic('0');
	sc_start(100, SC_NS);
}