#pragma once
#include <math.h>

//벡터3 벡터자료형
#include "Vector3.h"

#define PI 3.14159265358979323846
#define RADIAN (PI / 180)

//통합
Vector3 Affine(Vector3 Source, Vector3 Move, Vector3 Fixed_Rotation, double Degree, double Scale_Rate);

//차이
Vector3 Diffrence(Vector3 Source, Vector3 Target);

//이동하기
Vector3 Translate(Vector3 Source, Vector3 Move);

//2차원 회전하기
Vector3 Rotate(Vector3 Source, double degree);

//크기 변환
Vector3 Scale(Vector3 Source, double Rate);