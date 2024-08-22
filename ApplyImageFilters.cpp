
// Last Modification Date: 19/10/2023

//Shahd Muhammad 20221085
// E-mail: shahdmuhammad264@gmail.com

// Sama Ashraf 20220436
// E-mail: semsemsama2004@gmail.com

// Shouq Mohammed 20220166
//E-mail: shokzain@gmail.com

//T.A:


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
void loadImage ();
void saveImage ();
void BWImg ();
void Neg();
void Merge();
void Flip();
void FlipH();
void FlipV();
void Rotate90();
void Rotate();
void Darken();
void Lighten();
void Dark_Light();
void Edge_Detect();
void Enlarge();
void Shrink();
void Mirror();
void Shuffle();
void Blur();
void Crop();
void Skew_h();
void Skew_v();

int main()
{
    loadImage();
while(true)
{

  cout << "Choose a filter to apply: "<< endl;
  cout << "1-Black & White Filter \n"
          "2-Invert Filter\n"
         "3-Merge Filter\n"
         "4-Flip Image\n"
         "5-Darken and Lighten Image\n"
         "6-Rotate Image\n"
         "7-Detect Image Edges\n"
         "8-Enlarge Image\n"
         "9-Shrink Image\n"
         "a-Mirror Image\n"
         "b-Shuffle Image\n"
         "c-Blur Image\n"
         "d-Crop\n"
         "e-Skew Horizontally\n"
         "f-Skew Vertically\n"
         "s-Save Image\n"
         "0-Exit\n";

  char n;
  cin>> n;

      if (n == '1')
          BWImg();
      else if (n == '2')
          Neg();
      else if (n == '3')
          Merge();
      else if (n == '4')
          Flip();
      else if (n == '5')
          Dark_Light();
      else if (n == '6')
          Rotate();
      else if(n=='7')
          Edge_Detect();
      else if(n=='8')
          Enlarge();
      else if(n=='9')
          Shrink();
      else if(n=='a')
          Mirror();
      else if(n=='b')
          Shuffle();
      else if(n=='c')
          Blur();
      else if(n=='d')
          Crop();
      else if(n=='e')
          Skew_h();
      else if(n=='f')
          Skew_v();
      else if(n=='s')
          saveImage();
      else if(n=='0')
          return 0;

}

  return 0;
}
//----------------------------
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}
//----------------------------
void loadImage2 () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the image to merge with: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image2);
}
//-----------------------------
void saveImage () {
   char imageFileName[100];

   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
   cout << "DONE!\n";
}
//------------------------------
void BWImg() {

  // compare each pixel to the average ( lower-> black(0) / higher -> white(255) )
   for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k = 0; k < 3; k++) {
            if ((image[i][j][0]+image[i][j][1]+image[i][j][2])/3 > 127 ) {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }

            else
                image[i][j][0]=image[i][j][1]=image[i][j][2] = 0;
        }
    }
  }

}
//------------------------------
void Neg() {
    // Calculates the complement of each pixel to get the invert picture
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {

                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }

}
//---------------------------------
void Merge() {
    // Gets the image to merge with (image2)
   loadImage2();
   // Each pixel equals the average of it and the pixel of the same index in the required image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                int x;
                x = image[i][j][k] + image2[i][j][k];
                image[i][j][k] = x / 2;
            }
        }
    }

}
//-------------------------------
void Flip() {
    cout << "Choose:"<< endl;
    cout << "H - Horizontal Flip"<< endl;
    cout << "V - Vertical Flip"<< endl;
    char fl;
    cin>> fl;
    if(fl=='V')
     FlipV();
    else if(fl=='H')
    FlipH();

}
//---------------------
void FlipH()
{
    // horizontal flip
    // image2 copies image1 in flipped order of indices
    // horizontal flip --> affects on j-index
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            for (int k = 0; k < 3; k++) {
                image2[i][SIZE - j - 1][k] = image[i][j][k];
            }
        }
    }
    // image copies image2
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image2[i][j][k];
            }
        }
    }
}
//----------------------------------



void FlipV()
{
//    // vertical flip
//    // image2 copies image1 in flipped order of indices
//    // vertical flip --> affects on i-index

    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            for (int k = 0; k < 3; k++) {
                image2[SIZE - i - 1][j][k] = image[i][j][k];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image2[i][j][k];
            }
        }
    }

}

//----------------------------------
void Rotate90()
{
    // rotates 90 degree clockwise
    // rows being reversed (size-i-1) then changed to columns image2[j][...]
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image2[j][SIZE - 1 - i][k] = image[i][j][k];
            }
        }
    }
    // image2 copied to image to save it
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image2[i][j][k];
            }
        }
    }
}
//-----------------
void Rotate()
{
    cout << "Choose rotation Degree(90/180/270): ";
    int deg;
    cin>> deg;
    if(deg==90)
        Rotate90();
    else if(deg==180)
    {
        // combination between vertical and horizontal flip
     FlipH();
     FlipV();
    }
    else if(deg==270)
    {
        // combination between: 90-degree rotation, vertical, and horizontal flip
        Rotate90();
        FlipH();
        FlipV();
    }

}
//-----------------------
void Darken()
{
    // decrease each pixel by half of its value to get closer to 0 (black)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] -= (image[i][j][k] / 2);
            }
        }
    }

}
void Lighten()
{
    // increases each pixel by half the way between it and white (255)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] += ((255 - image[i][j][k]) / 2);
            }
        }
    }
}
void Dark_Light(){
    cout << "D - Darken"<< endl;
    cout << "L - Lighten"<< endl;
    char effect;
    cin >> effect;
    if (effect == 'D')
        Darken();
    else if(effect=='L')
        Lighten();

}
//-----------------------------
int Avg(int i, int j)
{
    int avg=0;
    for(int k=0; k<3; k++) {
        avg+=image[i][j][k];
    }
    return avg/3;
}
void Edge_Detect()
{

    //if a pixel's average of colors is less than the average of an adjacent pixel by 20 or more then it is an edge
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (Avg(i+1,j) - Avg(i,j) > 20 and i != SIZE - 1) {
                image2[i][j][0]=image2[i][j][1]=image2[i][j][2] = 0;
            } else if (Avg(i,j+1) - Avg(i,j) > 20 and  j != SIZE - 1) {
                image2[i][j][0]=image2[i][j][1]=image2[i][j][2] = 0;

            } else if (Avg(i-1,j) - Avg(i,j) > 20 and  i!=0) {
                image2[i][j][0] = image2[i][j][1] = image2[i][j][2] = 0;
            }
            else if (Avg(i,j-1) - Avg(i,j) > 20 and  j != 0) {
                image2[i][j][0] = image2[i][j][1] = image2[i][j][2] = 0;
            }
            else {
                image2[i][j][0]=image2[i][j][1]=image2[i][j][2] = 255;
            }

        }
    }
    //copies image2 to image to save it
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k=0; k<3; k++) {
                image[i][j][k] = image2[i][j][k];
            }
        }
    }


}
//-------------------------------------
void Enlarge()
{
    //choose the quarter to zoom on
    cout<< "Choose The Part (1-2-3-4)\n";
    int n;
    cin>>n;
    // each pixel in the required quarter in original image will occupy 2 pixels in image2 after enlargement

    if(n==1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image2[i][j][k] = image[i / 2][j / 2][k]; //first quarter
                }
            }
        }
    }
    else if(n==2)
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image2[i][j][k] = image[i / 2][(j / 2) + 127][k]; //second quarter
                }
            }
        }
    }
    else if(n==3)
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image2[i][j][k] = image[(i / 2) + 127][j / 2][k]; //third quarter
                }
            }
        }
    }
    else if(n==4)
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image2[i][j][k] = image[(i / 2) + 127][(j / 2) + 127][k]; //fourth quarter
                }
            }
        }
    }
    // copies image2 to the original image to save it
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image2[i][j][k];
            }
        }
    }

}
//--------------------------
void Shrink(){
    // turns image2 into white
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {

                image2[i][j][k] = 255;
            }
        }
    }
    //user chooses size after shrink
    cout<< "Choose Shrink Size (2-3-4)\n";
    cout<< "2- 1/2\n3- 1/3\n4- 1/4\n";
    int siz;
    cin>> siz;
    if(siz==2) {
    //takes a column and loses a column
    // takes a row and loses a row
    // (takes elements in even columns and rows only)

        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    image2[i][j][k] = image[i * 2][j * 2][k];
                }
            }
        }
    }
    else if(siz==3)
    {
        // shrink to 3rd
        //takes elements in rows and columns divisible by 3
        for (int i = 0; i < SIZE / 3; i++) {
            for (int j = 0; j < SIZE / 3; j++) {
                for (int k = 0; k < 3; k++) {
                image2[i][j][k] = image[i * 3][j * 3][k];
            }
            }
        }

    }
    else if(siz==4)
    {
        //shrink to 4th
        // takes elements in rows and columns divisible by 4
        for (int i = 0; i < SIZE / 4; i++) {
            for (int j = 0; j < SIZE / 4; j++) {
                for (int k = 0; k < 3; k++) {
                    image2[i][j][k] = image[i * 4][j * 4][k];
                }
            }
        }
    }
    // copies image2 to the original image to save
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image2[i][j][k];
            }
        }
    }

}
//--------------------------
void Mirror(){
    cout<<"Choose The Effect (1-2-3-4):\n"
          "1-Left 1/2\n2-Right 1/2\n3-Upper 1/2\n4-Lower 1/2\n";
          int eff;
    cin>> eff;
    if(eff==1) { //left
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image[i][j][k] = image[i][SIZE - 1 - j][k]; //right half copies the left half (j-index)
                }
            }
        }
    }
    else if(eff==2) //right
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j <= SIZE/2; j++) {
                for (int k = 0; k < 3; k++) {
                    image[i][j][k] = image[i][SIZE - 1 - j][k]; //left half copies the right half (j-index)
                }
            }
        }
    }
    else if(eff==3) //upper
    {
        for (int i = SIZE/2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image[i][j][k] = image[SIZE - 1 - i][j][k]; // lower half copies the upper half (i-index)
                }
            }
        }
    }
    else if(eff==4) //lower
    {
        for (int i = 0; i <= SIZE/2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image[i][j][k] = image[SIZE - 1 - i][j][k]; //upper half copies the lower half (i-index)
                }
            }
        }
    }

}
//-----------------------------
void Shuffle()
{
    int a,b,c,d;
    cout<<"Choose the order: ";
    cin>>a>>b>>c>>d;

 //++++++++++++++ 1st quarter ++++++++++

             // moving to lower quarter --> i+127
             // moving to upper quarter --> i-127
             // moving to quarter on the right --> j+127
             // moving to quarter on the left --> j-127

        for(int i=0; i<SIZE/2; i++)
        {
            for(int j=0; j<SIZE/2; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a == 1)
                        image2[i][j][k] = image[i][j][k]; //copying quarter 1 to quarter 1
                    else if (a == 2)
                        image2[i][j][k] = image[i][j + 127][k]; //copying quarter 2 to quarter 1
                    else if (a == 3)
                        image2[i][j][k] = image[i + 127][j][k];//copying quarter 3 to quarter 1
                    else if (a == 4)
                        image2[i][j][k] = image[i + 127][j + 127][k]; //copying quarter 4 to quarter 1

                }
            }
        }


//++++++++++ 2nd quarter ++++++++++++

        for(int i=0; i<SIZE/2; i++)
        {
            for(int j=127; j<SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    if (b == 1)
                        image2[i][j][k] = image[i][j - 127][k];//copying quarter 1 to quarter 2
                    else if (b == 2)
                        image2[i][j][k] = image[i][j][k]; //copying quarter 2 to quarter 2
                    else if (b == 3)
                        image2[i][j][k] = image[i + 127][j - 127][k]; //copying quarter 3 to quarter 2
                    else if (b == 4)
                        image2[i][j][k] = image[i + 127][j][k]; //copying quarter 4 to quarter 2


                }
            }
        }

//+++++++++ 3rd quarter +++++++++++++


        for(int i=127; i<SIZE; i++)
        {
            for(int j=0; j<SIZE/2; j++) {
                for (int k = 0; k < 3; k++) {
                    if (c == 1)
                        image2[i][j][k] = image[i - 127][j][k]; //copying quarter 1 to quarter 3
                    else if (c == 2)
                        image2[i][j][k] = image[i - 127][j + 127][k]; //copying quarter 2 to quarter 3
                    else if (c == 3)
                        image2[i][j][k] = image[i][j][k]; //copying quarter 3 to quarter 3
                    else if (c == 4)
                        image2[i][j][k] = image[i][j + 127][k]; //copying quarter 4 to quarter 3
                }
            }
        }


    //++++++++ 4th quarter ++++++++++
        for(int i=127; i<SIZE; i++)
        {
            for(int j=127; j<SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    if (d == 1)
                        image2[i][j][k] = image[i - 127][j - 127][k];//copying quarter 1 to quarter 4
                    else if (d == 2)
                        image2[i][j][k] = image[i - 127][j][k];//copying quarter 2 to quarter 4
                    else if (d == 3)
                        image2[i][j][k] = image[i][j - 127][k]; //copying quarter 3 to quarter 4
                    else if (d == 4)
                        image2[i][j][k] = image[i][j][k]; //copying quarter 4 to quarter 4
                }
            }
        }
   // copy image2 to image to save it
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image2[i][j][k];
            }
        }
    }

}
//---------------------------
void Blur() {
    // each pixel equals the average of it and the adjacent pixels
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                // pixel in the corner
                if (i == 0 and j == 0) {
                    image2[i][j][k] = (image[i][j][k] + image[i][j + 1][k] + image[i + 1][j][k] + image[i + 1][j + 1][k]) / 4;
                }
                    //pixel on the edge
                else if (j == 0) {
                    image2[i][j][k] =
                            (image[i][j][k] + image[i][j + 1][k] + image[i + 1][j][k] + image[i + 1][j + 1][k] + image[i - 1][j][k] +
                             image[i - 1][j + 1][k]) / 6;
                }
                    // pixel on the edge
                else if (i == 0) {
                    image2[i][j][k] =
                            (image[i][j][k] + image[i][j + 1][k] + image[i + 1][j][k] + image[i + 1][j + 1][k] + image[i][j - 1][k] +
                             image[i + 1][j - 1][k]) / 6;
                } else {
                    image2[i][j][k] =
                            (image[i][j][k] + image[i][j + 1][k] + image[i + 1][j][k] + image[i + 1][j + 1][k] + image[i][j - 1][k] +
                             image[i + 1][j - 1][k] + image[i - 1][j][k] + image[i - 1][j - 1][k] + image[i - 1][j + 1][k]) / 9;
                }
            }
        }
    }
    // copy image2 to image to save it
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k]= image2[i][j][k];
            }
        }
    }

}
//------------------------
void Crop() {
    //whitening image 2
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            for (int k = 0; k < 3; k++) {

                image2[i][j][k] = 255;

            }
        }
    }
    //User enters the dimensions
    int x, y, l, w;
    cin >> x >> y >> l >> w;
    //image2 copies the pixel of the original image through the part starting from the start-row along the required width
    // and from the start-column along the required length
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < l + y; j++) {
            for (int k = 0; k < 3; k++) {
                image2[i][j][k] = image[i][j][k];
            }

        }
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = image2[i][j][k];

            }
        }
    }
}

//---------------------------
void Skew_h() {
    double x;
    double an;
    cout << "Please enter the angle to skew right\n";
    cin >> an;
    an=abs(90-an);
    // calculating the required base size
    an = (22 / 7) * (an / 180);
    x = 256 / (1 + (1 / tan(an)));
    double move = SIZE - x;
    double step = move / SIZE;
    int siz = SIZE * 2;
    unsigned char img[SIZE][siz][RGB];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < siz; j++) {
            for (int k = 0; k < 3; k++) {
                img[i][j][k] = 255;
            }
        }
    }
            //shrink image to fit the base of size x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k < 3; k++) {
                image2[i][j][k] = image[i][j * SIZE / int(x)][k];
            }
        }
    }
    // copy image2 to image and whitening the remaining part
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {

            image[i][j][k] = image2[i][j][k];
            if (j > x)
                image[i][j][k] = 255;
            }
        }
    }

    // skewing to the right according to the required angle
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                img[i][j + int(move)][k] = image[i][j][k];
            }
        }
        move -= step;
    }
    // copying img to the original image to save it
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j][k] = img[i][j][k];
            }
        }
    }

}
//------------------------------
void Skew_v() {
    double x;
    double an;
    cout << "Please enter the angle to skew up\n";
    cin >> an;
    an=abs(90-an);
    an = (22 / 7) * (an / 180);
    x = 256 / (1 + (1 / tan(an)));
    double move = SIZE - x;
    double step = move / SIZE;
    int siz = SIZE * 2;
    unsigned char img[siz][SIZE][RGB];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < siz; j++) {
            for (int k = 0; k < 3; k++) {

                img[j][i][k] = 255;
            }
        }
    }
    //shrink image to fit the base of size x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k < 3; k++) {
                image2[j][i][k] = image[j * SIZE / int(x)][i][k];
            }
        }
    }
    // copy image2 to image and whitening the remaining part
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {

                image[j][i][k] = image2[j][i][k];
                if (j > x)
                    image[j][i][k] = 255;
            }
        }
    }

    // skewing upwards according to the required angle
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {

                img[j + int(move)][i][k] = image[j][i][k];
            }
        }
        move -= step;
    }
    // copying img to the original image to save it
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; k++) {

                image[j][i][k] = img[j][i][k];
            }
        }
    }

}