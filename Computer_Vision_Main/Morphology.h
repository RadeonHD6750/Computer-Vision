#pragma once
/*
��������

*/

double* Masking(double* Input_Image, double* Mask, int Width, int Height);

//��â
double* dilation(double* Input_Image, double* Mask, int Width, int Height);

//ħ��
double* Erosion(double* Input_Image, double* Mask, int Width, int Height);