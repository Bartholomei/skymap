#include <iostream>
#include <fstream>
#include <iomanip>cd ..

using namespace std;

int main()
{
    fstream fin;
    fin.open("20170205_163908_xst_sb157_30MHz.dat", ios_base::in | ios_base::binary);
    ofstream foutRe("re.txt");
    ofstream foutIm("im.txt");
    double real[192][192];
    double im[192][192];
    if (fin.is_open())
    {
        for (int y = 0; y < 192; y++)
        {
            for (int x = 0; x < 192; x++)
            {
                //std::cout << x << std::endl;
                fin.read((char *)&real[y][x], sizeof real[192][192]);
                fin.read((char *)&im[y][x], sizeof im[192][192]);
                foutRe << real[y][x] << " ";
                foutIm << im[y][x] << " ";
                //std::cout << real[y][x] << "i" << im[y][x] << std::endl;
            }
            foutRe << endl;
            foutIm << endl;
        }
        //std::cout << real[0][0] << " " << im[0][0] << std::endl;
    }
    fin.close();
    foutRe.close();
    foutIm.close();

    return 0;
}