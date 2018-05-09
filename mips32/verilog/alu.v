// Module of Arithmetic Logic Unit

module alu (control, a, b, r, zero);

input [2:0] control;
input [31:0] a;
input [31:0] b;

output [31:0] r;
output zero;

wire [31:0] s;

assign s = control[2] ? (a-b) : (a+b);

assign zero = (r == 0);

always@(*) begin
  case (control[1:0])
    2'b00: r <= a & b;    // and
    2'b01: r <= a | b;    // or
    2'b10: r <= s;        // add
    2'b11: r <= {{31{1'b0}}, s[31]};    // slt
  endcase
end

endmodule
