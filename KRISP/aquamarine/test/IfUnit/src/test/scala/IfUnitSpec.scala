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

import chisel3._
import chisel3.iotesters.ChiselFlatSpec

import scala.sys.process.Process
import scala.sys.exit
import org.scalacheck.Properties
import org.scalacheck.Prop.forAll 
import scala.language.implicitConversions

import scala.util.Random

class IfUnitSpec extends ChiselFlatSpec {
        def expect(ans: Int, res: Int){
          if (ans != res){
            println(ans)
            println(res)
            println("Error")
            sys.exit(0)
          }
        }

        implicit def bool2int(b:Boolean) = if (b) 1 else 0

        var jump = 0
        val enable = 1
        for (i <- 0 until 100) {
          val jumpAddress = Random.nextInt(0x1F)
          val regpc = Random.nextInt(0x1F)
          Process("./client " + jumpAddress.toString + " " + jump.toString + " " + enable.toString + " " + regpc.toString).!
          Process("./cloud 0").!
          var ans = Process("./verify").lineStream.toList
          expect(ans(0).toInt, regpc + 2)
          Process("./cloud 1").!
          ans = Process("./verify").lineStream.toList
          expect(ans(0).toInt, regpc + 4)
        }

        jump = 1
        for(i <- 0 until 100) {
          val jumpAddress = Random.nextInt(0x1F)
          val regpc = Random.nextInt(0x1F)
          Process("./client " + jumpAddress.toString + " " + jump.toString + " " + enable.toString + " " + regpc.toString).!
          Process("./cloud 0").!
          val ans = Process("./verify").lineStream.toList
          expect(ans(0).toInt, jumpAddress)
        }
}

