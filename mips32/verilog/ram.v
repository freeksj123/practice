// Practice for describing ram with Verilog

module ram(clock, read, write, address, data);

parameter addr_width = 8;
parameter data_width = 8;

input [addr_width-1:0] address;
input read;
input write;

inout [data_width-1:0] data;

reg [data_width-1:0] m [0:(1<<addr_width)-1];

assign data = read ? m[address] : {data_width{1'bz}};

always @(posedge clock)
    if (write)
        m[address] = data;

endmodule

