// Module for control unit of single cycle CPU

module cusc (op, func, zero, jump, mem2reg, branch, writemem, aluc, alusrcb, writereg, regdes);

input [5:0] op;
input [5:0] func;
input zero;

output jump;
output mem2reg;
output branch;
output writemem;
output [2:0] aluc;
output alusrcb;
output writereg;
output regdes;

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
assign isj   = (op == 6'b000010);

assign jump     = isj;
assign branch   = isbeq & zero;
assign writemem = issw;
assign aluc[2]  = issub | isslt | isbeq;
assign aluc[1]  = islw | issw | isadd | issub | isslt | isbeq;
assign aluc[0]  = isor | isslt;
assign alusrcb  = islw | issw;
assign mem2reg  = islw;
assign writereg = islw | isadd | issub | isand | isor | isslt;
assign regdes   = islw;

endmodule
