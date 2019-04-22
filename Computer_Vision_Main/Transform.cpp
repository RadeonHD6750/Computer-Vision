#include "Transform.h"
#include <stdio.h>


//���ɺ�ȯ ����
Vector3 Affine(Vector3 Source, Vector3 Move, Vector3 Fixed_Rotation, double Degree, double Scale_Rate)
{
	//�̵�
	Vector3 Translated_Result = Translate(Source, Move);

	printf_s("X = x1 + x2 = %lf \n", Translated_Result.x);
	printf_s("Y = y1 + y2 = %lf \n", Translated_Result.y);

	//ȸ���ϱ� ���� �������� �̵��ϱ�
	Vector3 Diffenced_Result = Diffrence(Fixed_Rotation, Translated_Result);

	//ȸ���ϱ�
	Vector3 Rotated_Result = Rotate(Diffenced_Result, Degree);

	printf_s("X = xCos%lf - ySin%lf = %lf \n", Degree, Degree, Rotated_Result.x);
	printf_s("Y = xSin%lf + yCos%lf = %lf \n", Degree, Degree, Rotated_Result.y);

	//�ٽ� ���� ��ġ��
	Vector3 Backed_Result = Translate(Rotated_Result, Fixed_Rotation);

	//ũ�� ��ȯ����
	Vector3 Scaled_Result = Scale(Backed_Result, Scale_Rate);

	return Scaled_Result;
}

//���� ��
Vector3 Diffrence(Vector3 Source, Vector3 Target)
{
	Vector3 Result;

	Result.x = Target.x - Source.x;
	Result.y = Target.y - Source.y;
	Result.z = Target.z - Source.z;

	return Result;
}

//�̵��ϱ�
Vector3 Translate(Vector3 Source, Vector3 Move)
{
	Vector3 Result;

	Result.x = Source.x + Move.x;
	Result.y = Source.y + Move.y;
	Result.z = Source.z + Move.z;
		
	return Result;
}


//2���� ȸ��
Vector3 Rotate(Vector3 Source, double degree)
{
	Vector3 Result;
	double degree_RADIAN = degree * RADIAN;

	Result.x = (Source.x * cos(degree_RADIAN)) - (Source.y * sin(degree_RADIAN));
	Result.y =  (Source.x * sin(degree_RADIAN)) + (Source.y * cos(degree_RADIAN));
	Result.z = 1;

	printf_s("Cos%lf = %lf \n\n", degree, cos(degree_RADIAN));

	return Result;
}

//ũ�� ��ȯ
Vector3 Scale(Vector3 Source, double Rate)
{
	Vector3 Result;

	Result.x = Source.x * Rate;
	Result.y = Source.y * Rate;
	Result.z = Source.z * Rate;

	return Result;
}
