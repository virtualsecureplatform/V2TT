`default_nettype none

module halfadder(
  input   wire  a,
  input   wire  b,
  output  wire  c,
  output  wire  s
  );

  assign  c = a & b;
  assign  s = a ^ b;

endmodule
