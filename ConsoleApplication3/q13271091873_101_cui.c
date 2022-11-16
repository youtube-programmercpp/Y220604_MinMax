﻿// C言語で平均値・最大値・最小値を求めるサンプル (CUI版) Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int 入力値;
	if (scanf("%d", &入力値) == 1) {
		//1個のデータを読み込むことができた
		if (入力値 > 0) {
			//正の値が入力された
			int 個数   = 1     ;//平均値を求めるにはデータの個数が必要
			int 合計値 = 入力値;//平均値を求めるには合計値が必要
			int 最大値 = 入力値;
			int 最小値 = 入力値;
			for (;;) {
				if (scanf("%d", &入力値) == 1) {
					if (入力値 > 0) {
						//正の値が入力された
						++個数;//個数をカウントする
						合計値 += 入力値;//合計値に入力値を足しこむ
						if (最大値 < 入力値) 最大値 = 入力値;//最大値を更新する
						if (最小値 > 入力値) 最小値 = 入力値;//最小値を更新する
					}
					else {
						//0または負の値が入力された
						break;//(負の整数または0が入力されると終了
					}
				}
				else {
					//データを読み込むことができなかった
					break;//入力エラー
				}
			}
			//処理結果を表示する
			printf("平均値: %f\n", (double)合計値 / 個数);
			printf("最大値: %d\n", 最大値);
			printf("最小値: %d\n", 最小値);
		}
		else {
			//0または負の値が入力された
			printf("正の整数値が一つも入力されていないため、平均値、最大値、最小値は求められません。\n");//仕様規定外
		}
	}
	else {
		//データを読み込むことができなかった
		printf("整数値であると看做されないデータが入力されました。\n");//入力エラー
	}
	return 0;
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q13271091873
1051449865さん

2022/11/16 10:55

2回答

キーボードから任意の個数の正整数を読み込み、それらの平均値、最大値、最小値を表示するプログラムがわからないです。(負の整数または0が入力されると終了)
よろしくお願いします。

C言語関連・10閲覧
*/