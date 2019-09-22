# V2TT
V2TT is short for "Verilog to TFHE Transcompiler".
This is the repository for the transpiler to compile Verilog to C++ code with TFHE library.

## Adder 32bit DEMO

```
git clone https://github.com/virtualsecureplatform/V2TT.git
cd V2TT/Dockerfiles
sudo make
cd ../test/Adder32bit
sudo make circuit
sudo make V2TT
sudo make tfhe
```

Most of codes can be run by same procedure.
Since this project is under development, some old codes may not workable.