#pragma once
/*
모폴로지

*/

double* Masking(double* Input_Image, double* Mask, int Width, int Height);

//팽창
double* dilation(double* Input_Image, double* Mask, int Width, int Height);

//침식
double* Erosion(double* Input_Image, double* Mask, int Width, int Height);