// Practice for describing register file with Verilog

module regfile(clock, r1, r2, d1, d2, rd, data, write);

parameter rnum_width = 5;

parameter data_width = 32;

input [rnum_width-1:0] r1;
input [rnum_width-1:0] r2;
input [rnum_width-1:0] rd;

input write;

input [data_width-1:0] data;


output [data_width-1:0] d1;
output [data_width-1:0] d2;

reg [data_width-1:0] r [0:(1<<rnum_width)-1];

assign d1 = r[r1];
assign d2 = r[r2];

always @(negedge clock)  // write at falling edge of clock
    if (write)
        r[rd] = data;

endmodule
