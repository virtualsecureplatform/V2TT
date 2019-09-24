/*
Copyright 2019 Kotaro MATSUOKA

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

import chisel3._
import chisel3.util.MuxLookup

class LURomPort extends Bundle {
  val address = Input(UInt(3.W))
  val rom = Vec(4,Input(UInt(2.W)))

  val out = Output(UInt(2.W))

}

class LURom extends Module {
  val io = IO(new LURomPort);
  var data: Array[(chisel3.core.UInt,chisel3.core.Data)] = Array.empty
  for(i <- 0 to 3){
      data = data :+ (i.U -> io.rom(i))
  }
  io.out := MuxLookup(io.address >> 1,0.U,data)
}

object Elaborate extends App {
  chisel3.Driver.execute(args, () => new LURom())
}