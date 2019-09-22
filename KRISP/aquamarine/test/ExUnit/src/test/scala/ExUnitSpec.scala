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


class ExUnitSpec extends ChiselFlatSpec{
        def expect(ans: Int, res: Int){
          if (ans != res){
            println(ans)
            println(res)
            println("Error")
            sys.exit(0)
          }
        }

        implicit def bool2int(b:Boolean) = if (b) 1 else 0

        def check_sign(t: Int): Boolean = {
          val sign_bit = (t >>> 15) & 0x1
          sign_bit == 1
        }

        def check_zero(t: Int): Boolean = (t == 0)

        def check_overflow(s1: Int, s2: Int, r: Int): Boolean = {
          val s1_sign = (s1 >> 15) & 0x1
          val s2_sign = (s2 >> 15) & 0x1
          val res_sign = (r >> 15) & 0x1
          if (((s1_sign ^ s2_sign) == 0) & ((s2_sign ^ res_sign) == 1)) {
            true
          } else {
            false
          }
        }

        def check_carry(t: Int): Boolean = (((t >> 16) & 0x1) == 0)

        var enable = 1
        var shifterSig = 0
        for (i <- 0 until 100) {
          //MOV
          val opcode = 0
          val a = Random.nextInt(0xFFFF)
          val b = Random.nextInt(0xFFFF)
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList

          val res = b
          expect(ans(0).toInt, res)
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2)
          expect(ans(1).toInt, FLAGS)
        }
        for (i <- 0 until 100) {
          //ADD
          val opcode = 2
          val a = Random.nextInt(0xFFFF)
          val b = Random.nextInt(0xFFFF)
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList
          val res = a + b
          expect(ans(0).toInt, (res & 0xFFFF))
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2) + (check_carry(res) << 1) + (check_overflow(a, b, res))
          expect(ans(1).toInt, FLAGS)
        }
        for (i <- 0 until 100) {
          //SUB
          val opcode = 3
          val a = Random.nextInt() & 0xFFFF
          val b = Random.nextInt() & 0xFFFF
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList
          val res = a + ((~b)&0xFFFF) + 1
          expect(ans(0).toInt, (res & 0xFFFF))
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2) + (check_carry(res) << 1) + (check_overflow(a, b, res))
          expect(ans(1).toInt, FLAGS)
        }
        for (i <- 0 until 100) {
          //AND
          val opcode = 4
          val a = Random.nextInt() & 0xFFFF
          val b = Random.nextInt() & 0xFFFF
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList
          val res = a & b
          expect(ans(0).toInt, (res & 0xFFFF))
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2)
          expect(ans(1).toInt, FLAGS)
        }
        for (i <- 0 until 100) {
          //OR
          val opcode = 5
          val a = Random.nextInt() & 0xFFFF
          val b = Random.nextInt() & 0xFFFF
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList
          val res = a | b
          expect(ans(0).toInt, (res & 0xFFFF))
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2)
          expect(ans(1).toInt, FLAGS)
        }
        for (i <- 0 until 100) {
          //XOR
          val opcode = 6
          val a = Random.nextInt() & 0xFFFF
          val b = Random.nextInt() & 0xFFFF
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList
          val res = a ^ b
          expect(ans(0).toInt, (res & 0xFFFF))
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2)
          expect(ans(1).toInt, FLAGS)
        }
        shifterSig = 1
        for (i <- 0 until 100) {
          //LSL
          val opcode = 1
          val a = Random.nextInt() & 0xFFFF
          val b = Random.nextInt() & 0x1F
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList
          val res = (a << b) & 0xFFFF
          expect(ans(0).toInt, res)
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2)
          expect(ans(1).toInt, FLAGS)
        }
        for (i <- 0 until 100) {
          //LSR
          val opcode = 2
          val a = Random.nextInt() & 0xFFFF
          val b = Random.nextInt() & 0x1F
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList
          val res = (a >> b) & 0xFFFF
          expect(ans(0).toInt, res)
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2)
          expect(ans(1).toInt, FLAGS)
        }
        for (i <- 0 until 100) {
          //ASR
          val opcode = 4
          val a = Random.nextInt() & 0xFFFF
          val b = Random.nextInt() & 0x1F
          Process("./client " + opcode.toString + " " + a.toString + " " + b.toString + " " + shifterSig.toString + " " + enable.toString + " 0 0 0").!
          Process("./cloud 1").!
          val ans = Process("./verify").lineStream.toList

          def shift_arithmetic(v: Int, shamt: Int): Int = {
            val sign_bit = (v >>> 15) & 0x1
            var mask = 0
            for (i <- 0 until shamt) {
              mask = mask + (sign_bit << 15 - i)
            }
            val res = v >>> shamt
            (res | mask) & 0xFFFF
          }

          val res = shift_arithmetic(a, b)
          expect(ans(0).toInt, res)
          val FLAGS = (check_sign(res) << 3) + (check_zero(res) << 2)
          expect(ans(1).toInt, FLAGS)
        }
}
