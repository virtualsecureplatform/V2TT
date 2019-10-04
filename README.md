# V2TT
V2TT is short for "Verilog to TFHE Transcompiler".
This is the repository for the transpiler to compile Verilog to C++ code with TFHE library.

## Clone repository
This repository containes submodule which containes processers' chisel files.

```
git clone --recursive https://github.com/virtualsecureplatform/V2TT.git
cd V2TT
```
Following codes assume your current directory is V2TT.

## Buid Docker Containers
This is necessary for all DEMOs.

```
cd Dockerfiles
sudo make
```

## Adder 32bit DEMO

```
cd test/Adder32bit
sudo make circuit
sudo make V2TT
sudo make tfhe
```

## VSP Aquamarine Test
This DEMO shows VSP's PoC.
```
cd KRISP/aquamarine
sudo make circuit
sudo make yosys
sudo make tfhe
```
The last command shows you how much time does VSP's one clock consumes. 
```
sudo make run
```
This command run the very simple binary file.
If you see "42" under the "cloud time", VSP worked fine. This shows x8 register of the processor on VSP.

## Disclaimer
Since this project is under development, some old codes may not workable.