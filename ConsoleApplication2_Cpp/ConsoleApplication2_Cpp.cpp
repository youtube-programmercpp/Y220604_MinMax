#include <iostream>
int main()
{
	int 入力値;
	if (std::cin >> 入力値) {
		//入力成功
		int 入力済みのデータ個数 = 1;
		int 最大値 = 入力値;
		int 最小値 = 入力値;

		//繰り返し
		for (;;) {
			if (入力済みのデータ個数 == 10)
				break;
			else {
				if (std::cin >> 入力値) {
					//入力成功
					++入力済みのデータ個数; //変数の値を 1 増やす

					if (最大値 < 入力値)
						最大値 = 入力値;//最大値を更新する
					else if (最小値 > 入力値)
						最小値 = 入力値;//最小値を更新する
				}
				else
					break;
			}
		}
		std::cout << "最大値: " << 最大値 << '\n';
		std::cout << "最小値: " << 最小値 << '\n';
		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}
