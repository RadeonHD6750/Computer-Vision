#include "Transform.h"
#include <stdio.h>


//아핀변환 구현
Vector3 Affine(Vector3 Source, Vector3 Move, Vector3 Fixed_Rotation, double Degree, double Scale_Rate)
{
	//이동
	Vector3 Translated_Result = Translate(Source, Move);

	printf_s("X = x1 + x2 = %lf \n", Translated_Result.x);
	printf_s("Y = y1 + y2 = %lf \n", Translated_Result.y);

	//회전하기 전에 원점으로 이동하기
	Vector3 Diffenced_Result = Diffrence(Fixed_Rotation, Translated_Result);

	//회전하기
	Vector3 Rotated_Result = Rotate(Diffenced_Result, Degree);

	printf_s("X = xCos%lf - ySin%lf = %lf \n", Degree, Degree, Rotated_Result.x);
	printf_s("Y = xSin%lf + yCos%lf = %lf \n", Degree, Degree, Rotated_Result.y);

	//다시 원래 위치로
	Vector3 Backed_Result = Translate(Rotated_Result, Fixed_Rotation);

	//크기 변환까지
	Vector3 Scaled_Result = Scale(Backed_Result, Scale_Rate);

	return Scaled_Result;
}

//벡터 차
Vector3 Diffrence(Vector3 Source, Vector3 Target)
{
	Vector3 Result;

	Result.x = Target.x - Source.x;
	Result.y = Target.y - Source.y;
	Result.z = Target.z - Source.z;

	return Result;
}

//이동하기
Vector3 Translate(Vector3 Source, Vector3 Move)
{
	Vector3 Result;

	Result.x = Source.x + Move.x;
	Result.y = Source.y + Move.y;
	Result.z = Source.z + Move.z;
		
	return Result;
}


//2차원 회전
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

//크기 변환
Vector3 Scale(Vector3 Source, double Rate)
{
	Vector3 Result;

	Result.x = Source.x * Rate;
	Result.y = Source.y * Rate;
	Result.z = Source.z * Rate;

	return Result;
}
