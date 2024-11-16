#include <iostream>
#include <vector>
#include <cstdlib> 
#include <random>
#include <conio.h>
#include <thread> 
#include <chrono>
#include <algorithm>
#include <functional>
int wthg = 0;
void render(std::vector<int> grid) {
	system("cls");
	int a = 0;
	for (int n = 0; n < 20; n++) {
		for (int i = 0; i < 10; i++) {
			if (grid[a] == 0) {
				std::cout << " □";
			}
			else {
				std::cout << " ■";
			}

			a++;
		}
		std::cout << std::endl;
	}

}



int main() {

	//フィールド作成 横10　縦20
	std::vector<int> grid;
	for (int i = 0; i < 200; i++) {
		grid.push_back(0);
	}
	std::vector<int> PreGrid = grid;


	int player_is_moving_block = 0;
	int y = 0;

	//各ブロックの初期座標　
	int i_block[4] = { 6,16,26,36 };
	int o_block[4] = { 5,6,15,16 };
	int s_block[4] = { 5,6,14,15 };
	int z_block[4] = { 4,5,15,16 };
	int j_block[4] = { 6,16,26,25 };
	int l_block[4] = { 5,15,25,26 };
	int t_block[4] = { 4,5,6,15 };

	//〇字型ブロックが□°の時、時計回りに回転させるために移動しなければいけない座標。左上のマスを最初とする
	int i_block_0[4] = { -9,0,9,18 };
	int i_block_90[4] = { 8,-1,-10,-19 };
	int i_block_180[4] = { -18, -9,0,9 };
	int i_block_270[4] = { 19,10,1,-8 };

	int s_block_0[4] = { 0,-9,-2,-11 };
	int s_block_90[4] = { -10,-1,-8,1 };
	int s_block_180[4] = { 11,2,9,0 };
	int s_block_270[4] = { -1,8,1,10 };

	int z_block_0[4] = { -2,-10,-1,-9 };
	int z_block_90[4] = { -8,0,-9,-1 };
	int z_block_180[4] = { 9,1,10,2 };
	int z_block_270[4] = { 1,9,0,8 };

	int j_block_0[4] = { -9,-9,-1,-1 };
	int j_block_90[4] = { 9,0,-8,1 };
	int j_block_180[4] = { 1,1,9,9 };
	int j_block_270[4] = { -1,8,0,-9 };

	int l_block_0[4] = { -2,-9,0,9 };
	int l_block_90[4] = { 1,-1,-10,-10 };
	int l_block_180[4] = { -9,0,9,2 };
	int l_block_270[4] = { 10,10,1,-1 };

	int t_block_0[4] = { 0,-1,-1,-9 };
	int t_block_90[4] = { -9,0,0,0 };
	int t_block_180[4] = { 9,1,1,0 };
	int t_block_270[4] = { 0,0,0,9 };

	std::vector<int> locations_of_moving_block;
	//次どの形状の図形を出現させるかを決めるためのランダム 図形は全部で七個あるので、0,6
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, 6);

	while (true) {
		if (player_is_moving_block == 0) {
			locations_of_moving_block.clear();
			int random = distr(gen);
			player_is_moving_block = 1;

			if (random == 0) {

				for (int p = 0; p < 4; p++) {
					locations_of_moving_block.push_back(i_block[p]);
				}
				locations_of_moving_block.push_back(0);
				locations_of_moving_block.push_back(0);

				for (int m = 0; m < 4; m++) {
					if (grid[i_block[m]] != 1) {
						grid[i_block[m]] = 1;
					}
					else {
						std::cout << "Game Over";//ゲームオーバーの処理
					}
				}
			}
			else if (random == 1) {

				for (int p = 0; p < 4; p++) {
					locations_of_moving_block.push_back(o_block[p]);
				}
				locations_of_moving_block.push_back(0);
				locations_of_moving_block.push_back(1);

				for (int m = 0; m < 4; m++) {
					if (grid[o_block[m]] != 1) {
						grid[o_block[m]] = 1;
					}
					else {
						std::cout << "Game Over";//ゲームオーバーの処理
					}
				}
			}
			else if (random == 2) {

				for (int p = 0; p < 4; p++) {
					locations_of_moving_block.push_back(s_block[p]);
				}
				locations_of_moving_block.push_back(0);
				locations_of_moving_block.push_back(2);

				for (int m = 0; m < 4; m++) {
					if (grid[s_block[m]] != 1) {
						grid[s_block[m]] = 1;
					}
					else {
						std::cout << "Game Over";//ゲームオーバーの処理
					}
				}
			}
			else if (random == 3) {

				for (int p = 0; p < 4; p++) {
					locations_of_moving_block.push_back(z_block[p]);
				}
				locations_of_moving_block.push_back(0);
				locations_of_moving_block.push_back(3);

				for (int m = 0; m < 4; m++) {
					if (grid[z_block[m]] != 1) {
						grid[z_block[m]] = 1;
					}
					else {
						std::cout << "Game Over";//ゲームオーバーの処理
					}
				}
			}
			else if (random == 4) {

				for (int p = 0; p < 4; p++) {
					locations_of_moving_block.push_back(j_block[p]);
				}
				locations_of_moving_block.push_back(0);
				locations_of_moving_block.push_back(4);

				for (int m = 0; m < 4; m++) {
					if (grid[j_block[m]] != 1) {
						grid[j_block[m]] = 1;
					}
					else {
						std::cout << "Game Over";//ゲームオーバーの処理
					}
				}
			}
			else if (random == 5) {

				for (int p = 0; p < 4; p++) {
					locations_of_moving_block.push_back(l_block[p]);
				}
				locations_of_moving_block.push_back(0);
				locations_of_moving_block.push_back(5);

				for (int m = 0; m < 4; m++) {
					if (grid[l_block[m]] != 1) {
						grid[l_block[m]] = 1;
					}
					else {
						std::cout << "Game Over";//ゲームオーバーの処理
					}
				}
			}
			else if (random == 6) {

				for (int p = 0; p < 4; p++) {
					locations_of_moving_block.push_back(t_block[p]);
				}
				locations_of_moving_block.push_back(0);
				locations_of_moving_block.push_back(6);

				for (int m = 0; m < 4; m++) {
					if (grid[t_block[m]] != 1) {
						grid[t_block[m]] = 1;
					}
					else {
						std::cout << "Game Over";//ゲームオーバーの処理
					}
				}
			}

			std::sort(locations_of_moving_block.begin(), locations_of_moving_block.begin() + 4, std::greater<int>());
			render(grid);
		}


		if (_kbhit()) {
			int key = _getch();
			int a;
			int b;
			if (key == 224) {
				key = _getch();
				int allow = 1;
				switch (key) {

				case 72://上

					switch (locations_of_moving_block[5]) {
					case 0:
						for (int i = 0; i < 4; i++) {
							PreGrid[locations_of_moving_block[i]] = 0;
							if (locations_of_moving_block[i] % 10 == 0 || (locations_of_moving_block[i] + 1) % 10 == 0) {
								allow = 0;
							}
						}
						if (allow == 1) {
							allow = 0;



							for (int i = 0; i < 4; i++) {
								switch (locations_of_moving_block[4]) {
								case 0:
									if (locations_of_moving_block[i] + i_block_0[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + i_block_0[i]] = 1;
									break;

								case 90:
									if (locations_of_moving_block[i] + i_block_90[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + i_block_90[i]] = 1;
									break;

								case 180:
									if (locations_of_moving_block[i] + i_block_180[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + i_block_180[i]] = 1;
									break;

								case 270:
									if (locations_of_moving_block[i] + i_block_270[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + i_block_270[i]] = 1;
									break;
								}
							}
							a = 0;
							b = 0;
							for (int i = 0; i < 200; i++) {
								a += grid[i];
								b += PreGrid[i];
							}

							if (a != b) {
								PreGrid = grid;
								break;
							}
							else {

								for (int i = 0; i < 4; i++) {
									switch (locations_of_moving_block[4]) {
									case 0:
										locations_of_moving_block[i] = locations_of_moving_block[i] + i_block_0[i];
										break;

									case 90:
										locations_of_moving_block[i] = locations_of_moving_block[i] + i_block_90[i];
										break;

									case 180:
										locations_of_moving_block[i] = locations_of_moving_block[i] + i_block_180[i];
										break;

									case 270:
										locations_of_moving_block[i] = locations_of_moving_block[i] + i_block_270[i];
										break;
									}

								}

								if (locations_of_moving_block[4] != 270) {
									locations_of_moving_block[4] += 90;
								}
								else {
									locations_of_moving_block[4] = 0;
								}
								grid = PreGrid;
								break;
							}
						}
						break;

					case 2:
						for (int i = 0; i < 4; i++) {
							PreGrid[locations_of_moving_block[i]] = 0;
							if (locations_of_moving_block[i] % 10 == 0 || (locations_of_moving_block[i] + 1) % 10 == 0) {
								allow = 0;
							}
						}
						if (allow == 1) {



							for (int i = 0; i < 4; i++) {
								switch (locations_of_moving_block[4]) {
								case 0:
									if (locations_of_moving_block[i] + s_block_0[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + s_block_0[i]] = 1;
									break;

								case 90:

									if (locations_of_moving_block[i] + s_block_90[i] > 200) {

										break;
									}
									PreGrid[locations_of_moving_block[i] + s_block_90[i]] = 1;
									break;

								case 180:
									if (locations_of_moving_block[i] + s_block_180[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + s_block_180[i]] = 1;
									break;

								case 270:
									if (locations_of_moving_block[i] + s_block_270[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + s_block_270[i]] = 1;
									break;
								}
							}
							a = 0;
							b = 0;
							for (int i = 0; i < 200; i++) {
								a += grid[i];
								b += PreGrid[i];
							}

							if (a != b) {
								PreGrid = grid;
								break;
							}
							else {

								for (int i = 0; i < 4; i++) {
									switch (locations_of_moving_block[4]) {
									case 0:
										locations_of_moving_block[i] = locations_of_moving_block[i] + s_block_0[i];
										break;

									case 90:
										locations_of_moving_block[i] = locations_of_moving_block[i] + s_block_90[i];
										break;

									case 180:
										locations_of_moving_block[i] = locations_of_moving_block[i] + s_block_180[i];
										break;

									case 270:
										locations_of_moving_block[i] = locations_of_moving_block[i] + s_block_270[i];
										break;
									}

								}

								if (locations_of_moving_block[4] != 270) {
									locations_of_moving_block[4] += 90;
								}
								else {
									locations_of_moving_block[4] = 0;
								}
								grid = PreGrid;
								break;
							}
						}
						break;



					case 3:

						for (int i = 0; i < 4; i++) {
							PreGrid[locations_of_moving_block[i]] = 0;
							if (locations_of_moving_block[i] % 10 == 0 || (locations_of_moving_block[i] + 1) % 10 == 0) {
								allow = 0;
							}
						}
						if (allow == 1) {


							for (int i = 0; i < 4; i++) {
								switch (locations_of_moving_block[4]) {
								case 0:
									if (locations_of_moving_block[i] + z_block_0[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + z_block_0[i]] = 1;
									break;

								case 90:
									if (locations_of_moving_block[i] + z_block_90[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + z_block_90[i]] = 1;
									break;

								case 180:
									if (locations_of_moving_block[i] + z_block_180[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + z_block_180[i]] = 1;
									break;

								case 270:
									if (locations_of_moving_block[i] + z_block_270[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + z_block_270[i]] = 1;
									break;
								}
							}
							a = 0;
							b = 0;
							for (int i = 0; i < 200; i++) {
								a += grid[i];
								b += PreGrid[i];
							}

							if (a != b) {
								PreGrid = grid;
								break;
							}
							else {

								for (int i = 0; i < 4; i++) {
									switch (locations_of_moving_block[4]) {
									case 0:
										locations_of_moving_block[i] = locations_of_moving_block[i] + z_block_0[i];
										break;

									case 90:
										locations_of_moving_block[i] = locations_of_moving_block[i] + z_block_90[i];
										break;

									case 180:
										locations_of_moving_block[i] = locations_of_moving_block[i] + z_block_180[i];
										break;

									case 270:
										locations_of_moving_block[i] = locations_of_moving_block[i] + z_block_270[i];
										break;
									}

								}

								if (locations_of_moving_block[4] != 270) {
									locations_of_moving_block[4] += 90;
								}
								else {
									locations_of_moving_block[4] = 0;
								}
								grid = PreGrid;
								break;
							}
						}
						break;

					case 4:
						for (int i = 0; i < 4; i++) {
							PreGrid[locations_of_moving_block[i]] = 0;
							if (locations_of_moving_block[i] % 10 == 0 || (locations_of_moving_block[i] + 1) % 10 == 0) {
								allow = 0;
							}
						}
						if (allow == 1) {


							for (int i = 0; i < 4; i++) {
								switch (locations_of_moving_block[4]) {
								case 0:
									if (locations_of_moving_block[i] + j_block_0[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + j_block_0[i]] = 1;
									break;

								case 90:

									if (locations_of_moving_block[i] + j_block_90[i] > 200) {

										break;
									}
									PreGrid[locations_of_moving_block[i] + j_block_90[i]] = 1;
									break;

								case 180:
									if (locations_of_moving_block[i] + j_block_180[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + j_block_180[i]] = 1;
									break;

								case 270:
									if (locations_of_moving_block[i] + j_block_270[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + j_block_270[i]] = 1;
									break;
								}
							}
							a = 0;
							b = 0;
							for (int i = 0; i < 200; i++) {
								a += grid[i];
								b += PreGrid[i];
							}

							if (a != b) {
								PreGrid = grid;
								break;
							}
							else {

								for (int i = 0; i < 4; i++) {
									switch (locations_of_moving_block[4]) {
									case 0:
										locations_of_moving_block[i] = locations_of_moving_block[i] + j_block_0[i];
										break;

									case 90:
										locations_of_moving_block[i] = locations_of_moving_block[i] + j_block_90[i];
										break;

									case 180:
										locations_of_moving_block[i] = locations_of_moving_block[i] + j_block_180[i];
										break;

									case 270:
										locations_of_moving_block[i] = locations_of_moving_block[i] + j_block_270[i];
										break;
									}

								}

								if (locations_of_moving_block[4] != 270) {
									locations_of_moving_block[4] += 90;
								}
								else {
									locations_of_moving_block[4] = 0;
								}
								grid = PreGrid;
								break;
							}
						}
						break;

					case 5:
						for (int i = 0; i < 4; i++) {
							PreGrid[locations_of_moving_block[i]] = 0;
							if (locations_of_moving_block[i] % 10 == 0 || (locations_of_moving_block[i] + 1) % 10 == 0) {
								allow = 1;
							}
						}
						if (allow == 1) {

							for (int i = 0; i < 4; i++) {
								switch (locations_of_moving_block[4]) {
								case 0:
									if (locations_of_moving_block[i] + l_block_0[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + l_block_0[i]] = 1;
									break;

								case 90:

									if (locations_of_moving_block[i] + l_block_90[i] > 200) {

										break;
									}
									PreGrid[locations_of_moving_block[i] + l_block_90[i]] = 1;
									break;

								case 180:
									if (locations_of_moving_block[i] + l_block_180[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + l_block_180[i]] = 1;
									break;

								case 270:
									if (locations_of_moving_block[i] + l_block_270[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + l_block_270[i]] = 1;
									break;
								}
							}
							a = 0;
							b = 0;
							for (int i = 0; i < 200; i++) {
								a += grid[i];
								b += PreGrid[i];
							}

							if (a != b) {
								PreGrid = grid;
								break;
							}
							else {

								for (int i = 0; i < 4; i++) {
									switch (locations_of_moving_block[4]) {
									case 0:
										locations_of_moving_block[i] = locations_of_moving_block[i] + l_block_0[i];
										break;

									case 90:
										locations_of_moving_block[i] = locations_of_moving_block[i] + l_block_90[i];
										break;

									case 180:
										locations_of_moving_block[i] = locations_of_moving_block[i] + l_block_180[i];
										break;

									case 270:
										locations_of_moving_block[i] = locations_of_moving_block[i] + l_block_270[i];
										break;
									}

								}

								if (locations_of_moving_block[4] != 270) {
									locations_of_moving_block[4] += 90;
								}
								else {
									locations_of_moving_block[4] = 0;
								}
								grid = PreGrid;
								break;
							}
						}
						break;

					case 6:
						for (int i = 0; i < 4; i++) {
							PreGrid[locations_of_moving_block[i]] = 0;
							if (locations_of_moving_block[i] % 10 == 0 || (locations_of_moving_block[i] + 1) % 10 == 0) {
								allow = 0;
							}
						}
						if (allow == 1) {

							for (int i = 0; i < 4; i++) {
								switch (locations_of_moving_block[4]) {
								case 0:
									if (locations_of_moving_block[i] + t_block_0[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + t_block_0[i]] = 1;
									break;

								case 90:

									if (locations_of_moving_block[i] + t_block_90[i] > 200) {

										break;
									}
									PreGrid[locations_of_moving_block[i] + t_block_90[i]] = 1;
									break;

								case 180:
									if (locations_of_moving_block[i] + t_block_180[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + t_block_180[i]] = 1;
									break;

								case 270:
									if (locations_of_moving_block[i] + t_block_270[i] > 200) {
										break;
									}
									PreGrid[locations_of_moving_block[i] + t_block_270[i]] = 1;
									break;
								}
							}
							a = 0;
							b = 0;
							for (int i = 0; i < 200; i++) {
								a += grid[i];
								b += PreGrid[i];
							}

							if (a != b) {
								PreGrid = grid;
								break;
							}
							else {

								for (int i = 0; i < 4; i++) {
									switch (locations_of_moving_block[4]) {
									case 0:
										locations_of_moving_block[i] = locations_of_moving_block[i] + t_block_0[i];
										break;

									case 90:
										locations_of_moving_block[i] = locations_of_moving_block[i] + t_block_90[i];
										break;

									case 180:
										locations_of_moving_block[i] = locations_of_moving_block[i] + t_block_180[i];
										break;

									case 270:
										locations_of_moving_block[i] = locations_of_moving_block[i] + t_block_270[i];
										break;
									}

								}

								if (locations_of_moving_block[4] != 270) {
									locations_of_moving_block[4] += 90;
								}
								else {
									locations_of_moving_block[4] = 0;
								}
								grid = PreGrid;
								break;
							}
						}
						break;

					}
					break;





				case 80://下
					//下にズドン
					wthg = 0;
					while (1) {


						for (int i = 0; i < 4; i++) {
							if (locations_of_moving_block[i] + 10 > 199) {
								player_is_moving_block = 0;
								wthg = 1;
							}
						}
						if (wthg != 1) {

							for (int i = 0; i < 4; i++) {
								PreGrid[locations_of_moving_block[i]] = 0;
								PreGrid[locations_of_moving_block[i] + 10] = 1;
							}
							int a = 0;
							for (int i = 0; i < 200; i++) {
								a += grid[i];
							}
							int b = 0;
							for (int i = 0; i < 200; i++) {
								b += PreGrid[i];
							}

							if (a != b) {
								player_is_moving_block = 0;
								PreGrid = grid;
								break;
							}
							else {
								for (int i = 0; i < 4; i++) {
									locations_of_moving_block[i] += 10;
								}
								grid = PreGrid;
							}
						}
						else {
							break;
						}



					}

					break;

				case 75://左
					int wth;
					wth = 0;
					for (int i = 0; i < 4; i++) {
						if (locations_of_moving_block[i] % 10 == 0) {
							wth = 1;
						}

					}
					if (wth == 1) {
						wth = 0;
						break;
					}
					for (int i = 0; i < 4; i++) {
						PreGrid[locations_of_moving_block[i]] = 0;
					}
					for (int i = 0; i < 4; i++) {
						PreGrid[locations_of_moving_block[i] - 1] = 1;
					}
					a = 0;
					b = 0;
					for (int i = 0; i < 200; i++) {
						a += grid[i];
						b += PreGrid[i];
					}
					if (a != b) {

						PreGrid = grid;
					}
					else {
						grid = PreGrid;
						for (int i = 0; i < 4; i++) {
							locations_of_moving_block[i] -= 1;
						}
					}
					break;

				case 77://右
					wth = 0;
					for (int i = 0; i < 4; i++) {
						if ((locations_of_moving_block[i] + 1) % 10 == 0) {
							wth = 1;
						}
					}
					if (wth == 1) {
						wth = 0;
						break;
					}

					for (int i = 0; i < 4; i++) {
						PreGrid[locations_of_moving_block[i]] = 0;

					}
					for (int i = 0; i < 4; i++) {
						PreGrid[locations_of_moving_block[i] + 1] = 1;
					}
					a = 0;
					b = 0;
					for (int i = 0; i < 200; i++) {
						a += grid[i];
						b += PreGrid[i];
					}
					if (a != b) {

						PreGrid = grid;
					}
					else {
						grid = PreGrid;
						for (int i = 0; i < 4; i++) {
							locations_of_moving_block[i] += 1;
						}
					}
					break;

				default: break;
				}
				render(grid);
			}
		}
		std::sort(locations_of_moving_block.begin(), locations_of_moving_block.begin() + 4, std::greater<int>());
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		y++;
		if (y == 10) {
			y = 0;
			int omg = 0;
			for (int i = 0; i < 4; i++) {
				if (locations_of_moving_block[i] + 10 > 199) {
					player_is_moving_block = 0;
					omg = 1;
				}
			}
			if (omg != 1) {



				for (int i = 0; i < 4; i++) {
					PreGrid[locations_of_moving_block[i]] = 0;
					PreGrid[locations_of_moving_block[i] + 10] = 1;
				}
				int a = 0;
				for (int i = 0; i < 200; i++) {
					a += grid[i];
				}
				int b = 0;
				for (int i = 0; i < 200; i++) {
					b += PreGrid[i];
				}

				if (a != b) {
					player_is_moving_block = 0;
					PreGrid = grid;
				}
				else {
					for (int i = 0; i < 4; i++) {
						locations_of_moving_block[i] += 10;
					}
					grid = PreGrid;
				}

			}



			render(grid);


		}
	}

}
