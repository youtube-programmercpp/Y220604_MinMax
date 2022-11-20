// C言語(C99)配列・平均値・最大値・最小値サンプル Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>
#include <stdlib.h>

/*【このサンプルのテーマ】
* size_t 型を使う
* 【説明】
* データは int 型だが、配列の添え字（インデックス）は size_t 型にして区別する。
* size_t 型の値を printf で出力する際は "%d" ではなく "%zu" とする。
*/
//読み込み関数：読み込み成功の場合は 1、失敗の場合は 0 を返す
static int input(int a[], size_t i)
{
	printf("Input Data No.%2zu : ", i + 1);
	return scanf_s("%d", &a[i]) == 1;
}
//表示関数
void output(const int a[], size_t i)
{
	printf("[No.%2zu] %d\n", i + 1, a[i]);
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
			if (n == 10/* 10 のところは sizeof a / sizeof *a または _countof(a) 等と書ける*/)
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
		printf("Data List:\n");
		output(a, 0);
		for (size_t i = 1; i < n; ++i)
			output(a, i);
		//平均値，最大値，最小値
		printf("\n");
		printf("average value : %.2f\n", s / n);
		printf("maximum value : %d (no.%zu)\n", a[max_i], max_i + 1);
		printf("minimum value : %d (no.%zu)\n", a[min_i], min_i + 1);
		return EXIT_SUCCESS;//正常終了
	}
	else
		return EXIT_FAILURE;//読み込みエラー
}
