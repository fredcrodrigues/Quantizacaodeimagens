#include<opencv2/opencv.hpp> //Biblioteca
#include<iostream>//Biblioteca padrao
#include<stdlib.h>
using namespace std;
using namespace cv; // defininido o nome dabivlioteca

int main(){


    Mat imagem, ImagemSaida;
    int col, lin, k, valoresPixel, entradaBits = 4, bits=8; //Enttrada de bits pode variar de 1 , 2 , 4 e 8


    imagem = imread("Mario.png");
    cvtColor (imagem,ImagemSaida ,COLOR_RGB2GRAY);
    
    
   pow(2, bits); //CONSIDERANDO UMA IMAGEM DE OITO BITS
   pow(2, entradaBits); 

   k= bits / entradaBits; // NIVEIS


    
       for (int lin = 0; lin < ImagemSaida.rows; lin++) {
        for (int col = 0; col < ImagemSaida.cols; col++) {
            
            valoresPixel = ImagemSaida.at<uchar>(lin, col);//Pega o pixell
            valoresPixel /= k;  // dividir pelo numeros de cores disponiveis , intervalo de cores disponiveis
            valoresPixel *= k;// bits de amarzenamento
            // Altera o valor do pixeel 
            ImagemSaida.at<uchar>(lin, col) = round(valoresPixel); // Arrendoda o valor do pixel
        }
        
    }
       imshow("Quantizada", ImagemSaida);
    
    
    waitKey(0);
    return 0;
}
