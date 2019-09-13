import chisel3._

class MemPort extends Bundle{
  val in = Input(UInt(2.W))
      val address = Input(UInt(1.W))
      val writeEnable = Input(Bool())

      val out = Output(UInt(2.W))
}

class Memory extends Module{
  val io = IO(new MemPort)
  val mem = Mem(2, UInt(2.W))
  val pReg = RegInit(0.U.asTypeOf(new MemPort))

  pReg.address := io.address
  pReg.in := io.in
  pReg.writeEnable := io.writeEnable
  when(pReg.writeEnable){
    mem(pReg.address) := pReg.in
    io.out := pReg.in
  }.otherwise{
    io.out := mem(pReg.address)
  }
}

object Elaborate extends App {
  chisel3.Driver.execute(args, () => new Memory())
}