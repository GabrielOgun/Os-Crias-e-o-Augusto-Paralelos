Rodamos em um Ubuntu na AWS usando a maquina EC2 z1d.large
sudo apt update
sudo apt install build-essential --> instalar GCC
sudo apt install libgmp-dev --> instalar GMP
gcc -O3 projetofinal.c -o projetofinal.exe -pthread -lgmp 
./projetofinal.exe >> arquivo.txt
Usamos >> arquivo.txt para armazenar a saida em um arquivo texto, visto que o console nao suporta 300 mil caracteres, ele limita a subida da pagina.
Comprovar Resultado: algoritmo que compara o resultado do programa  com os primeiros 2000000 de digitos encontrados pela NASA:
Link da Nasa: https://apod.nasa.gov/htmltest/gifcity/e.2mil
Link do Algoritmo: https://replit.com/join/gyfviztlze-arturvalladares --> basta colocar o numero obtido no formato string no arquivo sn.py
