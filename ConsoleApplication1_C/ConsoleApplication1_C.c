#include <stdio.h>
#include <stdlib.h> //EXIT_FAILURE
int main()
{
	int 入力値;
	if (scanf_s("%d", &入力値) == 1/*正常に入力されたデータの個数*/) {
		//入力成功
		int 入力済みのデータ個数 = 1;
		int 最大値 = 入力値;
		int 最小値 = 入力値;

		//繰り返し
		for (;;) {
			if (入力済みのデータ個数 == 10)
				break;
			else {
				if (scanf_s("%d", &入力値) == 1) {
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
		printf("最大値: %d\n", 最大値);
		printf("最小値: %d\n", 最小値);
		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}
