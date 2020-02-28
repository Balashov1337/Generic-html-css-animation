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
    int pixblock;
    int x=0;
    int y=0;
    int count=1;
    int time;
    printf("Enter the number of blocks along the axis OX \n");
    scanf_s("%i", &maxxi);
    printf("Enter the number of blocks along the axis OY \n");
    scanf_s("%i", &maxyi);
    maxblock = maxxi * maxyi;
    printf("Blocks will be generated = %d \n",maxblock);
    printf("Enter the number of pixels for one block \n");
    scanf_s("%i", &pixblock);
    ofstream fout;
    fout.open("generic_css.txt");
    for (yi = 0; yi < maxyi; yi++) {
        for (xi = 0; xi < maxxi; xi++) {
            fout << ".loader-block:nth-child("<<count<<") {\n -moz-transform: translate("<<x<<"px"<<","<<y<<"px"<<");\n ";
            fout << "-ms-transform: translate(" << x << "px" << "," << y << "px" << "); \n";
            fout << "-webkit-transform: translate(" << x << "px" << "," << y << "px" << "); \n";
            fout << "transform: translate(" << x << "px" << "," << y << "px" << "); \n";
            time = rand()%1000;  
            fout << "-webkit-animation-delay: 0." << time << "s;\n";
            fout << "animation-delay: 0." << time << "s;\n}\n\n";
            x = x + pixblock;
            count++;
        }
        x = 0;
        y = y + pixblock;
    }
    count--;
    printf("Count block css =%d\n file:generic_css \n",count);
    fout.close();
    count++;
    fout.open("generic_html.txt");

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
        
     printf("Count block html =%d\n file:generic_html", xi);
     fout.close();

    return 0;
}
