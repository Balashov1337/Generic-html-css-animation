#include <fstream>
#include <stdio.h>
using namespace std;
int main()
{
    printf("Hello its generator for html and css file for animation. Works up to 999 blocks\n");
    
    int xi;
    int yi;
    int maxxi;
    int maxyi;
    int maxblock;
    int pixblockx;
    int pixblocky;
    int OX;
    int OY;
    int x=0;
    int y=0;
    int count=1;
    int time;
    printf_s("Enter the number of blocks along the axis OX \n");
    scanf_s("%i", &maxxi);
    printf_s("Enter the number of blocks along the axis OY \n");
    scanf_s("%i", &maxyi);
    maxblock = maxxi * maxyi;
    printf_s("Blocks will be generated = %d \n",maxblock);
    printf_s("Enter the number of pixels for one block along the saxis OX \n");
    scanf_s("%i", &pixblockx);
    printf_s("Enter the number of pixels for one block along the axis OY \n");
    scanf_s("%i", &pixblocky);
    ofstream fout;
    fout.open("generic_css.txt");
    //Генерация background'a
    fout << "html,\n body { \n height: 100 %; \n} \n";
    fout << "body { \n background: #999 -webkit-radial-gradient(circle farthest-side, #333333, #111111); \n  background: #999 radial-gradient(circle farthest-side, #333333, #111111); \n}";
    //Генерация условий анимации
    fout << "@-webkit-keyframes show { \n from, 40 % { \n opacity : 0; \n } \n 41 %, to{ \n opacity : 1; \n } \n @keyframes \n show{ \n from, 40 % { \n opacity : 0; \n } \n  41 %, to { \n opacity : 1; \n } \n}";
    //вычесление размера картинки
    OX = maxxi * pixblockx;
    OY = maxyi * pixblockx;
    //Вывод размера картинки
    printf_s("Final picture size: %dpx x %dpx \n" ,OX, OY);
    //Размещение и размер блока с анимацией
    fout<< "\n.loader{ \n position: absolute; \n  top: 50 %; \n  left: 50 %; \n  width:"<<OX<<"px; \n  height: "<<OY<<"px; \n  margin - left: -3.66667em; \n margin - top: -3.66667em; \n   }";
    //Размещение и размер каждого отдельного блока
    fout << "\n.loader-block {\n position: absolute; \n top : 0; \n left : 0; \n   opacity : 0; \n width:"<<pixblockx<<"px;\nheight:"<<pixblocky<<"px;\n    -webkit - animation: show 0.88s step - end infinite alternate, pulse 0.88s linear infinite alternate; \nanimation: show 0.88s step - end infinite alternate, pulse 0.88s linear infinite alternate; \n \n}";
    //Расчет положения каждого блока и генерация времени для анимации
    for (yi = 0; yi < maxyi; yi++) {
        for (xi = 0; xi < maxxi; xi++) {
            fout << "\n.loader-block:nth-child("<<count<<") {\n -moz-transform: translate("<<x<<"px"<<","<<y<<"px"<<");\n ";
            fout << "-ms-transform: translate(" << x << "px" << "," << y << "px" << "); \n";
            fout << "-webkit-transform: translate(" << x << "px" << "," << y << "px" << "); \n";
            fout << "transform: translate(" << x << "px" << "," << y << "px" << "); \n";
            time = rand()%1000;  
            fout << "-webkit-animation-delay: 0." << time << "s;\n";
            fout << "animation-delay: 0." << time << "s;\n}\n\n";
            x = x + pixblockx;
            count++;
        }
        x = 0;
        y = y + pixblocky;
    }
    count--;
    printf_s("Count block css =%d\n file:generic_css \n",count);
    fout.close();
    count++;
    fout.open("generic_html.txt");
    //Создание файла HTML
    fout << "!!!Replace all $ with double quotes!!!";
    fout << "<!DOCTYPE html> \n  < html > \n  <head> \n <meta charset = $utf-8$>\n<title>Test< / title>\n<link href = $way to generic_css$ rel = $stylesheet$>\n< / head>\n <body > \n< div class = $loader$> \n \n ";
    //Генерация блоков для html  файла
        xi = 1;
        while (xi < count) {
            if (xi < 10) {
                fout << "<span class=$loader-block$><img src=$img/image_part_00" << xi << ".png$></span>\n";
            }
            if (xi >= 10 && xi<100 ) {
                fout << "<span class=$loader-block$><img src=$img/image_part_0" << xi << ".png$></span>\n";
            }
            if (xi >= 100) {
                fout << "<span class=$loader-block$><img src=$img/image_part_" << xi << ".png$></span>\n";
            }
            xi++;
        }
        fout << " \n</body>\n< / html > ";
        xi--;
     printf_s("Count block html =%d\n file:generic_html", xi);
     fout.close();

    return 0;
}