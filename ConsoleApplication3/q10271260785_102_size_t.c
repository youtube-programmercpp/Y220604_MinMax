// C����(C99)�z��E���ϒl�E�ő�l�E�ŏ��l�T���v�� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>
#include <stdlib.h>

/*�y���̃T���v���̃e�[�}�z
* size_t �^���g��
* �y�����z
* �f�[�^�� int �^�����A�z��̓Y�����i�C���f�b�N�X�j�� size_t �^�ɂ��ċ�ʂ���B
* size_t �^�̒l�� printf �ŏo�͂���ۂ� "%d" �ł͂Ȃ� "%zu" �Ƃ���B
*/
//�ǂݍ��݊֐��F�ǂݍ��ݐ����̏ꍇ�� 1�A���s�̏ꍇ�� 0 ��Ԃ�
static int input(int a[], size_t i)
{
	printf("Input Data No.%2zu : ", i + 1);
	return scanf_s("%d", &a[i]) == 1;
}
//�\���֐�
void output(const int a[], size_t i)
{
	printf("[No.%2zu] %d\n", i + 1, a[i]);
}
int main()
{
	int a[10];
	//a[0] �̓��̓f�[�^��ǂݍ���
	if (input(a, 0)) {
		double s = a[0];//���v�l
		size_t max_i  = 0; //�ő�l�̃C���f�b�N�X
		size_t min_i  = 0; //�ŏ��l�̃C���f�b�N�X
		size_t n = 1;
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
		for (size_t i = 1; i < n; ++i)
			output(a, i);
		//���ϒl�C�ő�l�C�ŏ��l
		printf("\n");
		printf("average value : %.2f\n", s / n);
		printf("maximum value : %d (no.%zu)\n", a[max_i], max_i + 1);
		printf("minimum value : %d (no.%zu)\n", a[min_i], min_i + 1);
		return EXIT_SUCCESS;//����I��
	}
	else
		return EXIT_FAILURE;//�ǂݍ��݃G���[
}
