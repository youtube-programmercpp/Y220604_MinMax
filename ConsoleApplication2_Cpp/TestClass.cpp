#include <iostream>

class Range {
	//メンバ変数
	int 最大値;//内部に隠し持っているデータ
	int 最小値;//内部に隠し持っているデータ
public:
	Range(int 入力値) noexcept
		: 最大値{ 入力値 }
		, 最小値{ 入力値 }
	{
	}
	void 更新(int 入力値) noexcept
	{
		if (最大値 < 入力値)
			最大値 = 入力値;//最大値を更新する
		else if (最小値 > 入力値)
			最小値 = 入力値;//最小値を更新する
	}
	void 結果出力() const //この const はメンバ変数の値を変えない
	{
		std::cout << "最大値: " << 最大値 << '\n';
		std::cout << "最小値: " << 最小値 << '\n';
	}
};

int main()
{
	int 入力値;
	if (std::cin >> 入力値) {
		//入力成功
		int 入力済みのデータ個数 = 1;
		Range 入力値の範囲(入力値);
		//繰り返し
		for (;;) {
			if (入力済みのデータ個数 == 10)
				break;
			else {
				if (std::cin >> 入力値) {
					//入力成功
					++入力済みのデータ個数; //変数の値を 1 増やす
					入力値の範囲.更新(入力値);
				}
				else
					break;
			}
		}
		//変数名 ドット 関数名();
		入力値の範囲.結果出力();
		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}
