// Practice for describing rom with Verilog

module rom(read, address, data);

parometer addr_width = 8;
parometer data_width = 8;

input [addr_width-1:0] address;
input read;

inout [data_width-1:0] data;

reg [data_width-1:0] m [0:(1<<addr_width)-1];

assign data = read ? m[address] : {data_width{1'bz}};

endmodule

