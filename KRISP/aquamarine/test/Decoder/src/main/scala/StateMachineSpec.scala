/*
Copyright 2019 Naoki Matsumoto

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

import chisel3.iotesters.ChiselFlatSpec
import scala.sys.process.Process
import scala.sys.exit

class StateMachineSpec extends ChiselFlatSpec {
  def expect(ans: Boolean, res: Boolean){
    if (ans != res){
    println(ans)
    println(res)
    println("Error")
    sys.exit(0)
    }
  }
  Process("./client ").!
  Process("./cloud 0").!
  val ans = Process("./verify").lineStream.toList
  println(ans)
}
