// C����(C99)�z��E���ϒl�E�ő�l�E�ŏ��l�T���v�� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>  //printf�Ascanf �p�Ƃ���
#include <stdlib.h> //EXIT_SUCCESS, EXIT_FAILURE �p�Ƃ���

/*�y���̃T���v���̃e�[�}�z
* ���̓G���[�΍�
* C99�����iscanf�̑���� scanf_s ���g�p�c�������A���̃v���O�����̓��e�Ƃ��Ă� scanf ���g���Ă������j
* �֐���p�ӂ���
* �擪�̗v�f�����͓���
* �y�����z
* ���̓f�[�^���󂯕t���邽�߂̊֐��Ƃ��� input�A
* �o�̓f�[�^��\�����邽�߂̊֐��Ƃ��� output ��p�ӂ����B
* �擪�̗v�f�̓ǂݍ��݂����s�����ꍇ�A���ϒl�A�ő�l�A�ŏ��l�����߂邱�Ƃ͂ł��Ȃ����߈ُ�I���B
*/

//�ǂݍ��݊֐��F�ǂݍ��ݐ����̏ꍇ�� 1�A���s�̏ꍇ�� 0 ��Ԃ�
static int input(int a[], int i)
{
	printf("Input Data No.%2d : ", i + 1);
	return scanf_s("%d", &a[i]) == 1;
}
//�\���֐�
static void output(const int a[], int i)
{
	printf("[No.%2d] %d\n", i + 1, a[i]);
}
int main()
{
	int a[10];
	//a[0] �̓��̓f�[�^��ǂݍ���
	if (input(a, 0)) {
		double s = a[0];//���v�l
		int max_i  = 0; //�ő�l�̃C���f�b�N�X
		int min_i  = 0; //�ŏ��l�̃C���f�b�N�X
		int n = 1;
		//a[1]�`a[9] �̓��̓f�[�^��ǂݍ���
		for (;;) {
			if (n == 10/* 10 �̂Ƃ���� sizeof a / sizeof *a �܂��� _countof(a) ���Ə�����*/)
				break;//���ׂēǂݍ��݊����in �� 10 �ƂȂ�A�ǂݍ��ݍς݂̃f�[�^��������킷�j
			else {
				if (input(a, n)) {
					s += a[n];
					if (a[max_i] < a[n]) max_i = n;
					if (a[min_i] > a[n]) min_i = n;
					++n;
				}
				else
					break;//�G���[�̂��ߓǂݍ��ݏI���in �� 10 �����̒l�ƂȂ�A�ǂݍ��ݍς݂̃f�[�^����\���j
			}
		}
		//�ǂݍ��񂾐����l�̈ꗗ
		printf("Data List:\n");
		output(a, 0);
		for (int i = 1; i < n; ++i)
			output(a, i);
		//���ϒl�C�ő�l�C�ŏ��l
		printf("\n");
		printf("average value : %.2f\n", s / n);
		printf("maximum value : %d (no.%d)\n", a[max_i], max_i + 1);
		printf("minimum value : %d (no.%d)\n", a[min_i], min_i + 1);
		return EXIT_SUCCESS;//����I��
	}
	else
		return EXIT_FAILURE;//�ǂݍ��݃G���[
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q10271260785
�W�ꂳ��

2022/11/19 22:04

2��

10�̐����l�𐮐��^�z��ɓǂݍ���ŁC�����̐����l�̈ꗗ�C����сC���ϒl�C�ő�l�C�ŏ��l�����߂�v���O�������쐬����Ƃ�����肪�悭�킩�������B���ɍŏ��A�ő�l�����߂�Ƃ��낪�킩��܂���B
���s����
./a.out
Input Data No. 1 : 10
Input Data No. 2 : 30
Input Data No. 3 : 45
Input Data No. 4 : 70
Input Data No. 5 : -5
Input Data No. 6 : 0
Input Data No. 7 : 28
Input Data No. 8 : 33
Input Data No. 9 : 90
Input Data No.10 : -25

Data List:
[No. 1] 10
[No. 2] 30
[No. 3] 45
[No. 4] 70
[No. 5] -5
[No. 6] 0
[No. 7] 28
[No. 8] 33
[No. 9] 90
[No.10] -25

average value : 27.60
maximum value : 90 (no.9)
minimum value : -25 (no.10)

C����֘A�E30�{���E25
*/
