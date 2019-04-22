#include "Main_Logic.h"

void Main_Loop()
{
	int Menu = 999;

	while (Menu != 0)
	{
		printf_s("Jimin TECH \n\n");
		printf_s("Affine Transform (1)\n");
		printf_s("Exit (0) \n");

		scanf_s("%d", &Menu);

		switch (Menu)
		{
			//���ɺ�ȯ
		case 1:
			Transform_Logic();
			break;


			//����
		case 0:
			Menu = 0;
			break;

		default:
			break;
		}
	}
	
}

//Affine ��ȯ�ϱ�
void Transform_Logic()
{
	printf_s("Jimin TECH Affine Transform \n\n");

	//���ɺ�ȯ
	//Vector3 Affine(Vector3 Source, Vector3 Move, Vector3 Fixed_Rotation, double Degree, double Scale_Rate);

	Vector3 Source; //����
	Vector3 Move; //�̵�����
	Vector3 Fixed_Rotation; //������ ȸ������

	double Degree = 0; //ȸ����
	double Scale_Rate = 1; //ũ��

	Source.x = 0;
	Source.y = 0;
	Source.z = 0;

	Move.x = 0;
	Move.y = 0;
	Move.z = 0;

	Fixed_Rotation.x = 0;
	Fixed_Rotation.y = 0;
	Fixed_Rotation.z = 0;


	printf_s("Source \n");
	printf_s("X > "); scanf_s("%lf", &Source.x);
	printf_s("Y > "); scanf_s("%lf", &Source.y);
	printf_s("Z > "); scanf_s("%lf", &Source.z);
	printf_s("\n\n");

	printf_s("Move \n");
	printf_s("X > "); scanf_s("%lf", &Move.x);
	printf_s("Y > "); scanf_s("%lf", &Move.y);
	printf_s("Z > "); scanf_s("%lf", &Move.z);
	printf_s("\n\n");

	printf_s("Fixed_Rotation \n");
	printf_s("X > "); scanf_s("%lf", &Fixed_Rotation.x);
	printf_s("Y > "); scanf_s("%lf", &Fixed_Rotation.y);
	printf_s("Z > "); scanf_s("%lf", &Fixed_Rotation.z);
	printf_s("\n\n");

	printf_s("Degree >"); scanf_s("%lf", &Degree);
	printf_s("Scale_Rate >"); scanf_s("%lf", &Scale_Rate);

	printf_s("���� > "); Print_Vector3(Source);
	printf_s("�̵� > "); Print_Vector3(Move);
	printf_s("������ > "); Print_Vector3(Fixed_Rotation);
	printf_s("ȸ���� > %lf \nũ�� > %lf", Degree, Scale_Rate);
	printf_s("\n\n");

	Vector3 Result = Affine(Source, Move, Fixed_Rotation, Degree, Scale_Rate);

	printf_s("Computer Vision Affine = X (%lf), Y (%lf), Z(%lf) \n\n", Result.x, Result.y, Result.z);
}

void Print_Vector3(Vector3 Source)
{
	printf_s("%lf, %lf, %lf \n\n", Source.x, Source.y, Source.z);
}

