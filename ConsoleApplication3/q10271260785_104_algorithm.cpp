// C++�z��E���ϒl�E�ő�l�E�ŏ��l�T���v�� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <iomanip>
#include <algorithm> //std::max_element, std::min_element
#include <numeric>   //std::accumulate

/*�y���̃T���v���̃e�[�}�z
* ���͏����ƕ��ϒl�A�ő�l�A�ŏ��l�����߂鏈���𕪗�����
* std::accumulate �ō��v�l�A
* std::max_element �ōŏ��l�A
* std::min_element �ōő�l�𓾂�
* �y�����z
* std::accumulate�Astd::max_element�Astd::min_element �ɑ΂����P�A��Q������ a, a + n �Ə�����B
* a �� &a[0] �̈Ӗ��ł���Aa + n �� &a[n] �̈Ӗ��ł���B
* &a[0] �͔͈͂̊J�n�|�C���^�ł���A
* &a[n] �͔͈͂̏I���|�C���^�ł���B
* ���̏ꍇ�́i�Ƃ������� C++ �W�����C�u�����̑S�̂Ƃ��āj�I���|�C���^�͍ŏI�v�f�̎��̗v�f���w���|�C���^�ƂȂ�B
*/

//�ǂݍ��݊֐��F�ǂݍ��ݐ����̏ꍇ�� true�A���s�̏ꍇ�� false ��Ԃ�
static bool input(int a[], size_t i)
{
	std::cout << "Input Data No." << std::setw(2) << i + 1 << " : ";
	return (std::cin >> a[i]).good();
}
//�\���֐�
static void output(const int a[], size_t i)
{
	std::cout << "[No." << std::setw(2) << i + 1 << "] " << a[i] << "\n";
}
int main()
{
	int a[10];
	//a[0] �̓��̓f�[�^��ǂݍ���
	if (input(a, 0)) {
		size_t n = 1;
		//a[1]�`a[9] �̓��̓f�[�^��ǂݍ���
		for (;;) {
			if (n == 10/*10 �̂Ƃ���� std::size(a) �Ə�����*/)
				break;//���ׂēǂݍ��݊����in �� 10 �ƂȂ�A�ǂݍ��ݍς݂̃f�[�^��������킷�j
			else {
				if (input(a, n))
					++n;
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
		const double s   = std::accumulate (a, a + n, 0); //���v�l
		const auto max_p = std::max_element(a, a + n   ); //�ő�l���w���|�C���^
		const auto min_p = std::min_element(a, a + n   ); //�ŏ��l���w���|�C���^
		const auto default_precision = std::cout.precision();
		std::cout
			<< "\n"
			<< "average value : " << std::fixed << std::setprecision(2) << s / n << std::defaultfloat << std::setprecision(default_precision) << "\n"
			<< "maximum value : " << *max_p << " (no." << (max_p - a) + 1 << ")\n"
			<< "minimum value : " << *min_p << " (no." << (min_p - a) + 1 << ")\n"
			;
		return 0;//����I��
	}
	else
		return 1;//�ǂݍ��݃G���[
}
