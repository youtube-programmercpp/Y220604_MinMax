// C++配列・平均値・最大値・最小値サンプル Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <iomanip>

/*【このサンプルのテーマ】
* q10271260785_102_size_t.c をそのまま C++ で表現
* 【説明】
* printf は std::cout << とし、
* scanf は std::cin >> とした。
* printf("%.2f", は std::cout << std::fixed << std::setprecision(2) <<  と書ける。
*/

//読み込み関数：読み込み成功の場合は true、失敗の場合は false を返す
static bool input(int a[], size_t i)
{
	std::cout << "Input Data No." << std::setw(2) << i + 1 << " : ";
	return (std::cin >> a[i]).good();
}
//表示関数
void output(const int a[], size_t i)
{
	std::cout << "[No." << std::setw(2) << i + 1 << "] " << a[i] << "\n";
}
int main()
{
	int a[10];
	//a[0] の入力データを読み込む
	if (input(a, 0)) {
		double s = a[0];//合計値
		size_t max_i  = 0; //最大値のインデックス
		size_t min_i  = 0; //最小値のインデックス
		size_t n = 1;
		//a[1]～a[9] の入力データを読み込む
		for (;;) {
			if (n == 10/*10 のところは std::size(a) と書ける*/)
				break;//すべて読み込み完了（n は 10 となり、読み込み済みのデータ個数をあらわす）
			else {
				if (input(a, n)) {
					s += a[n];
					if (a[max_i] < a[n]) max_i = n;
					if (a[min_i] > a[n]) min_i = n;
					++n;
				}
				else
					break;//エラーのため読み込み終了（n は 10 未満の値となり、読み込み済みのデータ個数を表す）
			}
		}
		//読み込んだ整数値の一覧
		std::cout << "Data List:\n";
		output(a, 0);
		for (size_t i = 1; i < n; ++i)
			output(a, i);
		//平均値，最大値，最小値
		const auto default_precision = std::cout.precision();
		std::cout
			<< "\n"
			<< "average value : " << std::fixed << std::setprecision(2) << s / n << std::defaultfloat << std::setprecision(default_precision) << "\n"
			<< "maximum value : " << a[max_i] << " (no." << max_i + 1 << ")\n"
			<< "minimum value : " << a[min_i] << " (no." << min_i + 1 << ")\n"
			;
		return 0;//正常終了
	}
	else
		return 1;//読み込みエラー
}
