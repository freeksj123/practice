// Module for control unit of pipelined CPU

module cupipelinesimple (op, func, writereg, mem2reg, writemem, branch, regdes, aluc, alusrcb);

input [5:0] op;
input [5:0] func;

output writereg;
output mem2reg;
output writemem;
output branch;
output regdes;
output [2:0] aluc;
output alusrcb;

wire rtype;
wire isadd;
wire issub;
wire isand;
wire isor;
wire isslt;
wire islw;
wire issw;
wire isbeq;
wire isj;

assign rtype = (op == 0);

assign isadd = (rtype & (func == 6'b100000));
assign issub = (rtype & (func == 6'b100010));
assign isand = (rtype & (func == 6'b100100));
assign isor  = (rtype & (func == 6'b100101));
assign isslt = (rtype & (func == 6'b101010));

assign islw  = (op == 6'b100011);
assign issw  = (op == 6'b101011);
assign isbeq = (op == 6'b000100);
//assign isj   = (op == 6'b000010);

//assign jump     = isj;
assign writereg = islw | isadd | issub | isand | isor | isslt;
assign mem2reg  = islw;
assign writemem = issw;
assign branch   = isbeq & zero;
assign regdes   = islw;
assign aluc[2]  = issub | isslt | isbeq;
assign aluc[1]  = islw | issw | isadd | issub | isslt | isbeq;
assign aluc[0]  = isor | isslt;
assign alusrcb  = islw | issw;

endmodule
