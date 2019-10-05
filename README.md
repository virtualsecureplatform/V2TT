# V2TT
V2TT is short for "Verilog to TFHE Transcompiler".
This is the repository for the transpiler to compile Verilog to C++ code with TFHE library.

## Quick DEMO
This is verified to work on AWS's m5.metal spot instance with ubuntu 18.04 AMI.
If you use Ubuntu, this will run the VSP Aquamarine Test automatically from nothing.

```
sudo apt-get update &&\
sudo apt-get install -y \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common &&\
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - &&\
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable" &&\
sudo apt-get update &&\
sudo apt-get install -y docker-ce docker-ce-cli containerd.io make &&\
git clone --recursive https://github.com/virtualsecureplatform/V2TT.git &&\
cd V2TT/Dockerfiles &&\
sudo make chisel-tfhe &&\
cd ../KRISP/aquamarine &&\
sudo make tfhe &&\
sudo make run
```

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
*The next command takes 200 times more time.*
```
sudo make run
```
This command run the very simple binary file, it culcurate 10th fibonach number, 55.
If you see "55" under the "cloud time", VSP worked fine. This shows x8 register of the processor on VSP.

## Disclaimer
Since this project is under development, some old codes may not workable.