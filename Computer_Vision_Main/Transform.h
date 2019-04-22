#pragma once
#include <math.h>

//����3 �����ڷ���
#include "Vector3.h"

#define PI 3.14159265358979323846
#define RADIAN (PI / 180)

//����
Vector3 Affine(Vector3 Source, Vector3 Move, Vector3 Fixed_Rotation, double Degree, double Scale_Rate);

//����
Vector3 Diffrence(Vector3 Source, Vector3 Target);

//�̵��ϱ�
Vector3 Translate(Vector3 Source, Vector3 Move);

//2���� ȸ���ϱ�
Vector3 Rotate(Vector3 Source, double degree);

//ũ�� ��ȯ
Vector3 Scale(Vector3 Source, double Rate);