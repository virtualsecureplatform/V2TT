import chisel3._

class AdderMiniPort extends Bundle {
  val in_a = Input(UInt(2.W))
  val in_b = Input(UInt(2.W))
  val out = Output(UInt(3.W))
}

class AdderMini extends Module {
  val io = IO(new AdderMiniPort)

    io.out := io.in_a +& io.in_b 
}

object Elaborate extends App {
  chisel3.Driver.execute(args, () => new AdderMini())
}