import chisel3._

class Adder32bitPort extends Bundle {
  val in_a = Input(UInt(32.W))
  val in_b = Input(UInt(32.W))
  val out = Output(UInt(33.W))
}

class Adder32bit extends Module {
  val io = IO(new Adder32bitPort)

    io.out := io.in_a +& io.in_b 
}

object Elaborate extends App {
  chisel3.Driver.execute(args, () => new Adder32bit())
}
