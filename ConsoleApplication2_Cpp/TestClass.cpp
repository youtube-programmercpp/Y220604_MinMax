#include <iostream>

class Range {
	//�����o�ϐ�
	int �ő�l;//�����ɉB�������Ă���f�[�^
	int �ŏ��l;//�����ɉB�������Ă���f�[�^
public:
	Range(int ���͒l) noexcept
		: �ő�l{ ���͒l }
		, �ŏ��l{ ���͒l }
	{
	}
	void �X�V(int ���͒l) noexcept
	{
		if (�ő�l < ���͒l)
			�ő�l = ���͒l;//�ő�l���X�V����
		else if (�ŏ��l > ���͒l)
			�ŏ��l = ���͒l;//�ŏ��l���X�V����
	}
	void ���ʏo��() const //���� const �̓����o�ϐ��̒l��ς��Ȃ�
	{
		std::cout << "�ő�l: " << �ő�l << '\n';
		std::cout << "�ŏ��l: " << �ŏ��l << '\n';
	}
};

int main()
{
	int ���͒l;
	if (std::cin >> ���͒l) {
		//���͐���
		int ���͍ς݂̃f�[�^�� = 1;
		Range ���͒l�͈̔�(���͒l);
		//�J��Ԃ�
		for (;;) {
			if (���͍ς݂̃f�[�^�� == 10)
				break;
			else {
				if (std::cin >> ���͒l) {
					//���͐���
					++���͍ς݂̃f�[�^��; //�ϐ��̒l�� 1 ���₷
					���͒l�͈̔�.�X�V(���͒l);
				}
				else
					break;
			}
		}
		//�ϐ��� �h�b�g �֐���();
		���͒l�͈̔�.���ʏo��();
		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}
