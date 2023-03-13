#include <stdio.h>

float calculamedia(float n1, float n2, float n3, float ne){
 n2  =  n2*2;
 n3 = n3*3;

float ma = (n1+n2+n3+ne)/7;

return ma;

}

int main(){

float media = calculamedia(8.5,10,7.0, 10);

if(media >= 9 )printf("\n\nMedia : %f \n A\n\n", media);
else{
 if(media < 9 && media >=7.5) printf("\n\nMedia : %f \n B\n\n", media);
else{
 if(media  < 7.5 && media >=6) printf("\n\nMedia : %f \n C\n\n", media);
else{ 
if(media <6 && media >=4) printf("\n\nMedia : %f D\n\n", media);
else printf("\n\nMedia : %f \n E\n\n", media);}}}
}
