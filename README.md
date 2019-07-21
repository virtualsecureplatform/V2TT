# V2TT
V2TT is short for "Verilog to TFHE Transcompiler".
This is the repository for the transpiler to compile Verilog to C++ code with TFHE library.

## Adder 32bit DEMO

```
git clone https://github.com/virtualsecureplatform/V2TT.git
cd V2TT/Dockerfiles
make
cd ../test/Adder32bit
make circuit
make V2TT
make tfhe
```