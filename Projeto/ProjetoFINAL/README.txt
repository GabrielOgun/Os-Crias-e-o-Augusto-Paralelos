Rodamos em um Ubuntu na AWS usando a maquina EC2 z1d.large
sudo apt update
sudo apt install build-essential --> instalar GCC
sudo apt install libgmp-dev --> instalar GMP
gcc -O3 projetofinal.c -o projetofinal.exe -pthread -lgmp 
