// C++�z��E���ϒl�E�ő�l�E�ŏ��l�T���v�� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <iomanip>

/*�y���̃T���v���̃e�[�}�z
* q10271260785_102_size_t.c �����̂܂� C++ �ŕ\��
* �y�����z
* printf �� std::cout << �Ƃ��A
* scanf �� std::cin >> �Ƃ����B
* printf("%.2f", �� std::cout << std::fixed << std::setprecision(2) <<  �Ə�����B
*/

//�ǂݍ��݊֐��F�ǂݍ��ݐ����̏ꍇ�� true�A���s�̏ꍇ�� false ��Ԃ�
static bool input(int a[], size_t i)
{
	std::cout << "Input Data No." << std::setw(2) << i + 1 << " : ";
	return (std::cin >> a[i]).good();
}
//�\���֐�
void output(const int a[], size_t i)
{
	std::cout << "[No." << std::setw(2) << i + 1 << "] " << a[i] << "\n";
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
			if (n == 10/*10 �̂Ƃ���� std::size(a) �Ə�����*/)
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
		std::cout << "Data List:\n";
		output(a, 0);
		for (size_t i = 1; i < n; ++i)
			output(a, i);
		//���ϒl�C�ő�l�C�ŏ��l
		const auto default_precision = std::cout.precision();
		std::cout
			<< "\n"
			<< "average value : " << std::fixed << std::setprecision(2) << s / n << std::defaultfloat << std::setprecision(default_precision) << "\n"
			<< "maximum value : " << a[max_i] << " (no." << max_i + 1 << ")\n"
			<< "minimum value : " << a[min_i] << " (no." << min_i + 1 << ")\n"
			;
		return 0;//����I��
	}
	else
		return 1;//�ǂݍ��݃G���[
}
